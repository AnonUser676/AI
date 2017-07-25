/*--------------------------------------------------------------------
Math Library
Vector 4
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
#include <Math.h>
#include "vector3.h"
#include "vector2.h"

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
Vector4 operators and functions proper, placed in public so that all
functions can be used and viewed by any program that uses the Math Library
------------------------------------------------------------------------*/

class Vector4
{
public:

	/*----------------------------------------------------------------------
	Constructors and Deconstructors for Vector4.

	1st Constructor is used if the instance created for Vector4 does not have
	any values.

	2nd Constructor is used if the instance created for Vector4 gets passed 4
	floats.

	3rd Constructor is used if the instance created for Vector4 gets passed a
	Vector3

	variable float x, float y, float z and float w is what is used for storing
	the values for any instance of Vector3 created.
	------------------------------------------------------------------------*/
	MATH_DLL Vector4();
	MATH_DLL Vector4(float valx, float valy, float valz, float valw);
	MATH_DLL Vector4(const Vector3 & rhs);
	MATH_DLL ~Vector4();

	float x;
	float y;
	float z;
	float w;


	/*----------------------------------------------------------------------
	The operators are listed here but what they individually do will be commented
	on the CPP file, but the basic definition of what they are purposed to do will
	be listed here

	Overload code						Purpose

	>	operator = 							- passes in the value of rhs to replace current value in Vector
	>	operator + 							- adds 2 Vectors
	>	operator +=							- adds 2 Vectors and replaces the original Vector
	>	operator - 							- subtracts a Vector from another Vector
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
	>	convertV2 							- converts a Vector 3 to a Vector 2
	>	convertV3 							- converts a Vector 3 to a Vector 2
	>	Swizzling (too many to list)		}- Swaps or changes the values of a Vector depending on the combination of the letters used
											   also known as Swizzling
	>	operator *(float, Vector3)			- multiplies a passed in Vector with a float and returns the resulting Vector
	------------------------------------------------------------------------*/

	MATH_DLL Vector4 operator =(const Vector4 & rhs);
	MATH_DLL Vector4 operator +(const Vector4 & rhs);
	MATH_DLL Vector4 operator +=(const Vector4 & rhs);
	MATH_DLL Vector4 operator -(const Vector4 & rhs);
	MATH_DLL Vector4 operator -=(const Vector4 & rhs);
	MATH_DLL Vector4 operator *(const float scalar);
	MATH_DLL Vector4 operator *=(const float scalar);
	MATH_DLL Vector4 operator /(const float scalar);
	MATH_DLL Vector4 operator /=(const float scalar);
	MATH_DLL float dot(const Vector4 & rhs);
	MATH_DLL Vector4 cross(const Vector4 & rhs);
	MATH_DLL float magnitude();
	MATH_DLL float sqrMagnitude();
	MATH_DLL Vector4 normalise();
	MATH_DLL void clamping(const Vector4 & min, const Vector4 & max);
	MATH_DLL float & operator [] (const int nIndex);
	MATH_DLL operator float*();
	MATH_DLL Vector4 lerp(const Vector4 & lhs, const Vector4 & rhs, const float t);
	MATH_DLL float distance(const Vector4 & lhs);
	MATH_DLL bool operator ==(const Vector4 & rhs);
	MATH_DLL bool operator !=(const Vector4 & rhs);
	MATH_DLL bool operator <(const Vector4 & rhs);
	MATH_DLL bool operator <=(const Vector4 & rhs);
	MATH_DLL bool operator >(const Vector4 & rhs);
	MATH_DLL bool operator >=(const Vector4 & rhs);
	MATH_DLL Vector4 quadBezier(const Vector4 & A, const Vector4 & B, const Vector4 & C, const float t);
	MATH_DLL Vector4 cubicBezier(const Vector4 & A, const Vector4 & B, const Vector4 & C, const Vector4 & D, const float t);
	MATH_DLL Vector4 Max(const Vector4 & rhs);
	MATH_DLL Vector4 Min(const Vector4 & rhs);
	MATH_DLL Vector4 hermitCurve(const Vector4 & pointA, const Vector4 & tangentA, const Vector4 & pointB, const Vector4 & tangentB, const float t);
	MATH_DLL Vector2 convertV2();
	MATH_DLL Vector3 convertV3();

	MATH_DLL Vector4 WWWW();
	MATH_DLL Vector4 WWWX();
	MATH_DLL Vector4 WWWY();
	MATH_DLL Vector4 WWWZ();
	MATH_DLL Vector4 WWXW();
	MATH_DLL Vector4 WWXX();
	MATH_DLL Vector4 WWXY();
	MATH_DLL Vector4 WWXZ();
	MATH_DLL Vector4 WWYW();
	MATH_DLL Vector4 WWYX();
	MATH_DLL Vector4 WWYY();
	MATH_DLL Vector4 WWYZ();
	MATH_DLL Vector4 WWZW();
	MATH_DLL Vector4 WWZX();
	MATH_DLL Vector4 WWZY();
	MATH_DLL Vector4 WWZZ();
	MATH_DLL Vector4 WXWW();
	MATH_DLL Vector4 WXWX();
	MATH_DLL Vector4 WXWY();
	MATH_DLL Vector4 WXWZ();
	MATH_DLL Vector4 WXXW();
	MATH_DLL Vector4 WXXX();
	MATH_DLL Vector4 WXXY();
	MATH_DLL Vector4 WXXZ();
	MATH_DLL Vector4 WXYW();
	MATH_DLL Vector4 WXYX();
	MATH_DLL Vector4 WXYY();
	MATH_DLL Vector4 WXYZ();
	MATH_DLL Vector4 WXZW();
	MATH_DLL Vector4 WXZX();
	MATH_DLL Vector4 WXZY();
	MATH_DLL Vector4 WXZZ();
	MATH_DLL Vector4 WYWW();
	MATH_DLL Vector4 WYWX();
	MATH_DLL Vector4 WYWY();
	MATH_DLL Vector4 WYWZ();
	MATH_DLL Vector4 WYXW();
	MATH_DLL Vector4 WYXX();
	MATH_DLL Vector4 WYXY();
	MATH_DLL Vector4 WYXZ();
	MATH_DLL Vector4 WYYW();
	MATH_DLL Vector4 WYYX();
	MATH_DLL Vector4 WYYY();
	MATH_DLL Vector4 WYYZ();
	MATH_DLL Vector4 WYZW();
	MATH_DLL Vector4 WYZX();
	MATH_DLL Vector4 WYZY();
	MATH_DLL Vector4 WYZZ();
	MATH_DLL Vector4 WZWW();
	MATH_DLL Vector4 WZWX();
	MATH_DLL Vector4 WZWY();
	MATH_DLL Vector4 WZWZ();
	MATH_DLL Vector4 WZXW();
	MATH_DLL Vector4 WZXX();
	MATH_DLL Vector4 WZXY();
	MATH_DLL Vector4 WZXZ();
	MATH_DLL Vector4 WZYW();
	MATH_DLL Vector4 WZYX();
	MATH_DLL Vector4 WZYY();
	MATH_DLL Vector4 WZYZ();
	MATH_DLL Vector4 WZZW();
	MATH_DLL Vector4 WZZX();
	MATH_DLL Vector4 WZZY();
	MATH_DLL Vector4 WZZZ();
	MATH_DLL Vector4 XWWW();
	MATH_DLL Vector4 XWWX();
	MATH_DLL Vector4 XWWY();
	MATH_DLL Vector4 XWWZ();
	MATH_DLL Vector4 XWXW();
	MATH_DLL Vector4 XWXX();
	MATH_DLL Vector4 XWXY();
	MATH_DLL Vector4 XWXZ();
	MATH_DLL Vector4 XWYW();
	MATH_DLL Vector4 XWYX();
	MATH_DLL Vector4 XWYY();
	MATH_DLL Vector4 XWYZ();
	MATH_DLL Vector4 XWZW();
	MATH_DLL Vector4 XWZX();
	MATH_DLL Vector4 XWZY();
	MATH_DLL Vector4 XWZZ();
	MATH_DLL Vector4 XXWW();
	MATH_DLL Vector4 XXWX();
	MATH_DLL Vector4 XXWY();
	MATH_DLL Vector4 XXWZ();
	MATH_DLL Vector4 XXXW();
	MATH_DLL Vector4 XXXX();
	MATH_DLL Vector4 XXXY();
	MATH_DLL Vector4 XXXZ();
	MATH_DLL Vector4 XXYW();
	MATH_DLL Vector4 XXYX();
	MATH_DLL Vector4 XXYY();
	MATH_DLL Vector4 XXYZ();
	MATH_DLL Vector4 XXZW();
	MATH_DLL Vector4 XXZX();
	MATH_DLL Vector4 XXZY();
	MATH_DLL Vector4 XXZZ();
	MATH_DLL Vector4 XYWW();
	MATH_DLL Vector4 XYWX();
	MATH_DLL Vector4 XYWY();
	MATH_DLL Vector4 XYWZ();
	MATH_DLL Vector4 XYXW();
	MATH_DLL Vector4 XYXX();
	MATH_DLL Vector4 XYXY();
	MATH_DLL Vector4 XYXZ();
	MATH_DLL Vector4 XYYW();
	MATH_DLL Vector4 XYYX();
	MATH_DLL Vector4 XYYY();
	MATH_DLL Vector4 XYYZ();
	MATH_DLL Vector4 XYZX();
	MATH_DLL Vector4 XYZY();
	MATH_DLL Vector4 XYZZ();
	MATH_DLL Vector4 XZWW();
	MATH_DLL Vector4 XZWX();
	MATH_DLL Vector4 XZWY();
	MATH_DLL Vector4 XZWZ();
	MATH_DLL Vector4 XZXW();
	MATH_DLL Vector4 XZXX();
	MATH_DLL Vector4 XZXY();
	MATH_DLL Vector4 XZXZ();
	MATH_DLL Vector4 XZYW();
	MATH_DLL Vector4 XZYX();
	MATH_DLL Vector4 XZYY();
	MATH_DLL Vector4 XZYZ();
	MATH_DLL Vector4 XZZW();
	MATH_DLL Vector4 XZZX();
	MATH_DLL Vector4 XZZY();
	MATH_DLL Vector4 XZZZ();
	MATH_DLL Vector4 YWWW();
	MATH_DLL Vector4 YWWX();
	MATH_DLL Vector4 YWWY();
	MATH_DLL Vector4 YWWZ();
	MATH_DLL Vector4 YWXW();
	MATH_DLL Vector4 YWXX();
	MATH_DLL Vector4 YWXY();
	MATH_DLL Vector4 YWXZ();
	MATH_DLL Vector4 YWYW();
	MATH_DLL Vector4 YWYX();
	MATH_DLL Vector4 YWYY();
	MATH_DLL Vector4 YWYZ();
	MATH_DLL Vector4 YWZW();
	MATH_DLL Vector4 YWZX();
	MATH_DLL Vector4 YWZY();
	MATH_DLL Vector4 YWZZ();
	MATH_DLL Vector4 YXWW();
	MATH_DLL Vector4 YXWX();
	MATH_DLL Vector4 YXWY();
	MATH_DLL Vector4 YXWZ();
	MATH_DLL Vector4 YXXW();
	MATH_DLL Vector4 YXXX();
	MATH_DLL Vector4 YXXY();
	MATH_DLL Vector4 YXXZ();
	MATH_DLL Vector4 YXYW();
	MATH_DLL Vector4 YXYX();
	MATH_DLL Vector4 YXYY();
	MATH_DLL Vector4 YXYZ();
	MATH_DLL Vector4 YXZW();
	MATH_DLL Vector4 YXZX();
	MATH_DLL Vector4 YXZY();
	MATH_DLL Vector4 YXZZ();
	MATH_DLL Vector4 YYWW();
	MATH_DLL Vector4 YYWX();
	MATH_DLL Vector4 YYWY();
	MATH_DLL Vector4 YYWZ();
	MATH_DLL Vector4 YYXW();
	MATH_DLL Vector4 YYXX();
	MATH_DLL Vector4 YYXY();
	MATH_DLL Vector4 YYXZ();
	MATH_DLL Vector4 YYYW();
	MATH_DLL Vector4 YYYX();
	MATH_DLL Vector4 YYYY();
	MATH_DLL Vector4 YYYZ();
	MATH_DLL Vector4 YYZW();
	MATH_DLL Vector4 YYZX();
	MATH_DLL Vector4 YYZY();
	MATH_DLL Vector4 YYZZ();
	MATH_DLL Vector4 YZWW();
	MATH_DLL Vector4 YZWX();
	MATH_DLL Vector4 YZWY();
	MATH_DLL Vector4 YZWZ();
	MATH_DLL Vector4 YZXW();
	MATH_DLL Vector4 YZXX();
	MATH_DLL Vector4 YZXY();
	MATH_DLL Vector4 YZXZ();
	MATH_DLL Vector4 YZYW();
	MATH_DLL Vector4 YZYX();
	MATH_DLL Vector4 YZYY();
	MATH_DLL Vector4 YZYZ();
	MATH_DLL Vector4 YZZW();
	MATH_DLL Vector4 YZZX();
	MATH_DLL Vector4 YZZY();
	MATH_DLL Vector4 YZZZ();
	MATH_DLL Vector4 ZWWW();
	MATH_DLL Vector4 ZWWX();
	MATH_DLL Vector4 ZWWY();
	MATH_DLL Vector4 ZWWZ();
	MATH_DLL Vector4 ZWXW();
	MATH_DLL Vector4 ZWXX();
	MATH_DLL Vector4 ZWXY();
	MATH_DLL Vector4 ZWXZ();
	MATH_DLL Vector4 ZWYW();
	MATH_DLL Vector4 ZWYX();
	MATH_DLL Vector4 ZWYY();
	MATH_DLL Vector4 ZWYZ();
	MATH_DLL Vector4 ZWZW();
	MATH_DLL Vector4 ZWZX();
	MATH_DLL Vector4 ZWZY();
	MATH_DLL Vector4 ZWZZ();
	MATH_DLL Vector4 ZXWW();
	MATH_DLL Vector4 ZXWX();
	MATH_DLL Vector4 ZXWY();
	MATH_DLL Vector4 ZXWZ();
	MATH_DLL Vector4 ZXXW();
	MATH_DLL Vector4 ZXXX();
	MATH_DLL Vector4 ZXXY();
	MATH_DLL Vector4 ZXXZ();
	MATH_DLL Vector4 ZXYW();
	MATH_DLL Vector4 ZXYX();
	MATH_DLL Vector4 ZXYY();
	MATH_DLL Vector4 ZXYZ();
	MATH_DLL Vector4 ZXZW();
	MATH_DLL Vector4 ZXZX();
	MATH_DLL Vector4 ZXZY();
	MATH_DLL Vector4 ZXZZ();
	MATH_DLL Vector4 ZYWW();
	MATH_DLL Vector4 ZYWX();
	MATH_DLL Vector4 ZYWY();
	MATH_DLL Vector4 ZYWZ();
	MATH_DLL Vector4 ZYXW();
	MATH_DLL Vector4 ZYXX();
	MATH_DLL Vector4 ZYXY();
	MATH_DLL Vector4 ZYXZ();
	MATH_DLL Vector4 ZYYW();
	MATH_DLL Vector4 ZYYX();
	MATH_DLL Vector4 ZYYY();
	MATH_DLL Vector4 ZYYZ();
	MATH_DLL Vector4 ZYZW();
	MATH_DLL Vector4 ZYZX();
	MATH_DLL Vector4 ZYZY();
	MATH_DLL Vector4 ZYZZ();
	MATH_DLL Vector4 ZZWW();
	MATH_DLL Vector4 ZZWX();
	MATH_DLL Vector4 ZZWY();
	MATH_DLL Vector4 ZZWZ();
	MATH_DLL Vector4 ZZXW();
	MATH_DLL Vector4 ZZXX();
	MATH_DLL Vector4 ZZXY();
	MATH_DLL Vector4 ZZXZ();
	MATH_DLL Vector4 ZZYW();
	MATH_DLL Vector4 ZZYX();
	MATH_DLL Vector4 ZZYY();
	MATH_DLL Vector4 ZZYZ();
	MATH_DLL Vector4 ZZZW();
	MATH_DLL Vector4 ZZZX();
	MATH_DLL Vector4 ZZZY();
	MATH_DLL Vector4 ZZZZ();
};

MATH_DLL Vector4 operator *(const float scalar, const Vector4 & rhs);