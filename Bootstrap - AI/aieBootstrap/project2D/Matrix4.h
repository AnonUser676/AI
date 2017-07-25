#pragma once
#include "Math.h"
#include "Vector4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"


#ifdef STATIC_LIB

#define MATH_DLL

#else

#ifdef DLL_EXPORT
#define MATH_DLL __declspec(dllexport)
#else 
#define MATH_DLL __declspec(dllimport)
#endif
#endif


class Matrix4
{
public:
	MATH_DLL Matrix4();
	MATH_DLL Matrix4(float val1, float val2, float val3, float val4, float val5, float val6, float val7, float val8, float val9, float val10, float val11, float val12, float val13, float val14, float val15, float val16 );
	MATH_DLL ~Matrix4();

	float matrix[4][4];

	MATH_DLL Matrix4 operator +(Matrix4 rhs);
	MATH_DLL Matrix4 operator +=(Matrix4 rhs);
	MATH_DLL Matrix4 operator -(Matrix4 rhs);
	MATH_DLL Matrix4 operator -=(Matrix4 rhs);
	MATH_DLL Matrix4 operator *(Matrix4 rhs);
	MATH_DLL Matrix4 operator *=(Matrix4 rhs);
	MATH_DLL Vector4 operator * (const Vector4 & rhs);
	MATH_DLL Matrix4 operator * (const float scalar);
	MATH_DLL Matrix4 operator *= (const float scalar);
	MATH_DLL void scale(const Vector4 pos);
	MATH_DLL void scale(const Vector3 pos);
	MATH_DLL void scale(const Vector2 pos);
	MATH_DLL Vector2 getScaleV2();
	MATH_DLL Vector3 getScaleV3();
	MATH_DLL Vector4 getScaleV4();
	MATH_DLL void setPosition(const Vector2 pos);
	MATH_DLL void setPosition(const Vector3 pos);
	MATH_DLL Vector3 getPosition();
	MATH_DLL Vector4 & operator [] (const int nIndex);
	MATH_DLL operator float*();
	MATH_DLL void setRotateX(const float angle);
	MATH_DLL void setRotateY(const float angle);
	MATH_DLL void setRotateZ(const float angle);
	MATH_DLL bool isIdentity();
	MATH_DLL float determinant();
	MATH_DLL Matrix4 transpose();
	MATH_DLL Matrix4 inverse();
	MATH_DLL void LookAt(const Vector3 from, const Vector3 target, const Vector3 up);
};