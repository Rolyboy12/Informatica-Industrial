// 
// 
// 

#include "PWM_ESP32.h"


PWM::PWM()
{
}

PWM::~PWM()
{
}

void PWM::setup( uint8_t pin, float frequency, uint8_t channel, uint8_t bits_resolution)
{
	_pin = pin;
	_channel = channel;
	_frequency = frequency;
	_bits_resolution = bits_resolution;
	_resolution = pow(2, _bits_resolution);
	pinMode(_pin, OUTPUT);
	ledcSetup(_channel, _frequency, _bits_resolution);
	ledcAttachPin(_pin, _channel);
}

void PWM::setPWM(float duty_cycle)
{
	if (duty_cycle > 100)
		duty_cycle = 100;
	if (duty_cycle < 0)
		duty_cycle = 0;
	_duty_cycle = duty_cycle;
	ledcWrite(_channel, _resolution * _duty_cycle / 100);
}

void PWM::setFrequency(float frequency)
{
	_frequency = frequency;
	ledcWriteTone(_channel, _frequency);
}
