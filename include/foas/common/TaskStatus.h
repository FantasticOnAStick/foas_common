#ifndef __FOAS_COMMON_TASKSTATUS_H__
#define __FOAS_COMMON_TASKSTATUS_H__


namespace foas {
  namespace common {
    typedef enum {
      Undefined = 0,
      Success = 1,
      Failed = 2
    } TaskStatus;
  }
}


#endif /* __FOAS_COMMON_TASKSTATUS_H__ */
