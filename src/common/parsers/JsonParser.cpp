#include <foas/common/parsers/JsonParser.h>


namespace foas {
  namespace common {
    namespace parsers {
      JsonParser::JsonParser() {
      }
      
      JsonParser::~JsonParser() {
      }
      
      std::shared_ptr<Property> JsonParser::ParseString(std::string content) {
	std::shared_ptr<Property> property = nullptr;
	
	// ...

	return property;
      }
    }
  }
}
