/*
 *  Vector.h
 *  Tiles
 *
 *  Created by Jack on 9/16/10.
 *  Copyright 2010 Never Ending Software. All rights reserved.
 *
 */
#ifndef C_VECTOR
#define C_VECTOR

#include <math.h>

class Vector2D
{
public:
    
	float   x;
	float   y;
	
	Vector2D() {}
	
	Vector2D(float r, float s)
	{
		x = r;
		y = s;
	}
	
	Vector2D& Set(float r, float s)
	{
		x = r;
		y = s;
		return (*this);
	}
	Vector2D* Zero() {
		(this)->Set(0.0f, 0.0f);
		
		return (this);
	}
	
	const float& operator [](long k) const
	{
		return ((&x)[k]);
	}
	
	Vector2D& operator +=(const Vector2D& v)
	{
		x += v.x;
		y += v.y;
		return (*this);
	}
	
	Vector2D& operator -=(const Vector2D& v)
	{
		x -= v.x;
		y -= v.y;
		return (*this);
	}
	
	Vector2D& operator *=(float t)
	{
		x *= t;
		y *= t;
		return (*this);
	}
	
	Vector2D& operator /=(float t)
	{
		float f = 1.0F / t;
		x *= f;
		y *= f;
		return (*this);
	}
	
	Vector2D& operator &=(const Vector2D& v)
	{
		x *= v.x;
		y *= v.y;
		return (*this);
	}
	
	Vector2D operator -(void) const
	{
		return (Vector2D(-x, -y));
	}
	
	Vector2D operator +(const Vector2D& v) const
	{
		return (Vector2D(x + v.x, y + v.y));
	}
	
	Vector2D operator -(const Vector2D& v) const
	{
		return (Vector2D(x - v.x, y - v.y));
	}
	
	Vector2D operator *(float t) const
	{
		return (Vector2D(x * t, y * t));
	}
	
	Vector2D operator /(float t) const
	{
		float f = 1.0F / t;
		return (Vector2D(x * f, y * f));
	}
	
	float operator *(const Vector2D& v) const
	{
		return (x * v.x + y * v.y);
	}
	
	Vector2D operator &(const Vector2D& v) const
	{
		return (Vector2D(x * v.x, y * v.y));
	}
	
	bool operator ==(const Vector2D& v) const
	{
		return ((x == v.x) && (y == v.y));
	}
	
	bool operator !=(const Vector2D& v) const
	{
		return ((x != v.x) || (y != v.y));
	}
	
	Vector2D& Normalize(void)
	{
		return (*this /= sqrtf(x * x + y * y));
	}
	
	Vector2D& Rotate(float angle);
	
	float Length() const{
		return sqrtf((x*x) + (y*y));
	}
	
	float Dot(Vector2D vec1, Vector2D vec2)
	{
		return (vec1.x*vec2.x)+(vec1.y*vec2.y);
	}
};

#endif