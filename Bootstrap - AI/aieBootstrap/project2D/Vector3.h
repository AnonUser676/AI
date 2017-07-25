/*--------------------------------------------------------------------
Math Library
Vector 3
Header File
----------------------------------------------------------------------*/

/*--------------------------------------------------------------------
Has an include for Math.h library for use with finding the Square Root
of certain numbers

The codes set below is used to export to create either a Static Library
or a Dynamic Library, depending on the Configuration being built.

First it checks if the Configuration being used is a Static Library,
if it does then it creates a definition called MATH_DLL which will be used
to set if the library needs to be dllexport or dllimport,

if the Library requires an export, then it sets MATH_DLL changes into
__declspec(dllexport)

if the Library requires an import, then it sets MATH_DLL changes into
__declspec(dllimport)
----------------------------------------------------------------------*/

#pragma once
#include "Math.h"
#include "vector2.h"
#include "vector4.h"

#ifdef STATIC_LIB

#define MATH_DLL

#else

#ifdef DLL_EXPORT
#define MATH_DLL __declspec(dllexport)
#else 
#define MATH_DLL __declspec(dllimport)
#endif
#endif


/*----------------------------------------------------------------------
Vector3 operators and functions proper, placed in public so that all
functions can be used and viewed by any program that uses the Math Library
------------------------------------------------------------------------*/

class Vector3
{
public:
	
	/*----------------------------------------------------------------------
	Constructors and Deconstructors for Vector3.

	1st Constructor is used if the instance created for Vector3 does not have
	any values.

	2nd Constructor is used if the instance created for Vector3 gets passed 3
	floats.

	variable float x, float y and float z is what is used for storing the values
	for any instance of Vector3 created.
	------------------------------------------------------------------------*/
	MATH_DLL Vector3();
	MATH_DLL Vector3(float valx, float valy, float valz);
	MATH_DLL ~Vector3();

	float x;
	float y;
	float z;


	/*----------------------------------------------------------------------
	The operators are listed here but what they individually do will be commented
	on the CPP file, but the basic definition of what they are purposed to do will
	be listed here

	Overload code						Purpose

	>	operator = 							- passes in the value of rhs to replace current value in Vector
	>	operator + 							- adds 2 Vectors
	>	operator + 							- adds 2 Vectors which one is a Vector 2
	>	operator +=							- adds 2 Vectors and replaces the original Vector
	>	operator - 							- subtracts a Vector from another Vector
	>	operator - 							- converts the elements of the vector to a negative
	>	operator -=							- subtracts a Vector from another Vector and replaces the original Vector
	>	operator * 							- multiplies a float to Vector
	>	operator *=							- multiplies a float to Vector and replaces Vector with the result
	>	operator / 							- divides a float to Vector
	>	operator /=							- divides a float to Vector and replaces Vector with the result
	>	dot 								- performs a dot product between 2 Vectors
	>	cross 								- calculates the cross product between 2 Vectors
	>	magnitude 							- gets the magnitude of a Vector
	>	sqrMagnitude 						- gets the square of the magnitude of a Vector
	>	normalise 							- normalises a Vector
	>	clamping 							- clamps a Vector to the min or max of another Vector
	>	operator []							- gets the value of a position in a Vector based on the value of nIndex
	>	float * 							- an overload that returns the address of a Vector
	>	lerp								- performs a Linear Interpolation on a Vector
	>	distance							- gets the distance between 2 Vectors
	>	==									- checks if 2 Vectors are the identical (returns true if it is)
	>	!=									- checks if 2 Vectors are the not identical (returns true if it is)
	>	<									- checks if a Vector is less than another Vector (returns true if it is)
	>	<=									- checks if a Vector is less than or identical to another Vector (returns true if it is)
	>	>									- checks if a Vector is greater than another Vector (returns true if it is)
	>	>=									- checks if a Vector is greater than or identical to another Vector (returns true if it is)
	>	quadBezier							- computes for a bezier curve based on 3 Vectors
	>	cubicBezier							- computes for a bezier curve based on 4 Vectors
	>	Max									- compares 2 Vectors and returns the larger value of x and y
	>	Min									- compares 2 Vectors and returns the smaller value of x and y
	>	hermitCurve							- creates a Hermite Curve using Vector tangents and control points
	>	convert 							- converts a Vector 3 to a Vector 2
	>	XXX
	>	XXY									
	>	XXZ									
	>	XYX
	>	XYY
	>	XZX
	>	XZY
	>	XZZ
	>	YXX
	>	YXY
	>	YXZ
	>	YYX									}- Swaps or changes the values of a Vector depending on the combination of the letters used
	>	YYY									   also known as Swizzling
	>	YYZ
	>	YZX
	>	YZY
	>	YZZ
	>	ZXX
	>	ZXY
	>	ZXZ
	>	ZYX
	>	ZYY
	>	ZYZ
	>	ZZX
	>	ZZY
	>	ZZZ
	>	operator *(float, Vector3)			- multiplies a passed in Vector with a float and returns the resulting Vector
	------------------------------------------------------------------------*/

	MATH_DLL Vector3 operator =(const Vector3 & rhs);
	MATH_DLL Vector3 operator +(const Vector3 & rhs);
	MATH_DLL Vector3 operator +(const Vector2 & rhs);
	MATH_DLL Vector3 operator +=(const Vector3 & rhs);
	MATH_DLL Vector3 operator -(const Vector3 & rhs);
	MATH_DLL Vector3 operator -();
	MATH_DLL Vector3 operator -=(const Vector3 & rhs);
	MATH_DLL Vector3 operator *(const float scalar);
	MATH_DLL Vector3 operator *=(const float scalar);
	MATH_DLL Vector3 operator /(const float scalar);
	MATH_DLL Vector3 operator /=(const float scalar);
	MATH_DLL float dot(const Vector3 & rhs);
	MATH_DLL Vector3 cross(const Vector3 & rhs);
	MATH_DLL float magnitude();
	MATH_DLL float sqrMagnitude();
	MATH_DLL Vector3 normalise();
	MATH_DLL void clamping(const Vector3 & min, const Vector3 & max);
	MATH_DLL float & operator [] (const int nIndex);
	MATH_DLL operator float*();
	MATH_DLL Vector3 lerp(const Vector3 & lhs, const Vector3 & rhs, const float t);
	MATH_DLL float distance(const Vector3 & lhs);
	MATH_DLL bool operator ==(const Vector3 & rhs);
	MATH_DLL bool operator !=(const Vector3 & rhs);
	MATH_DLL bool operator <(const Vector3 & rhs);
	MATH_DLL bool operator <=(const Vector3 & rhs);
	MATH_DLL bool operator >(const Vector3 & rhs);
	MATH_DLL bool operator >=(const Vector3 & rhs);
	MATH_DLL Vector3 quadBezier(const Vector3 & A, const Vector3 & B, const Vector3 & C, const float t);
	MATH_DLL Vector3 cubicBezier(const Vector3 & A, const Vector3 & B, const Vector3 & C, const Vector3 & D, const float t);
	MATH_DLL Vector3 Max(const Vector3 & rhs);
	MATH_DLL Vector3 Min(const Vector3 & rhs);
	MATH_DLL Vector3 hermitCurve(const Vector3 & pointA, const Vector3 & tangentA, const Vector3 & pointB, const Vector3 & tangentB, const float t);
	
	MATH_DLL Vector3 XXX();
	MATH_DLL Vector3 XXY();
	MATH_DLL Vector3 XXZ();
	MATH_DLL Vector3 XYX();
	MATH_DLL Vector3 XYY();
	MATH_DLL Vector3 XZX();
	MATH_DLL Vector3 XZY();
	MATH_DLL Vector3 XZZ();
	MATH_DLL Vector3 YXX();
	MATH_DLL Vector3 YXY();
	MATH_DLL Vector3 YXZ();
	MATH_DLL Vector3 YYX();
	MATH_DLL Vector3 YYY();
	MATH_DLL Vector3 YYZ();
	MATH_DLL Vector3 YZX();
	MATH_DLL Vector3 YZY();
	MATH_DLL Vector3 YZZ();
	MATH_DLL Vector3 ZXX();
	MATH_DLL Vector3 ZXY();
	MATH_DLL Vector3 ZXZ();
	MATH_DLL Vector3 ZYX();
	MATH_DLL Vector3 ZYY();
	MATH_DLL Vector3 ZYZ();
	MATH_DLL Vector3 ZZX();
	MATH_DLL Vector3 ZZY();
	MATH_DLL Vector3 ZZZ();

};

MATH_DLL Vector3 operator *(const float scalar, const Vector3 & rhs);