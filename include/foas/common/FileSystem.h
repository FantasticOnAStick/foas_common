#ifndef __FOAS_COMMON_FILESYSTEM_H__
#define __FOAS_COMMON_FILESYSTEM_H__


#include <string>
#include <list>

#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


namespace foas {
  namespace common {
    class FileSystem {
    public:
      enum class FileSystemEntryType {
	Unknown = 0,
	Nonexistant,
	File,
	Directory,
	Symlink,
	BlockDevice,
	CharacterDevice,
	FIFO,
	Socket
      };
      
      typedef struct {
	std::string name;
	FileSystemEntryType type;
      } FileSystemEntry;
      
    public:
      FileSystem();
      ~FileSystem();
      
      static std::string GetExecutablePath();
      static std::string GetExecutableDirectory();

      static std::list<FileSystemEntry> GetDirectoryContents(std::string path);

      static FileSystemEntryType GetPathType(std::string path);
      
      static bool PathExists(std::string path);

      static bool IsPathAbsolute(std::string path);
      static std::string GetAbsolutePath(std::string base, std::string path);
    };
  }
}


#endif /* __FOAS_COMMON_FILESYSTEM_H__ */
