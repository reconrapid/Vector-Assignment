#include "Vector3D.h"
#include "Bin.h"

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main()
{
	int hold;
	float x, y, z;
	float scalar;
	float magnitude;
	x = 10;
	y = 10;
	z = 10;

	// Two Vectors
	Vector3D v1(x, y, z);
	x += 5;
	y += 10;
	z += 15;
	Vector3D v2(x, y, z);

	// Result Vector
	Vector3D v3(0, 0, 0);

	cout << "Starting vectors " << endl;
	v1.display();
	v2.display();
	v3.display();

	//TESTING GET METHODS
	cout << endl << "GET METHODS " << endl;
	cout << "Testing Get Methods on v1, result should be (10, 10, 10) " << endl;
	x = v1.getX();
	y = v1.getY();
	z = v1.getZ();

	cout << x << ", " << y << ", " << z << endl;

	cout << "Testing Get Methods on v2, result should be (15, 20, 25) " << endl;
	x = v2.getX();
	y = v2.getY();
	z = v2.getZ();

	cout << x << ", " << y << ", " << z << endl;



	// TESTING CALCULATIONS
	cout << endl << "CALCULATIONS " << endl;
	cout << "Testing calculating magnitude of v1, result should be (17.32) " << endl;
	magnitude = v1.magnitude();
	cout << magnitude << endl;

	cout << "Testing calculating scalar of two vectors, result should be (600) " << endl;
	scalar = v1.scalarProduct(v2);
	cout << scalar << endl;

	cout << "Testing calculating unit vector of v2, result should be (0.56, 0.42, 0.70) " << endl;
	v3 = v2.unitVector();
	v3.display();

	cout << "Testing Vector Product, result should be (50, -100, 50) " << endl;
	v3 = v1.vectorProduct(v2);
	v3.display();

	cout << "Testing Unit Vector Orthogonal " << endl;
	v3 = v1.vectorOrthogonal(v2);
	v3.display();



	cout << endl << "ADDITION, SUBTRACTION, MULTIPLICATION & DIVISION " << endl;
	cout << "Testing adding two vectors, result should be (25, 30, 35) " << endl;
	v3 = v1.addVector(v2);
	v3.display();

	cout << "Testing subtracting two vectors, result should be (-5, -10, -15) " << endl;
	v3 = v2.subtractVector(v1);
	v3.display();

	cout << "Testing multiplication by scalar on v2, result should be (9000, 12000, 15000) " << endl;
	v3 = v2.multiplyVector(scalar);
	v3.display();

	cout << "Setting scalar to 5 for easier division testing " << endl;
	scalar = 5;

	cout << "Testing division by scalar on v2, result should be (3, 4, 5) " << endl;
	v3 = v2.divideVector(scalar);
	v3.display();

	cout << endl << "TESTING OVERLOADS " << endl;
	Vector3D o1(x, y, z);
	x += 20;
	y += 10;
	z += 30;
	Vector3D o2(x, y, z);
	x += 55;
	y += 20;
	z += 75;
	Vector3D o3(x, y, z);

	cout << "Vector o1" << endl;
	o1.display();
	cout << "Vector o2" << endl;
	o2.display();
	cout << "Vector o3" << endl;
	o3.display();

	cout << "Testing equal overload, o3 = o1, result should be (15, 20, 25)" << endl;
	o3 = o1;
	o3.display();

	cout << "Testing vector overload, result should be (350, 50, -250)" << endl;
	o3 = o1%o2;
	o3.display();

	cout << "Testing scalar overload, result should be (2500)" << endl;
	scalar = o1*o2;
	cout << scalar;

	cout << endl << endl << "BIN TESTING" << endl;
	Bin b1(5);
	cout << "Adding vectors to bin" << endl;

	// Adding 5 elements to the bin
	for (int i = 0; i < 5; i++) {
		b1.add(x, y, z);
		cout << "Getting components from vector " << i << " result should be " << x << ", " << y << ", " << z << ", " << "ACTUAL RESULT: " << b1.getX(i) << ", " << b1.getY(i) << ", " << b1.getZ(i) << endl;
		x += 15;
		y += 15;
		z += 15;

	}
	cout << endl << "Removing the 1st & 2rd element of the bin (Oth & 1nd element of the array)" << endl;
	//IMPORTANT TO REMEMBER SINCE WE SHIFT TO THE LEFT WE HAVE TO KEEP IN MIND ONCE ELEMENT 0 HAS BEEN DELETED ELEMENT 1 WILL BECOME ELEMENT 0
	b1.remove(0);
	b1.remove(0);

	// Can see duplicate elements here but once we insert new Vector3Ds into the bin these will be overwritten, the important thing being the ones we wanted to delete are gone 
	cout << "Remaining vectors within the bin " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Getting components from vector " << i << " " << b1.getX(i) << ", " << b1.getY(i) << ", " << b1.getZ(i) << endl;
	}

	cout << endl << "Adding two new vectors to the bin " << endl;
	b1.add(x, y, z);
	x += 15;
	y += 15;
	z += 15;
	b1.add(x, y, z);

	// Can see now the duplicate elements are gone too 
	cout << endl << "All elements within the bin now that we have added two new vectors" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Getting components from vector " << i << " " << b1.getX(i) << ", " << b1.getY(i) << ", " << b1.getZ(i) << endl;
	}

	cout << endl << "BIN 2 " << endl;
	// Creating new bin 
	Bin b2(5);
	for (int i = 0; i < 5; i++) {
		b2.add(x, y, z);
		cout << "Getting components from vector " << i << " result should be " << x << ", " << y << ", " << z << ", " << "ACTUAL RESULT: " << b2.getX(i) << ", " << b2.getY(i) << ", " << b2.getZ(i) << endl;
		x += 5;
		y += 5;
		z += 5;

	}

	cout << endl << "TESTING EQUAL OVERLOAD b1 = b2" << endl;
	b1 = b2;

	cout << endl << "PRINTING OUT b1" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Getting components from vector " << i << " " << b1.getX(i) << ", " << b1.getY(i) << ", " << b1.getZ(i) << endl;
	}



	cin >> hold;
	return 0;
}

