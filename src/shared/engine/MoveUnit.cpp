#include "MoveUnit.h"
#include <iostream>

using namespace engine;
using namespace status;

MoveUnit::MoveUnit (int height_start, int width_start, int height_end, int width_end)
{
	this->height_start = height_start;
	this->width_start = width_start;
	this->height_end = height_end;
	this->width_end = width_end;
}

CommandTypeID MoveUnit::getTypeID () const
{
	return MOVE;
}

void MoveUnit::execute (status::State& state)
{
	state.getUnits()->setElement(height_end, width_end, state.getUnits()->getElement(height_start, width_start));
    std::cout << "Move units from (" << height_start << ", " << width_start << ") to (" << height_end << ", " << width_end << ")" << std::endl;
    state.getUnits()->setElement(height_start, width_start, NULL);
}
