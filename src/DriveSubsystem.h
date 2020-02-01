#pragma once

//#include "Robot.h"
#include "ctre/Phoenix.h"
#include <CORERobotLib.h>
#include "AHRS.h"
#include "COREFramework/COREScheduler.h"

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include "COREUtilities/CORETimer.h"

enum class DriveSide{LEFT = 1, RIGHT = 2, BOTH = 3};

class DriveSubsystem : public CORESubsystem {
public:
	DriveSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	void teleopEnd() override;

	void initTalons();

	void setMotorSpeed(double speedInFraction, DriveSide whichSide);
	void setMotorSpeed(double leftPercent, double rightPercent);
	void fillCompressor();
	void toggleGear();
	COREVector path;
private:
    COREConstant<double> m_etherAValue, m_etherBValue, m_etherQuickTurnValue, m_ticksPerInch;
    TalonSRX m_leftMaster, m_rightMaster, m_leftSlave, m_rightSlave;
    DoubleSolenoid m_leftDriveShifter, m_rightDriveShifter;
    bool m_highGear;
    Compressor compressor;
};
