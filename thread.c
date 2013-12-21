#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void*
threadfunc(void* dummy)
{
	while(1) {
		printf(".\n");
		sleep(1);
	}
}

static pthread_t thread;

void
StartThread()
{
	pthread_create(&thread, NULL, &threadfunc, NULL);
}

int
CancelThread()
{
	void *r;
	pthread_cancel(thread);
	pthread_join(thread, &r);
	return (r == PTHREAD_CANCELED);
}
