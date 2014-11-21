#ifndef __VECTOR2_H__
#define __VECTOR2_H__

class Vector2
{
public:

	int x;
	int y;
	Vector2() : x(0), y(0)
	{
	
	}
	Vector2(int x, int y) : x(x), y(y)
	{

	}
	Vector2 operator+(const Vector2& rhs)
	{
		return Vector2(x + rhs.x, y + rhs.y);
	}
};

#endif