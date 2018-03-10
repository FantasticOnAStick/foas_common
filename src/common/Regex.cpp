#include <foas/common/Regex.h>


namespace foas {
  namespace common {
    Regex::Regex() {
    }

    Regex::~Regex() {
    }

    std::list<std::string> Regex::Match(std::string pattern, std::string content) {
      std::list<std::string> match;
      
      std::regex rgx(pattern, std::regex_constants::extended);
      auto rgx_begin = std::sregex_iterator(content.begin(), content.end(), rgx);
      auto rgx_end = std::sregex_iterator();
      
      for (std::sregex_iterator i = rgx_begin; i != rgx_end; ++i) {
	std::smatch m = *i;
	std::string m_str = m.str();
	
	match.push_back(m_str);
      }
      
      return match;
    }

    bool Regex::Matches(std::string pattern, std::string content) {
      return Regex::Match(pattern, content).size() > 0;
    }
  }
}
