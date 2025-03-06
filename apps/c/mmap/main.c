
// #include <stdio.h>
// #include <sys/time.h>
// #include <stdlib.h>
// #include <sys/mman.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>
// #include <errno.h>
// int main()
// {
//     size_t length = 4096;
//     void *addr=(void *)0xffffffc080200000;
//     // 使用 mmap 映射匿名内存
//     void *mapped_memory = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
//     void *mapped_memory1 = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
//     if (mapped_memory == MAP_FAILED) {
//         perror("mmap failed");
//         return 1;
//     }

//     printf("Memory mapped at address: %p\n", (int *)addr);

//     // char* i = ((char *)mapped_memory);
    
//     // 写入映射的内存
//     const char *message = "Hello, mmap!";
//     strcpy((char *)mapped_memory, message);
//     printf("Written to memory: %s\n", (char *)mapped_memory);

//     // 验证读取
//     printf("Read from memory: %s\n", (char *)mapped_memory);

//     // 使用 msync 刷新内存（如果需要）
//     if (msync(mapped_memory, length, MS_SYNC) == -1) {
//         perror("msync failed");
//     }

//     // 释放映射的内存
//     if (munmap(mapped_memory, length) == -1) {
//         perror("munmap failed");
//         return 1;
//     }

//     printf("Memory unmapped successfully.\n");
//     return 0;
//     struct timeval tv;
//     if (gettimeofday(&tv, NULL) != 0 ) {
//         perror("gettimeofday");
//         return -1;
//     }
    
//     printf("now time: %ld : %ld\n", tv.tv_sec,tv.tv_usec);

//     usleep(3000000);

//     if (gettimeofday(&tv, NULL) != 0 ) {
//         perror("gettimeofday");
//         return -1;
//     }

//     printf("now time: %ld : %ld\n", tv.tv_sec,tv.tv_usec);

//     struct timeval new_time;
//     new_time.tv_sec = 1731110400;
//     new_time.tv_usec = 0;

//     if (settimeofday(&new_time, NULL) != 0 ) {
//         perror("settimeofday");
//         return -1;
//     }
//     if (gettimeofday(&tv, NULL) != 0 ) {
//         perror("gettimeofday");
//         return -1;
//     }

//     printf("now time: %ld : %ld\n", tv.tv_sec,tv.tv_usec);
//     return 0;

// }
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 线程函数
void* print_message(void* ptr) {
    char* message;
    message = (char*) ptr;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    const char* message1 = "Thread 1";
    const char* message2 = "Thread 2";

    // 创建线程1
    int ret1 = pthread_create(&thread1, NULL, print_message, (void*) message1);
    if (ret1) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", ret1);
        exit(EXIT_FAILURE);
    }

    // 创建线程2
    int ret2 = pthread_create(&thread2, NULL, print_message, (void*) message2);
    if (ret2) {
        fprintf(stderr, "Error - pthread_create() return code: %d\n", ret2);
        exit(EXIT_FAILURE);
    }

    // 等待线程1结束
    pthread_join(thread1, NULL);
    // 等待线程2结束
    pthread_join(thread2, NULL);

    printf("Both threads have completed.\n");

    return 0;
}
