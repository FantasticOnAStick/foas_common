#include <foas/common/Task.h>


namespace foas {
  namespace common {
    Task::Task(std::function<void()> function) : mFunction(function), mState(ExecutionState::NotStarted) {
    }
    
    Task::~Task() {
    }
    
    void Task::Start() {
      try {
	std::lock_guard<std::mutex> lock(mRunningLock);
	
	mFunction();
      } catch(...) {
	mResult.Status = Failure;
      }
      
      mResult.Status = Success;
    }
    
    TaskResult Task::Wait() {
      std::lock_guard<std::mutex> lock(mRunningLock);

      if(mState == ExecutionState::NotStarted) {
	// Exception
      }
      
      return mResult;
    }
  }
}
