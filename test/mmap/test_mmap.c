#include <stdio.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <sys/mman.h>
#include <string.h>

const char str[] = "Hello World";

int main(int argc, char const *argv[]) {
    char* memory;
    int file_len = strlen(str);
    int fd = open( "hello.txt" , O_RDWR | O_CREAT );
    memory = mmap(NULL, file_len+1, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%p\n", memory);
    if (memory == (void*)-1) {
        printf("映射错误\n");
        return -1;
    }
    strncpy( memory, str, file_len );
    munmap( memory, file_len+1 );
    close( fd );
    return 0;
}
