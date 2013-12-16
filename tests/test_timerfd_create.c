
#include <sys/timerfd.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

int main(int argc, char *argv[])
{
#ifdef CLOCK_REALTIME
	assert(timerfd_create(CLOCK_REALTIME, 0) >= 0);
#endif
#ifdef CLOCK_MONOTONIC
	assert(timerfd_create(CLOCK_MONOTONIC, 0) >= 0);
#endif
#if 0 /* privileges required */
#ifdef CLOCK_PROCESS_CPUTIME_ID
	assert(timerfd_create(CLOCK_PROCESS_CPUTIME_ID, 0) >= 0);
#endif
#ifdef CLOCK_THREAD_CPUTIME_ID
	assert(timerfd_create(CLOCK_THREAD_CPUTIME_ID, 0) >= 0);
#endif
#ifdef CLOCK_MONOTONIC_RAW
	assert(timerfd_create(CLOCK_MONOTONIC_RAW, 0) >= 0);
#endif
#ifdef CLOCK_REALTIME_COARSE
	assert(timerfd_create(CLOCK_REALTIME_COARSE, 0) >= 0);
#endif
#ifdef CLOCK_MONOTONIC_COARSE
	assert(timerfd_create(CLOCK_MONOTONIC_COARSE, 0) >= 0);
#endif
#ifdef CLOCK_BOOTTIME
	assert(timerfd_create(CLOCK_BOOTTIME, 0) >= 0);
#endif
#ifdef CLOCK_REALTIME_ALARM
	assert(timerfd_create(CLOCK_REALTIME_ALARM, 0) >= 0);
#endif
#ifdef CLOCK_BOOTTIME_ALARM
	assert(timerfd_create(CLOCK_BOOTTIME_ALARM, 0) >= 0);
#endif
#endif

	/* error cases */
	assert(timerfd_create(-1, 0) < 0 && errno == EINVAL);

	return 0;
}

