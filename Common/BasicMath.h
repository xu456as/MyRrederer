#pragma once
#include <cstring>
#include<cmath>
namespace BasicMath
{
	/*
		Start Vector definition and operation
 	*/

	struct Matrix4x4;
	struct Vector4{
	
		float v[4];
		Vector4(){
			memset(v, 0, sizeof(v));
		}
		Vector4(float x, float y, float z, float w){
			v[0] = x;v[1] = y;
			v[2] = z;v[3] = w;
		}
		Vector4(const Vector4& x){
			memcpy(v, x.v, 4 * sizeof(float));
		}

		float operator[] (int i) const {
			return v[i];
		}
		float& operator[] (int i) {
			return v[i];
		}

		float Length();
		void Normalize();

		//cross product
		Vector4 Cross(const Vector4& x) const;
		
		Vector4 Apply (const Matrix4x4& x) const;

		Vector4 operator- (const Vector4& x) const ;

		
		
	};
	//dot product
	float operator* (const Vector4& x, const Vector4& y);

	Vector4 operator+ (const Vector4& x, const Vector4& y);

	Vector4 operator* (const Vector4& x, const float& num);

	/*
		End Vector definition and operation
 	*/

	/*
		Start Matrix definition and operation
 	*/

	struct Matrix4x4{

		friend Vector4 Vector4::Apply(const Matrix4x4& x) const ;

		float m[4][4];

		Matrix4x4(){
			memset(m, 0, sizeof(m));
		}
		Matrix4x4(const Matrix4x4& x){
			memcpy(m, x.m, 16 * sizeof(float));
		}
		const float(*operator[](int i) const) {
			return (m[i]);
		}

		float  (* operator[](int i)) {
			return (m[i]);
		}

		void SetZero();
		void SetIdentity();

		void SetTranslate(float x, float y, float z);
		void SetScale(float x, float y, float z);
		void SetRotate(Vector4 privot, float theta);
		void SetLookAt(Vector4 eye, Vector4 at, Vector4 up);
		void SetPerspective(float fovAngleY, float aspectRatio, float nearZ, float farZ);

		Matrix4x4 operator* (const Matrix4x4& y) const ;

		Matrix4x4 operator- (const Matrix4x4& y) const ;

	};

	Matrix4x4 operator* (const Matrix4x4& x, const float& num);


	/*
		End Matrix definition and operation
 	*/

	/*
		Start screen point definition
	*/
	struct SceenPoint{
		int x;
		int y;

		SceenPoint(int x, int y){
			this->x = x;
			this->y = y;
		}

	};
	/*
		End screen point definition
	*/


	template<typename T>
	T Clamp(T x, T min, T max);

	template<typename T>
	T Lerp(T from, T to, float x);

	int gcd(int x, int y);

	bool EqualF(float f1, float f2);
}