#pragma once

#include "ctre/Phoenix.h"
#include <frc/AnalogInput.h>

class Index{
    public:
    
        Index();

        void set(ControlMode mode, double Mpow);

        void setTop(ControlMode mode, double Mpow);

        void setBot(ControlMode mode, double Mpow);

        void setFeed(ControlMode mode, double Mpow);

        int getCodex();

        void resetCodex();

        bool getTopSensor();

        bool getBotSensor();

        void stop();

        void stopAll();

        void runCodex(double Mpow);

    private:
        int codex;
};