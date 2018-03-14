#include <foas/common/parsers/Parser.h>


namespace foas {
  namespace common {
    namespace parsers {
      Parser::Parser() {
      }
      
      Parser::~Parser() {
      }

      std::shared_ptr<Property> Parser::ParseFile(std::string path) {
	std::shared_ptr<Property> property = nullptr;
	
	if(FileSystem::GetPathType(path) == FileSystem::FileSystemEntryType::File) {
	  std::ifstream t(path);
	  t.seekg(0, std::ios::end);
	  size_t size = t.tellg();
	  std::string buffer(size, ' ');
	  t.seekg(0);
	  t.read(&buffer[0], size);
	  
	  property = this->ParseString(buffer);
	}
	
	return property;
      }
    }
  }
}
