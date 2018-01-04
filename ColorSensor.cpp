#include "ColorSensor.h"

ColorSensor::ColorSensor() {
	
	this->colorSensor.begin();

}

void ColorSensor::updateData()
{
	uint16_t clear, red, green, blue;

	delay(60);  // takes 50ms to read 
	
	//Get the data from the color sensor
	colorSensor.getRawData(&red, &green, &blue, &clear);	
	
	this->redRaw = red();
	this->greenRaw = green();
	this->blueRaw = blue();
}

float ColorSensor::getRed() {
	//returns raw red value of color
	return this->redRaw;
}

float ColorSensor::getGreen() {
	//returns raw green value of color
	return this->greenRaw;
}

float ColorSensor::getBlue() {
	//returns raw blue value of color
	return this->blueRaw;
}

Color ColorSensor::getColor() {
	
	float _R = getRed();
	float _G = getGreen();
	float _B = getBlue();
	
	//Use RGB values to match color to each color 
	return color(_R,_G,_B);
}