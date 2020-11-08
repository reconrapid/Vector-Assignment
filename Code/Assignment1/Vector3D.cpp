#include "Vector3D.h"
#include <cmath>
#include <iostream>


using namespace std;


// Default Constructor
Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

//Constructor
Vector3D::Vector3D(float x1, float y1, float z1) {
	x = x1;
	y = y1;
	z = z1;
}
//Copy Constructor 
Vector3D::Vector3D(const Vector3D &v1) {
	x = v1.x;
	y = v1.y;
	z = v1.z;
}
// Destructor
Vector3D::~Vector3D(void) {

}

// Add two vectors together 
Vector3D Vector3D::addVector(const Vector3D &v1) {
	return Vector3D(v1.x + x, v1.y + y, v1.z + z);
}
// Subtract two vectors  
Vector3D Vector3D::subtractVector(const Vector3D &v1) {
	return Vector3D(v1.x - x, v1.y - y, v1.z - z);
}

// Multiply vector by scaler
Vector3D Vector3D::multiplyVector(float scalar) {
	return Vector3D(x*scalar, y*scalar, z*scalar);
}
// Divide vector by scaler
Vector3D Vector3D::divideVector(float scalar) {
	scalar = 1.0f / scalar;
	return Vector3D(x*scalar, y*scalar, z*scalar);
}

// CALCULATIONS
// Calculate magnitude
float Vector3D::magnitude() {
	float store;
	float result;
	store = pow(x, 2) + pow(y, 2) + pow(z, 2);
	result = sqrt(store);
	return(result);
}
// Calculate scalar/dot product
float Vector3D::scalarProduct(const Vector3D &v1) {
	return ((v1.x * x) + (v1.y * y) + (v1.z * z));
}
// Calculate cross product/vector product
Vector3D Vector3D::vectorProduct(const Vector3D &v1) {
	return Vector3D((y * v1.z - z * v1.y), (z * v1.x - x * v1.z), (x * v1.y - y * v1.x));
}
// Unit vector
Vector3D Vector3D::unitVector() {
	return Vector3D(y / magnitude(), x / magnitude(), z / magnitude());
}
// Vector orthogonal
Vector3D Vector3D::vectorOrthogonal(const Vector3D &v1) {
	// Only Orthogonal if equal to 0
	return Vector3D(vectorProduct(v1).unitVector());

}

//Display Vectors
void Vector3D::display()
{
	cout << x << ", " << y << ", " << z << endl;
}

// GET METHODS
float Vector3D::getX() {
	return x;
}

float Vector3D::getY() {
	return y;
}

float Vector3D::getZ() {
	return z;
}

// OPERATOR OVERLOADING 
// VECTOR OVERLOAD
Vector3D Vector3D::operator%(const Vector3D &rhs) {
	Vector3D temp;
	temp = this->vectorProduct(rhs);

	return temp;
}
//SCALAR OVERLOAD
float Vector3D::operator*(const Vector3D &rhs) {
	float result;
	result = this->scalarProduct(rhs);

	return result;
}
//ASSIGNMENT OPERATOR
Vector3D Vector3D::operator=(const Vector3D &rhs) {
	// check for self-assignment
	if (&rhs == this) {
		return *this;
	}
	else {
	Vector3D tmp(rhs);

		std::swap(x, tmp.x);
		std::swap(y, tmp.y);
		std::swap(z, tmp.z);

		return *this;
	}
}


