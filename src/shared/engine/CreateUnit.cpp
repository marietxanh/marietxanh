#include "CreateUnit.h"
#include <iostream>

using namespace engine;
using namespace status;

CreateUnit::CreateUnit (status::TypeUnits type_unit)
{
	this->type_unit = type_unit;
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
