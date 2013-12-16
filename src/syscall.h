
#ifndef LIBTIMERFD_SYSCALL_H
#define LIBTIMERFD_SYSCALL_H

#ifndef SYS_timerfd_create
#  define SYS_timerfd_create __NR_timerfd_create
#endif
#ifndef SYS_timerfd_gettime
#  define SYS_timerfd_gettime __NR_timerfd_gettime
#endif
#ifndef SYS_timerfd_settime
#  define SYS_timerfd_settime __NR_timerfd_settime
#endif

#ifndef __NR_timerfd_create
#  define __NR_timerfd_create 283
#endif
#ifndef __NR_timerfd_settime
#  define __NR_timerfd_settime 286
#endif
#ifndef __NR_timerfd_gettime
#  define __NR_timerfd_gettime 287
#endif

#endif

