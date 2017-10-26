// Generated by dia2code
#ifndef STATUS__ELEMENT__H
#define STATUS__ELEMENT__H


#include "TypeID.h"

namespace status {

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  protected:
    TypeID type_id;
    // Operations
  public:
    Element (TypeID id);
    virtual ~Element ();
    virtual bool isStatic () const = 0;
    virtual void affiche () const = 0;
    // Setters and Getters
    TypeID getType_id() const;
    void setType_id(TypeID type_id);
  };

};

#endif