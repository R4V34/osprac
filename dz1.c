#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	printf("Uid: %d. Gid: %d\n", (int)getuid(), (int)getgid());
}

