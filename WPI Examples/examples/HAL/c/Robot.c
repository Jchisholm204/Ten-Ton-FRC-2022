// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/*
This example shows how to use the HAL directly, and what is needed to run a
basic program. The sample is compiled in C, however the functionality works from
C++ as well.

The HAL is considered a stable but changeable API. The API is stable during a
season, and is safe to use for events. However, between seasons there might be
changes to the API. This is an advanced sample, and should only be used by users
that want even more control over what code runs on their robot.
*/

#include <stdio.h>

#include <hal/HAL.h>

enum DriverStationMode {
  DisabledMode,
  TeleopMode,
  TestMode,
  AutoMode,
};

enum DriverStationMode getDSMode(void) {
  // Get Robot State
  HAL_ControlWord word;
  HAL_GetControlWord(&word);

  // We send the observes, otherwise the DS disables
  if (!word.enabled) {
    HAL_ObserveUserProgramDisabled();
    return DisabledMode;
  } else {
    if (word.autonomous) {
      HAL_ObserveUserProgramAutonomous();
      return AutoMode;
    } else if (word.test) {
      HAL_ObserveUserProgramTest();
      return TestMode;
    } else {
      HAL_ObserveUserProgramTeleop();
      return TeleopMode;
    }
  }
}

int main(void) {
  // Must initialize the HAL, 500ms timeout
  HAL_Bool initialized = HAL_Initialize(500, 0);
  if (!initialized) {
    printf("Failed to initialize the HAL\n");
    return 1;
  }

  int32_t status = 0;

  // For DS to see valid robot code
  HAL_ObserveUserProgramStarting();

  // Create a Motor Controller
  status = 0;
  HAL_DigitalHandle pwmPort =
      HAL_InitializePWMPort(HAL_GetPort(2), NULL, &status);

  if (status != 0) {
    const char* message = HAL_GetLastError(&status);
    printf("%s\n", message);
    return 1;
  }

  // Set PWM config to standard servo speeds
  HAL_SetPWMConfig(pwmPort, 2.0, 1.501, 1.5, 1.499, 1.0, &status);

  // Create an Input
  status = 0;
  HAL_DigitalHandle dio =
      HAL_InitializeDIOPort(HAL_GetPort(2), 1, NULL, &status);

  if (status != 0) {
    const char* message = HAL_GetLastError(&status);
    printf("%s\n", message);
    status = 0;
    HAL_FreePWMPort(pwmPort, &status);
    return 1;
  }

  while (1) {
    // Wait for DS data, with a timeout
    HAL_Bool validData = HAL_WaitForDSDataTimeout(1.0);
    if (!validData) {
      // Do something here on no packet
      continue;
    }
    enum DriverStationMode dsMode = getDSMode();
    switch (dsMode) {
      case DisabledMode:
        break;
      case TeleopMode:
        status = 0;
        if (HAL_GetDIO(dio, &status)) {
          HAL_SetPWMSpeed(pwmPort, 1.0, &status);
        } else {
          HAL_SetPWMSpeed(pwmPort, 0, &status);
        }
        break;
      case AutoMode:
        break;
      case TestMode:
        break;
      default:
        break;
    }
  }

  // Clean up resources
  status = 0;
  HAL_FreeDIOPort(dio);
  HAL_FreePWMPort(pwmPort, &status);
}
