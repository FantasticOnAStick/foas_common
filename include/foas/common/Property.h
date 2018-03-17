#ifndef __FOAS_COMMON_PROPERTY_H__
#define __FOAS_COMMON_PROPERTY_H__


#include <string>
#include <list>
#include <map>
#include <memory>

#include <foas/common/PropertyContent.h>
#include <foas/common/TypedPropertyContent.hpp>


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
      std::list<std::shared_ptr<Property>> mList;
      std::map<std::string, std::shared_ptr<Property>> mDictionary;
      
      std::shared_ptr<PropertyContent> mContent;
      
    public:
      Property(std::string content = "");
      Property(double content);
      Property(float content);
      Property(int content);
      Property(bool content);
      ~Property();
      
      Type GetType();
      
      void operator=(std::string content);
      void operator=(double content);
      void operator=(float content);
      void operator=(int content);
      void operator=(bool content);
      
      std::shared_ptr<Property>& operator[](int index);
      std::shared_ptr<Property>& operator[](std::string key);
      
      void Add(std::shared_ptr<Property> property);
      
      std::shared_ptr<Property>& Get(std::string key);
      std::shared_ptr<Property>& Get(int index);

      size_t Size();
      
      template<typename TDataType>
	void Set(TDataType content) {
	mContent = std::make_shared<TypedPropertyContent<TDataType>>(content);
      }
      
      template<typename TDataType>
	TDataType Get() {
	TDataType returnValue = TDataType();
	
	if(mType == Atom) {
	  std::shared_ptr<TypedPropertyContent<TDataType>> tpc = std::dynamic_pointer_cast<TypedPropertyContent<TDataType>>(mContent);
	  
	  if(tpc) {
	    returnValue = tpc->Get();
	  }
	}
	
	return returnValue;
      }
    };
  }
}


#endif /* __FOAS_COMMON_PROPERTY_H__ */
