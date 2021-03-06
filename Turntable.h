/*
 * Turntable.h
 *
 *  Created on: Dec 4, 2017
 *      Author: Joseph Chang
 */

#ifndef TURNTABLE_H_
#define TURNTABLE_H_

#include <Arduino.h>
#include <StepperMotor.h>
#include "Color.h"

class Turntable {

public:
	Turntable();
	
	void begin(StepperMotor stepper);
	
	void setPosition(Color color);
	void setPosition(int angle);
	void setPosition();

private:
	StepperMotor stepperMot;
	 
};

#endif /* TURNTABLE_H_ */