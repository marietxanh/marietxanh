// Generated by dia2code
#ifndef CLIENT__CLIENT__H
#define CLIENT__CLIENT__H

#include <memory>
#include <mutex>

namespace engine {
  class Engine;
};
namespace ai {
  class Heuristique_AI;
};
namespace render {
  class Display;
}

#include "engine/Engine.h"
#include "ai/Heuristique_AI.h"
#include "render/Display.h"

namespace client {

  /// class Client - 
  class Client {
    // Associations
    // Attributes
  private:
    engine::Engine engine;
    std::unique_ptr<ai::Heuristique_AI> Heu_AI;
    mutable std::mutex draw_mutex;
    // Operations
  public:
    Client ();
    ~Client ();
    void engineUpdating ();
    void engineUpdated ();
    void run ();
    // Setters and Getters
  };

};

#endif