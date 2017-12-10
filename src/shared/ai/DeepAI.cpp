/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DeepAI.h"
#include <limits>

namespace ai{
    DeepAI::DeepAI (status::State* state)
    {
        this->buildings_map.resize(2);
        this->units_map.resize(2);        
    }
    int DeepAI::minmax_rec_max (engine::Engine* engine, Direction& bestdir, int depth)
    {
        if (depth <= 0) return 0;
        
        int max_val = std::numeric_limits<int>::max();
        
        return max_val;
    }
    int DeepAI::minmax_rec_min (engine::Engine* engine, Direction& bestdir, int depth)
    {
        if (depth <= 0) return 0;
        
        int min_val = std::numeric_limits<int>::max();
        
        return min_val;
        
    }
    void DeepAI::run (engine::Engine* engine)
    {
        
    }
    int DeepAI::getMaxDepth() const
    {
        return this->maxDepth;
    }
    void DeepAI::setMaxDepth(int maxDepth)
    {
        this->maxDepth = maxDepth;
    }
    
};