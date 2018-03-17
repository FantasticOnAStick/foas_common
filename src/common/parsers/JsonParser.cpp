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
	std::shared_ptr<Property> property = std::make_shared<Property>();
	
	if(jobj) {
	  enum json_type type = json_object_get_type(jobj);
	  
	  switch (type) {
	  case json_type_null: {
	    property->Set<std::string>("");
	  } break;
	    
	  case json_type_boolean: {
	    bool value = json_object_get_boolean(jobj);
	    property->Set<bool>(value);
	  } break;
	    
	  case json_type_double: {
	    double value = json_object_get_double(jobj);
	    property->Set<double>(value);
	  } break;
	    
	  case json_type_int: {
	    int value = json_object_get_int(jobj);
	    property->Set<int>(value);
	  } break;
	    
	  case json_type_object: {
	    json_object_object_foreach(jobj, key, val) {
	      std::shared_ptr<Property> subProperty = this->ConvertJsonObject(val);
	      
	      (*property)[key] = subProperty;
	    }
	  } break;
	    
	  case json_type_array: {
	    int size = json_object_array_length(jobj);
	    
	    for(int i = 0; i < size; ++i) {
	      std::shared_ptr<Property> subProperty = this->ConvertJsonObject(json_object_array_get_idx(jobj, i));
	      
	      property->Add(subProperty);
	    }
	  } break;
	    
	  case json_type_string: {
	    std::string value = json_object_get_string(jobj);
	    property->Set<std::string>(value);
	  } break;
	  }
	}
	
	return property;
      }
    }
  }
}
