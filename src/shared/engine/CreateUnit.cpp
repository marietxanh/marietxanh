#include "CreateUnit.h"
#include "../status.h"
#include <iostream>

using namespace status;

namespace engine {

	CreateUnit::CreateUnit (status::TypeUnits type_unit, int height, int width)
	{
		this->type_unit = type_unit;
		this->height = height;
		this->width = width;
	}
	
	CreateUnit::~CreateUnit()
	{
	
	}
	
	CommandTypeID CreateUnit::getTypeID () const
	{
		return CREATE;
	}
	void CreateUnit::execute (status::State& state)
	{
		state.getUnits()->setElement(height, width, new Unit(type_unit));
		std::cout << "Unit created in (" << height << ", " << width << ")" << std::endl;	
	}
	
};
