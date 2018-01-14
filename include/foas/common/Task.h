#ifndef __FOAS_COMMON_TASK_H__
#define __FOAS_COMMON_TASK_H__


#include <foas/common/TaskResult.h>


namespace foas {
  namespace common {
    class Task {
    public:
      Task();
      ~Task();
      
      void Start();
      TaskResult Wait();
    };
  }
}


#endif /* __FOAS_COMMON_TASK_H__ */
