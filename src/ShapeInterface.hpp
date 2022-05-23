#pragma once

#include <string>

class IShape
{
	std::string mName;
public:
	IShape(std::string&& _Name);
	virtual ~IShape();

	std::string get_name();
	virtual void read_data() = 0;

	virtual float get_perimetr() = 0;
	virtual float get_area() = 0;
	virtual float get_volume() = 0;
};