#include <stdint.h>



#ifndef I2C_COM_H
#define I2C_COM_H

class MotorIO {

private:
	int file;
	const char* i2cDevName;
	unsigned char bufferTx[10];
	unsigned char bufferRx[10];
	uint8_t instr, cmd;

public:
	uint8_t motors_array[12];
	MotorIO();
	// Members
	/*--------------------------------*/
	void start();
	void stop();
	void ping();
	uint8_t* ping(uint8_t arr[]);
	/*--------------------------------*/
	void set_gain(int, char, float);
	float get_gain(int, char);
	/*--------------------------------*/
	void set_position(int, float);
	void set_speed(int, float);
	void set_load(int, float);
	/*--------------------------------*/
	float get_position(int);
	float get_speed(int);
	float get_load(int);
	/*--------------------------------*/
	void readEEPROM(int, uint8_t);
	void writeEEPROM(int, uint8_t, float);
	/*--------------------------------*/


};

#endif