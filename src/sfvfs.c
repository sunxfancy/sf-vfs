#include "sfvfs/sfvfs.h"
#include <stdlib.h>

/**
 * @brief 打开一个文件系统
 * @method sfvfs_openfs
 * @param  filename     要打开的文件的名字
 * @param  options      选项结构体
 * @return              文件系统结构体
 */
extern struct sfvfs_fs*
sfvfs_openfs (const char* filename, struct sfvfs_options* options) {
    struct sfvfs_fs* sfs;
    sfs = (struct sfvfs_fs*) malloc(sizeof(struct sfvfs_fs));
    sfs->cntr = sfvfs_copen(filename);
    sfs->options = options;

    if (sfvfs_size(sfs->cntr) == 0) { // 对于刚刚创建的文件系统,需要初始化
        sfvfs_resize(sfs->cntr, sizeof(struct sfvfs_header));
        sfvfs_init_header(sfs);
        printf("sfvfs header init done\n");
    } else {
        sfs->header = sfvfs_read_header(sfs, NULL);
        printf("sfvfs header found\n");

    }
    return sfs;
}


/**
 * @brief 关闭文件系统
 * @method voidsfvfs_closefs
 * @param  sfs               文件系统指针
 */
extern void
sfvfs_closefs (struct sfvfs_fs* sfs) {
    sfvfs_save_header(sfs, NULL);
    sfvfs_cclose(sfs->cntr);
    free(sfs);
}





/**
 * @brief 新建一个文件系统的容器文件
 * @method intsfvfs_makefile
 * @param  filename          文件名
 * @param  options           选项结构体
 * @return                   成功返回0, 否则返回异常号
 */
extern int
sfvfs_makefile (const char* filename, struct sfvfs_options* options) {
    struct sfvfs_fs* sfs;
    sfs = sfvfs_openfs(filename, options);
    sfvfs_closefs(sfs);
    return 0;
}
