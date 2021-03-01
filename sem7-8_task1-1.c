#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
	char *msg;
	int x;
	key_t key;

	if ((key = ftok("writer.c", 0)) < 0)
    {
	    printf("Can not create key\n");
	    exit(-1);
	}

	if ((x = shmget(key, 10000 * sizeof(char), 0666|IPC_CREAT)) < 0)
    {
	    printf("Can not create shared memory\n");
	    exit(-1);
	}

	if ((msg = (char*)shmat(x, NULL, 0)) == (char*)(-1))
	{
		printf("Can not attach shared memory\n");
		exit(-1);
	}

	printf("The message has been recieved: \n%s\n", msg);

	if (x(msg) < 0)
	{
		printf("Can not detach shared memory\n");
		exit(-1);
	}

	if (shmctl(x, 0, NULL) == -1)
    {
		printf("Can not delete shared memory\n");
		exit(-1);
	}

	printf("All fine\n");
	return 0;
}
