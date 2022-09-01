#ifndef TIME_H
# define TIME_H

# include <unistd.h>
# include <sys/time.h>

typedef struct	s_time
{
	int	sec;
	int	usec;
}				t_time;

t_time	gettime(void);
long int	getTimeSinceStarted(t_time startTime);

#endif