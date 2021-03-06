#include <iostream>
#include <map>
#include <memory>

#include "ShapesImpl.hpp"

enum class CalcTarget : size_t
{
	Done,
	Perimetr,
	Area,
	Volume
};

//insert value before "Count"
enum class Shapes : size_t
{
	Nope,
	Sphere,
	Parallelepiped,
	Count
};

using dict_t = std::map<Shapes, std::unique_ptr<IShape>>;

auto create_dict()
{
	dict_t dict;

	dict[Shapes::Sphere] = std::make_unique<Sphere>("Sphere", 0.f);
	dict[Shapes::Parallelepiped] = std::make_unique<Parallelepiped>("Parallelepiped", 0.f, 0.f, 0.f);

	return dict;
}

void make_calc(IShape* _Shape)
{
	if (!_Shape)
		return;

	_Shape->read_data();

	size_t selector = -1;
	for (; selector;)
	{
		std::cout << 0 << " : Done" << std::endl <<
			1 << " : calc perimetr" << std::endl <<
			2 << " : calc area" << std::endl <<
			3 << " : calc volume" << std::endl;

		std::cin >> selector;
		try {
			switch (static_cast<CalcTarget>(selector))
			{
			case CalcTarget::Done:
				break;
			case CalcTarget::Perimetr:
				std::cout << "Perimetr is : " << _Shape->get_perimetr() << std::endl;
				break;
			case CalcTarget::Area:
				std::cout << "Area is : " << _Shape->get_area() << std::endl;
				break;
			case CalcTarget::Volume:
				std::cout << "Volume is : " << _Shape->get_volume() << std::endl;
				break;
			default:
				std::cout << "What you wi???" << std::endl;
				break;
			}
		}
		catch (ShapeCalcExcept& e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int main()
{
	auto dict = create_dict();

	size_t selector = -1;
	for (; selector;)
	{
		std::cout << 0 << " : Exit" << std::endl;
		for (auto& e : dict)
		{
			std::cout << static_cast<size_t>(e.first) << " : " << e.second->get_name() << std::endl;
		}
		std::cin >> selector;

		if (selector == 0)
			break;

		if (selector < static_cast<size_t>(Shapes::Count))
			make_calc(dict[static_cast<Shapes>(selector)].get());
	}

	return 0;
}