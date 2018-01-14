#ifndef __FOAS_COMMON_TASKRESULT_H__
#define __FOAS_COMMON_TASKRESULT_H__


#include <foas/common/TaskStatus.h>


namespace foas {
  namespace common {
    typedef struct TaskResult_ {
      TaskStatus Status;
    } TaskResult;
  }
}


#endif /* __FOAS_COMMON_TASKRESULT_H__ */
