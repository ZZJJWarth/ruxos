#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // 子进程
        printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        sleep(2); // 模拟子进程运行
        printf("Child process exiting...\n");
        exit(0);
    } else {
        // 父进程
        printf("Parent process (PID: %d), waiting for child (PID: %d)\n", getpid(), pid);
        wait(NULL); // 等待子进程结束
        printf("Parent process exiting...\n");
    }

    return 0;
}
