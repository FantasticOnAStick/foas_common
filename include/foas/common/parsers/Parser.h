#ifndef __FOAS_COMMON_PARSERS_PARSER_H__
#define __FOAS_COMMON_PARSERS_PARSER_H__


#include <iostream>
#include <memory>
#include <string>
#include <fstream>

#include <foas/common/Property.h>
#include <foas/common/FileSystem.h>


namespace foas {
  namespace common {
    namespace parsers {
      class Parser {
      public:
	Parser();
	~Parser();
	
	virtual std::shared_ptr<Property> ParseString(std::string content) = 0;
	std::shared_ptr<Property> ParseFile(std::string path);
      };
    }
  }
}


#endif /* __FOAS_COMMON_PARSERS_PARSER_H__ */
