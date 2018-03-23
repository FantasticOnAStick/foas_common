#include <foas/common/Task.h>


namespace foas {
  namespace common {
    Task::Task(std::function<void()> function) : mFunction(function), mState(ExecutionState::NotStarted) {
    }
    
    Task::~Task() {
    }
    
    void Task::Start() {
      try {
	//std::lock_guard<std::mutex> lock(mRunningLock);

	std::thread thread(mFunction);
	mThread.swap(thread);
	//mFunction();
      } catch(...) {
	std::cerr << "Exception in task" << std::endl;
	mResult.Status = Failure;
	
	throw;
      }
      
      mResult.Status = Success;
    }
    
    TaskResult Task::Wait() {
      /*std::lock_guard<std::mutex> lock(mRunningLock);
       */
      if(mState == ExecutionState::NotStarted) {
	// Exception
      }

      if(mThread.joinable()) {
	mThread.join();
      }
      
      return mResult;
    }

    void Task::Sleep(int milliSeconds) {
      std::this_thread::sleep_for(std::chrono::milliseconds(milliSeconds));
    }
  }
}
