#include <foas/common/FileSystem.h>


namespace foas {
  namespace common {
    FileSystem::FileSystem() {
    }

    FileSystem::~FileSystem() {
    }

    std::string FileSystem::GetExecutablePath() {
      char buffer[1024];
      ssize_t sz = readlink("/proc/self/exe", buffer, 1024);

      if(sz == -1) {
	return "";
      } else {
	return std::string(buffer, sz);
      }
    }
    
    std::string FileSystem::GetExecutableDirectory() {
      std::string path = FileSystem::GetExecutablePath();
      
      if(path == "" || path.find_last_of('/') == std::string::npos) {
	return "./";
      } else {
	return path.substr(0, path.find_last_of('/') + 1);
      }
    }

    std::list<FileSystem::FileSystemEntry> FileSystem::GetDirectoryContents(std::string path) {
      std::list<FileSystemEntry> contents;
      
      DIR* d;
      struct dirent* dir;
      d = opendir(path.c_str());
      
      if(d) {
	while((dir = readdir(d)) != NULL) {
	  std::string entry = std::string(dir->d_name);
	  
	  if(entry != "." && entry != "..") {
	    FileSystemEntry fse;
	    fse.name = entry;
	    fse.type = FileSystem::GetPathType(path + "/" + entry);
	    
	    contents.push_back(fse);
	  }
	}
	
	closedir(d);
      }
      
      return contents;
    }

    FileSystem::FileSystemEntryType FileSystem::GetPathType(std::string path) {
      struct stat st;
      int s = stat(path.c_str(), &st);

      if(s != 0) {
	return FileSystemEntryType::Nonexistant;
      } else {
	if(S_ISREG(st.st_mode)) {
	  return FileSystemEntryType::File;
	} else if(S_ISDIR(st.st_mode)) {
	  return FileSystemEntryType::Directory;
	} else if(S_ISCHR(st.st_mode)) {
	  return FileSystemEntryType::CharacterDevice;
	} else if(S_ISBLK(st.st_mode)) {
	  return FileSystemEntryType::BlockDevice;
	} else if(S_ISFIFO(st.st_mode)) {
	  return FileSystemEntryType::FIFO;
	} else if(S_ISLNK(st.st_mode)) {
	  return FileSystemEntryType::Symlink;
	} else if(S_ISSOCK(st.st_mode)) {
	  return FileSystemEntryType::Socket;
	}
      }

      return FileSystemEntryType::Unknown;
    }
  }
}
