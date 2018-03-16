#ifndef __FOAS_COMMON_TYPEDPROPERTYCONTENT_H__
#define __FOAS_COMMON_TYPEDPROPERTYCONTENT_H__


#include <foas/common/PropertyContent.h>


namespace foas {
  namespace common {
    template<typename TDataType>
    class TypedPropertyContent : public PropertyContent {
    private:
      TDataType mContent;
      
    public:
      TypedPropertyContent() {
      }

      TypedPropertyContent(TDataType content) : mContent(content) {
      }
      
      ~TypedPropertyContent() {
      }

      TDataType Get() {
	return mContent;
      }

      void operator=(TDataType content) {
	mContent = content;
      }
      
      void operator=(TDataType& content) {
	mContent = content;
      }
      
      void operator=(const TDataType& content) {
	mContent = content;
      }
    };
  }
}


#endif /* __FOAS_COMMON_TYPEDPROPERTYCONTENT_H__ */
