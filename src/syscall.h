/*
 * Copyright (c) 2013-2014, Viveris Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file   syscall.h
 * @brief  Define identifiers for timerfd syscalls
 * @author Didier Barvaux <didier.barvaux@toulouse.viveris.com>
 */

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

