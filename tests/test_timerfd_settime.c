
#include <sys/timerfd.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct itimerspec old;
	struct itimerspec new;
	int fd;

	fd = timerfd_create(CLOCK_REALTIME, 0);
	if(fd < 0)
	{
		fprintf(stderr, "timerfd_create() failed: %s (%d)\n",
		        strerror(errno), errno);
		goto error;
	}

	/* bad fd */
	assert(timerfd_settime(-1, 0, &new, NULL) != 0 &&
	       (errno == EBADF || errno == EINVAL));
	/* bad pointer */
	assert(timerfd_settime(fd, 0, NULL, NULL) != 0 && errno == EFAULT);
	/* ok without old value */
	new.it_interval.tv_sec = 1;
	new.it_interval.tv_nsec = 3;
	new.it_value.tv_sec = 2;
	new.it_value.tv_nsec = 4;
	assert(timerfd_settime(fd, 0, &new, NULL) == 0);
	/* ok with old value */
	new.it_interval.tv_sec = 1;
	new.it_interval.tv_nsec = 3;
	new.it_value.tv_sec = 2;
	new.it_value.tv_nsec = 4;
	assert(timerfd_settime(fd, 0, &new, &old) == 0);
	/* ok, disarm */
	new.it_interval.tv_sec = 0;
	new.it_interval.tv_nsec = 0;
	new.it_value.tv_sec = 0;
	new.it_value.tv_nsec = 0;
	assert(timerfd_settime(fd, 0, &new, &old) == 0);

	close(fd);
	return 0;

error:
	return 1;
}

