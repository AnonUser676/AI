/*--------------------------------------------------------------------
Math Library
Vector 2
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
These lines create a class Matrix2
and a class Vector3 for use in certain functions.
------------------------------------------------------------------------*/

class Matrix2;
class Vector3;


/*----------------------------------------------------------------------
Vector2 operators and functions proper, placed in public so that all
functions can be used and viewed by any program that uses the Math Library
------------------------------------------------------------------------*/

class Vector2
{
public:

	/*----------------------------------------------------------------------
	Constructors and Deconstructors for Vector2.
	
	1st Constructor is used if the instance created for Vector2 does not have
	any values.

	2nd Constructor is used if the instance created for Vector2 gets passed 2
	floats.

	variable float x and float y is what is used for storing the values for
	any instance of Vector2 created.
	------------------------------------------------------------------------*/
	MATH_DLL Vector2();
	MATH_DLL Vector2(float valx, float valy);
	MATH_DLL ~Vector2();

	float x;
	float y;

	/*----------------------------------------------------------------------
	The operators are listed here but what they individually do will be commented
	on the CPP file, but the basic definition of what they are purposed to do will
	be listed here

		Overload code						Purpose
		
	>	operator = 							- passes in the value of rhs to replace current value in Vector
	>	convert 							- converts a Vector 3 to a Vector 2
	>	operator + 							- adds 2 Vectors
	>	operator +=							- adds 2 Vectors and replaces the original Vector
	>	operator - 							- subtracts a Vector from another Vector
	>	operator -=							- subtracts a Vector from another Vector and replaces the original Vector
	>	operator * 							- multiplies a float to Vector
	>	operator *=							- multiplies a float to Vector and replaces Vector with the result
	>	operator / 							- divides a float to Vector
	>	operator /=							- divides a float to Vector and replaces Vector with the result
	>	dot 								- performs a dot product between 2 Vectors
	>	magnitude 							- gets the magnitude of a Vector
	>	sqrMagnitude 						- gets the square of the magnitude of a Vector
	>	clamping 							- clamps a Vector to the min or max of another Vector
	>	normalise 							- normalises a Vector
	>	operator []							- gets the value of a position in a Vector based on the value of nIndex
	>	float * 							- an overload that returns the address of a Vector
	>	XX 									
	>	YY 									}- Swaps or changes the values of a Vector depending on the combination of the letters used
	>	YX 									   also known as Swizzling
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
	>	operator *(float, Vector2)			- multiplies a passed in Vector with a float and returns the resulting Vector
	------------------------------------------------------------------------*/

	MATH_DLL Vector2 operator =(const Vector2 & rhs);
	MATH_DLL Vector2 convert(const Vector3 & rhs);
	MATH_DLL Vector2 operator +(const Vector2 & rhs);
	MATH_DLL Vector2 operator +=(const Vector2 & rhs);
	MATH_DLL Vector2 operator -(const Vector2 & rhs);
	MATH_DLL Vector2 operator -=(const Vector2 & rhs);
	MATH_DLL Vector2 operator *(const float scalar);
	MATH_DLL Vector2 operator *=(const float scalar);
	MATH_DLL Vector2 operator /(const float scalar);
	MATH_DLL Vector2 operator /=(const float scalar);
	MATH_DLL float dot(const Vector2 & rhs);
	MATH_DLL float magnitude();
	MATH_DLL float sqrMagnitude();
	MATH_DLL Vector2 clamping(const Vector2 & min, const Vector2 & max);
	MATH_DLL Vector2 normalise();
	MATH_DLL float & operator [] (const int nIndex);
	MATH_DLL operator float*();
	MATH_DLL Vector2 XX();
	MATH_DLL Vector2 YY();
	MATH_DLL Vector2 YX();
	MATH_DLL Vector2 lerp(const Vector2 & lhs, const Vector2 & rhs, const float t);
	MATH_DLL float distance(const Vector2 & lhs);
	MATH_DLL bool operator ==(const Vector2 & rhs);
	MATH_DLL bool operator !=(const Vector2 & rhs);
	MATH_DLL bool operator <(const Vector2 & rhs);
	MATH_DLL bool operator <=(const Vector2 & rhs);
	MATH_DLL bool operator >(const Vector2 & rhs);
	MATH_DLL bool operator >=(const Vector2 & rhs);
	MATH_DLL Vector2 quadBezier(const Vector2 & A, const Vector2 & B, const Vector2 & C, const float t);
	MATH_DLL Vector2 cubicBezier(const Vector2 & A, const Vector2 & B, const Vector2 & C, const Vector2 & D, const float t);
	MATH_DLL Vector2 Max(const Vector2 & rhs);
	MATH_DLL Vector2 Min(const Vector2 & rhs);
	MATH_DLL Vector2 hermitCurve(const Vector2 & pointA, const Vector2 & tangentA, const Vector2 & pointB, const Vector2 & tangentB, const float t);

};

MATH_DLL Vector2 operator *(const float scalar, const Vector2 & rhs);