/*--------------------------------------------------------------------
Math Library
Matrix 2
Header File
----------------------------------------------------------------------*/

/*--------------------------------------------------------------------
Has an include for Math.h library for use with finding the Square Root
of certain numbers and using the sinf and cosf functions for finding the
Sine and Cosine of numbers

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
#include "Vector2.h"

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
Matrix2 operators and functions proper, placed in public so that all
functions can be used and viewed by any program that uses the Math Library
------------------------------------------------------------------------*/

class Matrix2
{
public:

	/*----------------------------------------------------------------------
	Constructors and Deconstructors for Maatrix2.

	1st Constructor is used if the instance created for Matrix2 does not have
	any values.

	2nd Constructor is used if the instance created for Matrix2 gets passed
	4 float values.

	A 2 by 2 array is created to store float values whenever an instance of Matrix2
	is created.
	------------------------------------------------------------------------*/
	MATH_DLL Matrix2();
	MATH_DLL Matrix2(float val1, float val2, float val3, float val4);
	MATH_DLL ~Matrix2();

	float matrix[2][2];


	/*----------------------------------------------------------------------
	The operators are listed here but what they individually do will be commented
	on the CPP file, but the basic definition of what they are purposed to do will
	be listed here

	Overload code						Purpose

	>	operator +						- adds 2 Matrices
	>	operator +=						- adds 2 Matrices and changes the left hand side Matrix into the sum
	>	operator -						- subtracts 2 Matrices
	>	operator -=						- subtracts 2 Matrices and changes the left hand side Matrix into the difference
	>	operator *	(Matrix)			- multiplies a Matrix with another Matrix
	>	operator *=	(Matrix)			- multiplies a Matrix with another Matrix and replace the left hand side with the product
	>	operator *	(Vector)			- multiplies a Matrix with a Vector
	>	operator *	(float)				- multiplies a Matrix with a float
	>	operator *=	(float)				- multiplies a Matrix with a float and replaces the Matrix with the result
	>	setScale						- changes the value for [0][0] and [1][1] of the Matrix
	>	getScale						- retrieves the value for [0][0] and [1][1] of the Matrix
	>	operator []						- retrieves the Vector for a line in the Matrix equivalent to the passed in integer
	>	float*							- returns the address of the Matrix
	>	setRotate						- changes the value in the Matrix to equal rotation depending on the float passed in
	>	isIdentity						- Checks if the Matrix is an Identity Matrix
	>	determinant						- Calculates the determinant of the Matrix
	>	inverse							- Inverses the Matrix
	>	transpose						- Transposes the Matrix
	------------------------------------------------------------------------*/

	MATH_DLL Matrix2 operator +(Matrix2 rhs);
	MATH_DLL Matrix2 operator +=(Matrix2 rhs);
	MATH_DLL Matrix2 operator -(Matrix2 rhs);
	MATH_DLL Matrix2 operator -=(Matrix2 rhs);
	MATH_DLL Matrix2 operator *(Matrix2 rhs);
	MATH_DLL Matrix2 operator * (const float scalar);
	MATH_DLL Matrix2 operator *=(Matrix2 rhs);
	MATH_DLL Vector2 operator * (const Vector2 rhs);
	MATH_DLL Matrix2 operator *= (const float scalar);
	MATH_DLL void setScale(const Vector2 pos);
	MATH_DLL Vector2 getScale();
	MATH_DLL Vector2 & operator [] (const int nIndex);
	MATH_DLL operator float*();
	MATH_DLL void setRotate(const float angle);
	MATH_DLL bool isIdentity();
	MATH_DLL float determinant();
	MATH_DLL Matrix2 inverse();
	MATH_DLL Matrix2 transpose();
};