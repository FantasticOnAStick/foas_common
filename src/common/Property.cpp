#include <foas/common/Property.h>


namespace foas {
  namespace common {
    Property::Property() {
    }
    
    Property::~Property() {
    }
    
    Property::Type Property::GetType() {
      return mType;
    }
  }
}
