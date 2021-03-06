// Generated by dia2code
#ifndef STATUS__TRANSPORT__H
#define STATUS__TRANSPORT__H


namespace status {
  class Unit;
}

#include "TypeTransport.h"
#include "TEAM.h"
#include "Unit.h"

namespace status {

  /// class Transport - 
  class Transport : public status::Unit {
    // Associations
    // Attributes
  private:
    int maximumCharge;
    int onBoard;
    TypeTransport type_transport;
    // Operations
  public:
    Transport ();
    Transport (TypeTransport type_transport, TEAM team);
    ~Transport ();
    int getOnBoard () const;
    int getMaximumCharge () const;
    void setMaximumCharge (int charge);
    TypeTransport getType_transport () const;
    void setType_transport (TypeTransport type_transport);
    // Setters and Getters
  };

};

#endif
