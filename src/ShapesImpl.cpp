#include "ShapesImpl.hpp"

IShape::IShape(std::string&& _Name)
	:
	mName(_Name)
{	}

IShape::~IShape() {	};

std::string IShape::get_name()
{
	return mName;
}

#include <iostream>

/*********************************** Shpere ***********************************/

constexpr double PI = 3.141592653589793;

Sphere::Sphere(std::string&& _Name, float _Radius)
	:
	IShape(std::move(_Name)),
	mRadius(_Radius)
{	}

void Sphere::read_data()
{
	std::cout << "entry shpere radius: ";
	std::cin >> mRadius;
}

float Sphere::get_perimetr()
{
	throw ShapeCalcExcept("unable to calculate perimeter");
}

float Sphere::get_area()
{
	return static_cast<float>(4 * PI * mRadius * mRadius);
}

float Sphere::get_volume()
{
	return static_cast<float>(4.f / 3.f * PI * mRadius * mRadius * mRadius);
}

/*********************************** Parallelepiped ***********************************/

Parallelepiped::Parallelepiped(std::string&& _Name, float _Width, float _Height, float _Depth)
	:
	IShape(std::move(_Name)),
	mWidth(_Width),
	mHeight(_Height),
	mDepth(_Depth)
{	}

void Parallelepiped::read_data()
{
	std::cout << "Entry width, height and depth: ";
	std::cin >> mWidth >> mHeight >> mDepth;
}

float Parallelepiped::get_perimetr()
{
	throw ShapeCalcExcept("unable to calculate perimeter");
}

float Parallelepiped::get_area()
{
	return 2.f * (mWidth * mHeight + mHeight * mDepth + mWidth * mDepth);
}

float Parallelepiped::get_volume()
{
	return mHeight*mWidth*mDepth;
}

