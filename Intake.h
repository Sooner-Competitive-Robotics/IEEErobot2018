#ifndef INTAKE_H
#define INTAKE_H

#include <Arduino.h>
#include <RobotLib.h>
#include "Electromagnet.h"
#include "IntakeConstants.h"
#include "Turntable.h"
#include <Servo.h>

class Intake
{
	public:
		Intake();
		
		void begin(Motor motor, Encoder encoder, DigitalDevice metalDetector, DigitalDevice limitSwitch, Electromagnet electromagnet, Turntable turnTable, int colorServoPinNumber);
		
		int pickUpSequence(Color color);
		
		void pickUpSequenceA(Color color);
		
		void dropOffSequence(Color color);
		
		bool coinDetected();
		
		Motor getRackAndPinionMotor();
		
		Encoder getRackAndPinionEncoder();
		
		void raiseRackAndPinion(int newHeight);
		
		Turntable turnTable;
		
	private:
		enum PickUpState{IDLE, GRAB, SCAN, RAISE, STORE, DROP};
		enum DropOffState{IDLEd, GRABd, RAISEd, DROPd};
		
		int lastHeight;
		
		PickUpState pickUpState;
		DropOffState dropOffState;
		
		Motor intakeMotor;
		Encoder intakeEncoder;
		
		DigitalDevice metalDetector;
		DigitalDevice limitSwitch;
		Electromagnet electromagnet;
		
		Servo colorServo;
		
		
		//Most recent read from color sensor
		Color lastColor;
};

#endif