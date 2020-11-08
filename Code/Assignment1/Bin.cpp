#include "Bin.h"
#include "Vector3D.h"

#include <iostream>
#include <cmath>
#include <algorithm> 

using namespace std;

// Bin constructor that gets passed an int to determine how many vector objects we want to store inside the bin
Bin::Bin(int binSize) {
	sizeOfBin = binSize;

	//Allocate new vector3D array on the heap & use our pointer to point to the first vector3D object 
	myArrayPointer = new Vector3D[sizeOfBin];
}

// Copy Constructor
Bin::Bin(const Bin &v1) {

	myArrayPointer = new Vector3D[v1.sizeOfBin];
	memcpy(myArrayPointer, v1.myArrayPointer, sizeof(Vector3D) * v1.sizeOfBin);

}

Bin::~Bin(void) {
	delete[] myArrayPointer;
	myArrayPointer = NULL;
}

int Bin::getX(int a) {
	return myArrayPointer[a].getX();
}

int Bin::getY(int a) {
	return myArrayPointer[a].getY();
}

int Bin::getZ(int a) {
	return myArrayPointer[a].getZ();
}

void Bin::add(float x, float y, float z) {
	myArrayPointer[tick] = Vector3D(x, y, z);
	tick++;
}
void Bin::remove(int b) {
	// Overwrites element b with elements to the right, this shifts everything left & gets rid of the element we dont want. Results in a copy at the end but for performance this is best to just ignore, the element we actually want is gone & the copy will be overwritten by the next element we insert
	for (int i = b; i < sizeOfBin-1; i++) {
		myArrayPointer[i] = myArrayPointer[i + 1]; // copy next element left
	}
	tick--; // rewind tick by one
}
Bin Bin::operator=(const Bin &v1) {
	// check for self-assignment
	if (&v1 == this) {
		return *this;
	}
	else {
		delete[] myArrayPointer; // freeing previously used memory

		myArrayPointer = new Vector3D[v1.sizeOfBin];
		memcpy(myArrayPointer, v1.myArrayPointer, sizeof(Vector3D) * v1.sizeOfBin);

		return *this;
	}
}

