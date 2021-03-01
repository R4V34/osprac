#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
	char* arr;
	int x;
	FILE* fo = fopen("writer.c", "r");
	char ch;
	key_t key;


	if ((key = ftok("writer.c", 0)) < 0)
    {
	    printf("Can not generate key\n");
	    exit(-1);
	}

	if ((x = shmget(key, 10000 * sizeof(char), 0666|IPC_CREAT)) < 0)
    {
	    printf("Can not create shared memory\n");
	    exit(-1);
	}

	if ((arr = (char*)shmat(x, NULL, 0)) == (char*)(-1)) {
		printf("Can not attach shared memory\n");
		exit(-1);
	}

	int i = 0;
	if (fo == NULL)
    {
		printf("Can not open file for reading\n");
		exit(-1);
	} else {
		while(!feof(fo)) {
			ch = getc(fo);
			msg[i] = ch;
			i++;
		}
	}
	arr[i - 1] = 0;

	printf("The message has been sent\n");

	if (x(arr) < 0)
    {
		printf("Can not detach shared memory\n");
		exit(-1);
	}

	printf("All fine\n");
	return 0;
}
