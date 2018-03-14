#include <foas/common/parsers/JsonParser.h>


namespace foas {
  namespace common {
    namespace parsers {
      JsonParser::JsonParser() {
      }
      
      JsonParser::~JsonParser() {
      }
      
      std::shared_ptr<Property> JsonParser::ParseString(std::string content) {
	return this->ConvertJsonObject(json_tokener_parse(content.c_str()));
      }
      
      std::shared_ptr<Property> JsonParser::ConvertJsonObject(json_object* jobj) {
	std::shared_ptr<Property> property = nullptr;
	
	if(jobj) {
	  enum json_type type = json_object_get_type(jobj);

	  switch (type) {
	  case json_type_null: {
	    printf("json_type_nulln");
	  } break;
	    
	  case json_type_boolean: {
	    printf("json_type_booleann");
	  } break;
	    
	  case json_type_double: {
	    printf("json_type_doublen");
	  } break;
	    
	  case json_type_int: {
	    printf("json_type_intn");
	  } break;
	    
	  case json_type_object: {
	    json_object_object_foreach(jobj, key, val) {
	      std::shared_ptr<Property> subProperty = this->ConvertJsonObject(val);
	      
	      // ...
	    }
	  } break;
	    
	  case json_type_array: {
	    printf("json_type_arrayn");
	  } break;
	    
	  case json_type_string: {
	    printf("json_type_stringn");
	  } break;
	  }
	}
	
	return property;
      }
    }
  }
}
