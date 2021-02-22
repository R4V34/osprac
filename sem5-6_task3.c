#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
	int array[2];
    size_t size = 1;
	int result = 0;
    char* resstring = malloc(sizeof(char));

    if(pipe(array) < 0) {
        printf("create pipe error\n");
        exit(-1);
    }
    fcntl(array[1], F_SETFL, fcntl(array[1], F_GETFL) | O_NONBLOCK);
    while (size == 1) {
        size = write(array[1], resstring, 1);
        result++;
    }

    printf("size %d\n", result);
    return 0;
}
