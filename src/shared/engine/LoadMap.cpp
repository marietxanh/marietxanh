#include "LoadMap.h"
#include <iostream>

using namespace status;

namespace engine{

	LoadMap::LoadMap (const std::string& file_name)
	{
		this->file_name = file_name;
	}
	
	LoadMap::~LoadMap()
	{
	
	}
	
	CommandTypeID LoadMap::getTypeID () const
	{
		return LOAD;
	}
	void LoadMap::execute (std::stack<Action*>& actions, status::State* state)
	{
		state->initialisation(file_name);
		std::cout << "Map loaded" << std::endl;
	}
        void LoadMap::serialize (Json::Value& out) const
        {
			out["LoadMap"]["file_name"] = this->file_name;
            
        }
        LoadMap* LoadMap::deserialize (const Json::Value& in)
        {
            this->file_name = in["LoadMap"]["file_name"];
        }
};  
