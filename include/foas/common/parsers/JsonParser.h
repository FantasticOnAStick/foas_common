#ifndef __FOAS_COMMON_PARSERS_JSONPARSER_H__
#define __FOAS_COMMON_PARSERS_JSONPARSER_H__


#include <json.h>

#include <foas/common/parsers/Parser.h>


namespace foas {
  namespace common {
    namespace parsers {
      class JsonParser : public Parser {
      public:
	JsonParser();
	~JsonParser();

	virtual std::shared_ptr<Property> ParseString(std::string content) override;
      };
    }
  }
}


#endif /* __FOAS_COMMON_PARSERS_JSONPARSER_H__ */
