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
            out["type_command"] = "LoadMap";
            out["file_name"] = this->file_name;
            std::cout << "LoadMap serialize" << std::endl;
        }
        LoadMap* LoadMap::deserialize (const Json::Value& in)
        {
            LoadMap* load_map = new LoadMap(in["file_name"].asString());
            return load_map;
        }
};  
