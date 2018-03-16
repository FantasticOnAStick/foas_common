#include <foas/common/Property.h>


namespace foas {
  namespace common {
    Property::Property(std::string content) {
      *this = content;
    }
    
    Property::Property(double content) {
      *this = content;
    }
    
    Property::Property(float content) {
      *this = content;
    }
    
    Property::Property(int content) {
      *this = content;
    }
    
    Property::Property(bool content) {
      *this = content;
    }
    
    Property::~Property() {
    }
    
    Property::Type Property::GetType() {
      return mType;
    }
    
    void Property::operator=(std::string content) {
      mType = Atom;
      this->Set<std::string>(content);
    }
    
    void Property::operator=(double content) {
      mType = Atom;
      this->Set<double>(content);
    }
    
    void Property::operator=(float content) {
      mType = Atom;
      this->Set<double>(content);
    }
    
    void Property::operator=(int content) {
      mType = Atom;
      this->Set<int>(content);
    }
    
    void Property::operator=(bool content) {
      mType = Atom;
      this->Set<bool>(content);
    }
    
    std::shared_ptr<Property>& Property::operator[](int index) {
      mType = List;
      
      if(mList.size() <= index) {
	throw std::exception();
      }

      std::list<std::shared_ptr<Property>>::iterator it = mList.begin();
      std::advance(it, index);
      
      return *it;
    }
    
    std::shared_ptr<Property>& Property::operator[](std::string key) {
      mType = Dictionary;
      
      return mDictionary[key];
    }
    
    void Property::Add(std::shared_ptr<Property> property) {
      mType = List;
      mList.push_back(property);
    }
  }
}
