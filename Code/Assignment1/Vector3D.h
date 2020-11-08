#ifndef VECTOR3D_H_
#define VECTOR3D_H_

class Vector3D {

private:
	float x, y, z; // Vector Components 

public:

	Vector3D();

	~Vector3D(void);

	Vector3D(float x1, float y1, float z1);

	Vector3D::Vector3D(const Vector3D &v1);

	Vector3D addVector(const Vector3D &v1);

	Vector3D subtractVector(const Vector3D &v1);

	Vector3D multiplyVector(float scalar);

	Vector3D divideVector(float scalar);

	Vector3D unitVector();

	Vector3D vectorOrthogonal(const Vector3D &v1);

	float magnitude();

	float scalarProduct(const Vector3D &v1);

	Vector3D vectorProduct(const Vector3D &v1);

	void display();

	float getX();

	float getY();

	float getZ();

	Vector3D operator=(const Vector3D &rhs);

	float operator*(const Vector3D &rhs);

	Vector3D operator%(const Vector3D &rhs);
};
#endif