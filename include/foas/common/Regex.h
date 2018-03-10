#ifndef __FOAS_COMMON_REGEX_H__
#define __FOAS_COMMON_REGEX_H__


#include <iostream>
#include <string>
#include <list>
#include <regex>


namespace foas {
  namespace common {
    class Regex {
    public:
      Regex();
      ~Regex();
      
      static std::list<std::string> Match(std::string pattern, std::string content);
      static bool Matches(std::string pattern, std::string content);
    };
  }
}


#endif /* __FOAS_COMMON_REGEX_H__ */
