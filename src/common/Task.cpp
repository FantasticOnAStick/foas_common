#include <foas/common/Task.h>


namespace foas {
  namespace common {
    Task::Task() {
    }

    Task::~Task() {
    }
    
    void Task::Start() {
    }
    
    TaskResult Task::Wait() {
      TaskResult result;
      
      result.Status = Success;
      
      return result;
    }
  }
}
