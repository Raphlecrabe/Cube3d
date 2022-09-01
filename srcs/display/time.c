#include "../../incs/time.h"

t_time	gettime(void)
{
	struct timeval	tv;
	t_time			time;

	time.sec = -1;
	time.usec = -1;
	if (gettimeofday(&tv, NULL) == -1)
		return (time);
	time.sec = tv.tv_sec;
	time.usec = tv.tv_usec;
	return (time);
}

long int	getTimeSinceStarted(t_time startTime)
{
	struct timeval	tv;
	long int	time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = (tv.tv_usec - startTime.usec) / 1000
		+ ((tv.tv_sec - startTime.sec) * 1000);
	return (time);
}