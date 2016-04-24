#ifndef SFVFS_CONTAINER_H
#define SFVFS_CONTAINER_H

#include <stdio.h>


struct sfvfs_container;

/**
 * 一个段文件在内存中的映射
 */
struct sfvfs_fimage {
    void* data;
    int pos;  /* 在文件中的位置 */
    int length; /* 长度 */
};


extern struct sfvfs_container*
sfvfs_copen (const char* filename);


extern void
sfvfs_cclose (struct sfvfs_container* cntr);

extern int
sfvfs_size (struct sfvfs_container* cntr);


extern struct sfvfs_fimage*
sfvfs_cread (struct sfvfs_container* cntr, int pos, int length);


extern int
sfvfs_cwrite (struct sfvfs_container* cntr, struct sfvfs_fimage* image);


extern struct sfvfs_fimage*
sfvfs_cread_block (struct sfvfs_container* cntr, int block_id);


extern int
sfvfs_resize (struct sfvfs_container* cntr, int size);

/**
 * @brief 打开一个文件指针
 * @method sfvfs_fopen
 * @param  ctr         文件系统容器指针
 * @param  filepath    文件在内部文件系统中的路径
 * @return             返回一个文件指针
 */
extern int
sfvfs_fopen (struct sfvfs_container* ctr, const char* filepath);





#endif /* end of include guard: SFVFS_CONTAINER_H */
