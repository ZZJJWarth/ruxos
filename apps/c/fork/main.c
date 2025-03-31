#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// #include <stdio.h>
#include <sys/time.h>
// #include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
// #include <unistd.h>
#include <string.h>
#include <errno.h>
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
    // void *mapped_memory = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    // void *mapped_memory1 = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // for(;;);
        // 子进程
        printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        int a=0;
        sleep(2);
        // for(int i=0;i<100;i++){
        //     for(int j=0;j<1000;j++){
        //         for(int k=0;k<1000;k++){
        //             a++;
        //         }
        //     }
        // }
        printf("Child process exiting...\n");
        exit(0);
    } else {
        // 父进程
        // ppan();
        // sleep(2);
        printf("Parent process (PID: %d), waiting for child (PID: %d)\n", getpid(), pid);
        // sleep(10);
        wait(NULL); // 等待子进程结束
        ppan();
        printf("Parent process exiting...\n");
    }

    return 0;
}
