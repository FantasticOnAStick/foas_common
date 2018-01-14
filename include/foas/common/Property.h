#ifndef __FOAS_COMMON_PROPERTY_H__
#define __FOAS_COMMON_PROPERTY_H__


#include <string>
#include <list>
#include <map>


namespace foas {
  namespace common {
    class Property {
    public:
      typedef enum {
	List = 0,
	Dictionary = 1,
	Atom = 2
      } Type;
      
    private:
      Type mType;
      
    public:
      Property();
      ~Property();

      Type GetType();
    };
  }
}


#endif /* __FOAS_COMMON_PROPERTY_H__ */
