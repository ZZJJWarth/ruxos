
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main()
{
    size_t length = 4096;
    void *addr=(void *)0xffffffc080200000;
    // 使用 mmap 映射匿名内存
    void *mapped_memory = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    void *mapped_memory1 = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    printf("Memory mapped at address: %p\n", (int *)mapped_memory);

    // char* i = ((char *)mapped_memory);
    
    // 写入映射的内存
    const char *message = "Hello, mmap!";
    strcpy((char *)mapped_memory, message);
    printf("Written to memory: %s\n", (char *)mapped_memory);

    // 验证读取
    printf("Read from memory: %s\n", (char *)mapped_memory);

    // 使用 msync 刷新内存（如果需要）
    if (msync(mapped_memory, length, MS_SYNC) == -1) {
        perror("msync failed");
    }

    // 释放映射的内存
    if (munmap(mapped_memory, length) == -1) {
        perror("munmap failed");
        return 1;
    }

    printf("Memory unmapped successfully.\n");
    return 0;
}