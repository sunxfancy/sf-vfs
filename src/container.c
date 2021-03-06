#include "sfvfs/container.h"
#include "sfvfs/config.h"
#include "sfvfs/header.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <sys/mman.h>
#include <sys/stat.h>


struct sfvfs_container {
    int fd;
    const char* filepath;
    size_t length;
    size_t block_number;
};


extern struct sfvfs_container*
sfvfs_copen (const char* filename) {
    struct sfvfs_container* ctr;
    ctr = (struct sfvfs_container*) malloc(sizeof(struct sfvfs_container));
    ctr->filepath = NULL;
    int ret = sfvfs_fopen(ctr, filename);
    if (ret == -1) { printf("open file failed!\n"); free(ctr); return NULL; }
    return ctr;
}


extern void
sfvfs_cclose (struct sfvfs_container* cntr) {
    if (!cntr) return;
    close(cntr->fd);
    if (cntr->filepath) free((void*)(cntr->filepath));
    free(cntr);
}


extern int
sfvfs_size (struct sfvfs_container* cntr) {
    struct stat st;
    int r = fstat(cntr->fd, &st);
    if (r == -1) return -1;
    cntr->length = st.st_size;
    return cntr->length;
}

extern struct sfvfs_fimage*
sfvfs_cread (struct sfvfs_container* cntr, int pos, int length) {
    if (pos+length > cntr->length) sfvfs_resize(cntr, pos+length);
    void* data = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, cntr->fd, pos);
    if (!data) { printf("mmap failed!\n"); return NULL; }

    struct sfvfs_fimage* fimg = (struct sfvfs_fimage*) malloc(sizeof(struct sfvfs_fimage));
    fimg->data = data;
    fimg->pos = pos;
    fimg->length = length;
    return fimg;
}

extern struct sfvfs_fimage*
sfvfs_cread_block (struct sfvfs_container* cntr, int block_id) {
    if (cntr->block_number < block_id) cntr->block_number = block_id;
    return sfvfs_cread(cntr, block_id * SFVFS_BLOCK_SIZE, SFVFS_BLOCK_SIZE);
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
sfvfs_fopen (struct sfvfs_container* ctr, const char* filepath) {
    ctr->fd = open(filepath, O_RDWR|O_CREAT, 0666);
    if (ctr->fd == -1) return -1;
    ctr->filepath = cpystr(filepath);
    return ctr->fd;
}


extern int
sfvfs_resize (struct sfvfs_container* cntr, int size) {
    int ret = ftruncate(cntr->fd, size);
    if (ret == -1) { printf("file resize failed!\n"); return -1; }
    cntr->length = size;
    return 0;
}
