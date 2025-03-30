#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void pan(){
    return;
}

// void ppan(){
//     return;
// }

extern void ppan();

int main() {
    pid_t pid = fork();
    // ppan();
    // sleep(2);
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // 子进程
        printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        // sleep(2); // 模拟子进程运行
        printf("Child process exiting...\n");
        exit(0);
    } else {
        // 父进程
        // ppan();
        printf("Parent process (PID: %d), waiting for child (PID: %d)\n", getpid(), pid);
        // sleep(10);
        wait(NULL); // 等待子进程结束
        ppan();
        printf("Parent process exiting...\n");
    }

    return 0;
}
