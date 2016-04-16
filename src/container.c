#include "sfvfs/container.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <sys/mman.h>

struct sfvfs_container {
    int fd;
    const char* filepath;
};


extern struct sfvfs_container*
sfvfs_copen (const char* filename, const char* mode) {
    struct sfvfs_container* ctr;
    ctr = (struct sfvfs_container*) malloc(sizeof(struct sfvfs_container));
    ctr->filepath = NULL;
    sfvfs_fopen(ctr, filename, mode);
    return ctr;
}


extern void
sfvfs_cclose (struct sfvfs_container* cntr) {
    if (!cntr) return;
    close(cntr->fd);
    if (cntr->filepath) free((void*)(cntr->filepath));
    free(cntr);
}


extern struct sfvfs_fimage*
sfvfs_cread (struct sfvfs_container* cntr, int pos, int length) {
    struct sfvfs_fimage* fimg;
    fimg = (struct sfvfs_fimage*) malloc(sizeof(struct sfvfs_fimage));
    fimg->data = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, cntr->fd, pos);
    return fimg;
}


extern int
sfvfs_cwrite (struct sfvfs_container* cntr, struct sfvfs_fimage* image) {
    munmap(image->data, image->length);
    return 0;
}


/**
 * 复制字符串，返回一个新的malloc的字符串指针，注意之后要自己析构
 * @method cpystr
 * @param  str    原字符串
 * @return        新copy的字符串指针
 */
static char* cpystr(const char* str) {
    int len = strlen(str);
    char* path = calloc(sizeof(char), len+1);
    strncpy(path, str, len); path[len] = 0;
    return path;
}

/**
 * @brief 打开一个文件指针
 * @method sfvfs_fopen
 * @param  ctr         文件系统容器指针
 * @param  filepath    文件在内部文件系统中的路径
 * @param  mode        打开选项, 类似fopen
 * @return             返回一个文件指针
 */
extern int
sfvfs_fopen (struct sfvfs_container* ctr, const char* filepath, const char* mode) {
    ctr->fd = open(filepath, O_RDWR|O_CREAT|O_APPEND, 0666);
    if (ctr->fd == -1) return -1;
    ctr->filepath = cpystr(filepath);
    return ctr->fd;
}