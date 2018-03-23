#ifndef __FOAS_COMMON_TASK_H__
#define __FOAS_COMMON_TASK_H__


#include <mutex>
#include <chrono>
#include <thread>
#include <iostream>

#include <foas/common/TaskResult.h>


namespace foas {
  namespace common {
    class Task {
    private:
      enum class ExecutionState {
	NotStarted = 0,
	Running = 1,
	Finished = 2
      };
      
      std::function<void()> mFunction;
      std::thread mThread;
      ExecutionState mState;
      TaskResult mResult;
      std::mutex mRunningLock;
      
    public:
      Task(std::function<void()> function);
      ~Task();
      
      void Start();
      TaskResult Wait();

      static void Sleep(int milliSeconds);
    };
  }
}


#endif /* __FOAS_COMMON_TASK_H__ */
