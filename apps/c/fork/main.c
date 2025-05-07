#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>



int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        sleep(2);
        exit(0);
    } else {
        printf("Parent process (PID: %d), waiting for child (PID: %d)\n", getpid(), pid);
        wait(NULL); // 等待子进程结束
        printf("Parent process exiting...\n");
    }
    return 0;
}
