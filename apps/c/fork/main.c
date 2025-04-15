// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// // #include <stdio.h>
// #include <sys/time.h>
// // #include <stdlib.h>
// #include <sys/mman.h>
// #include <fcntl.h>
// // #include <unistd.h>
// #include <string.h>
// #include <errno.h>
// void pan(){
//     return;
// }

// // void ppan(){
// //     return;
// // }

// // extern void ppan();

// int main() {
// //    pid_t pid;
//     pid_t pid2 = fork();
//     if(pid2<0){
//         perror("fail");
//         return 1;
//     }else if(pid2==0){
//  printf("----------------Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
// //  sleep(3);
//         int a=0;
//        for(int i=0;i<10;i++){
//             for(int j=0;j<220;j++){
//                 for(int k=0;k<10;k++){
//                     a++;
//                     // printf("a:%d",a);
//                 }
//             }
//         } 
//         printf("Chile process(PID:%d) exiting...\n",getpid());
//         exit(0);
//     }else{
//         //  pid_t pid = fork();
//     }
//     pid_t pid = fork();
//     // ppan();
//     // sleep(2);
//     // void *mapped_memory = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
//     // void *mapped_memory1 = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
//     if (pid < 0) {
//         perror("fork failed");
//         return 1;
//     } else if (pid == 0) {
//         // for(;;);
//         // 子进程
//         printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
//         // int a=0;
//         sleep(2);
//         // for(int i=0;i<100;i++){
//         //     for(int j=0;j<1000;j++){
//         //         for(int k=0;k<1000;k++){
//         //             a++;
//         //         }
//         //     }
//         // }
//         printf("Child process exiting...\n");
//         exit(0);
//     } else {
//         // 父进程
//         // ppan();
//         // sleep(3);
//         printf("Parent process (PID: %d), waiting for child (PID: %d)\n", getpid(), pid);
//         sleep(2);
// //  int a=0;
//     //    for(int i=0;i<100;i++){
//     //         for(int j=0;j<1000;j++){
//     //             for(int k=0;k<1000;k++){
//     //                 a++;
//     //             }
//     //         }
//     //     } 
//         wait(NULL); // 等待子进程结束
//         printf("114514");
//         wait(NULL);
//         // ppan();
//         printf("Parent process exiting...\n");
//     }

//     return 0;
// }

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
    // int a=0;
    // for(int i=0;i<10;i++){
    //     a++;
    // }
    return;
}

// void ppan(){
//     return;
// 

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        sleep(2);
        // pid_t cpid = fork();
        // if(cpid < 0){
        //     perror("fail");
        // }else if (cpid==0){
        //     printf("114514:start\n");
        //     sleep(2);
        //     exit(0);   
        // }else{
        //     printf("114514:wait\n");
        //     wait(NULL);
        // //     printf("114514:end wait\n");
        // for (size_t i = 0; i < 20000000; i++)
        // {
        //     for (size_t j = 0; j < 100000; j++)
        //     {
        //         /* code */

        //     }
            
        //     /* code */
        // }
        
            exit(0);
        // }
    } else {
        // 父进程
        // sleep(3);
        printf("Parent process (PID: %d), waiting for child (PID: %d)\n", getpid(), pid);
        // sleep(5);
        // while(1);
        // see_irq();
        wait(NULL); // 等待子进程结束
        printf("Parent process exiting...\n");
    }

    return 0;
}
