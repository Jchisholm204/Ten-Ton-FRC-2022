#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AnalogInput.h>
#include <frc/util/Color.h>
#include "ctre/Phoenix.h"

class IndexSubsystem : public frc2::SubsystemBase {
    public:

        IndexSubsystem();
        
        /**
         * Run the Top Two Indexers
         * @param iPow The Shooting Power [-1,1]
         */
        void shoot(double iPow);

        /**
         * Run the Codexing program
         */
        void runCodex();

        /**
         * Reset The Indexers Codex Variable
         */
        void resetCodex();

        /**
         * Get the Codex Variable
         * @return The Codex
         */
        int getCodex();

        /**
         * Control The Top Index Motor
         * @param mode The CTRE Control Mode
         * @param iPow
         */
        void setTop(ControlMode mode, double iPow);

        /**
         * Control The Bottom Index Motor
         * @param mode The CTRE Control Mode
         * @param iPow
         */
        void setBot(ControlMode mode, double iPow);

        /**
         * Control The Feed Index Motor
         * @param mode The CTRE Control Mode
         * @param iPow
         */
        void setFeed(ControlMode mode, double iPow);

        /**
         * Stop All Index Motors
         */
        void stop();

        /**
         * Stop The Top Two Index Motors
         */
        void stopShoot();

         /**
         * Stop The Top Index Motor
         */       
        void stopTop();

        /**
         * Stop The Bottom Index Motor
         */
        void stopBot();

        /**
         * Stop The Index Feed Motor
         */
        void stopFeed();

        /**
         * Gets if the Top Photoelectric Sensor is currently triggered
         * @return True if the sensor is currently triggered
         */
        bool getTopSensor();

        /**
         * Gets if the Top Photoelectric Sensor is currently triggered
         * @return True if the sensor is currently triggered
         */
        bool getBotSensor();

    private:
        TalonSRX topMtr;
        TalonSRX botMtr;
        TalonSRX feedMtr;

        frc::AnalogInput topPE;
        frc::AnalogInput botPE;

        int codex;
};