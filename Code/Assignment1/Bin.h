#ifndef BIN_H_
#define BIN_H_
#include "Vector3D.h"

class Bin {

private:
	int sizeOfBin = 0;
	Vector3D* myArrayPointer;
	int tick = 0; //use to insert objects into array 

public:

	Bin(int binSize);

	Bin(const Bin &v1);

	~Bin(void);

	int getX(int a);

	int getY(int a);

	int getZ(int a);

	void add(float x, float y, float z);

	void remove(int b);

	Bin operator=(const Bin &v1);


};
#endif