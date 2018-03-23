#ifndef __FOAS_COMMON_PROTECTED_HPP__
#define __FOAS_COMMON_PROTECTED_HPP__


#include <mutex>


namespace foas {
  namespace common {
    template<typename TDataType>
    class Protected {
    private:
      std::mutex mAccess;
      TDataType mData;
      
    public:
      Protected(TDataType data = TDataType()) {
	mData = data;
      }
      
      Protected() {
      }
      
      TDataType Get() {
	std::lock_guard<std::mutex> lock(mAccess);
	
	return mData;
      }
      
      void Set(TDataType data) {
	std::lock_guard<std::mutex> lock(mAccess);

	mData = data;
      }
      
      TDataType operator*() {
	return this->Get();
      }

      void operator=(TDataType data) {
	this->Set(data);
      }
      
      bool operator==(TDataType other) {
	return this->Get() == other;
      }
      
      bool operator==(Protected<TDataType> other) {
	return this->Get() == other.Get();
      }

      bool operator!=(TDataType other) {
	return !(*this == other);
      }
      
      bool operator!=(Protected<TDataType> other) {
	return !(*this == other);
      }
   };
  }
}


#endif /* __FOAS_COMMON_PROTECTED_HPP__ */
