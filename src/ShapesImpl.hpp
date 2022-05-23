#pragma once

#include <stdexcept>

class ShapeCalcExcept : public std::exception
{
public:
	ShapeCalcExcept(const char* _Msg)
		:
		std::exception(_Msg)
	{	}
};

#include "ShapeInterface.hpp"

class Sphere : public IShape
{
	float mRadius;
public:
	Sphere(std::string&& _Name, float _Radius = 0.f);

	void read_data();

	float get_perimetr();
	float get_area();
	float get_volume();
};

class Parallelepiped : public IShape
{
	float mWidth, mHeight, mDepth;
public:
	Parallelepiped(std::string&& _Name, float _Width = 0.f, float _Height = 0.f, float _Depth = 0.f);

	void read_data();

	float get_perimetr();
	float get_area();
	float get_volume();
};