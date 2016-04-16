#ifndef SF_VFS_H
#define SF_VFS_H

#ifdef __cplusplus
extern "C"{
#endif

#include "sfvfs/config.h"
#include "sfvfs/container.h"


struct sfvfs_fs {
    struct sfvfs_container* cntr; /* 打开的文件容器 */



    struct sfvfs_options* options; /* 文件系统的配置选项 */

};


/**
 * @brief 打开一个文件系统
 * @method sfvfs_openfs
 * @param  filename     要打开的文件的名字
 * @param  options      选项结构体
 * @return              文件系统结构体
 */
extern struct sfvfs_fs*
sfvfs_openfs (const char* filename, struct sfvfs_options* options);


/**
 * @brief 关闭文件系统
 * @method voidsfvfs_closefs
 * @param  sfs               文件系统指针
 */
extern void
sfvfs_closefs (struct sfvfs_fs* sfs);



/**
 * @brief 新建一个文件系统的容器文件
 * @method intsfvfs_makefile
 * @param  filename          文件名
 * @param  options           选项结构体
 * @return                   成功返回0, 否则返回异常号
 */
extern int
sfvfs_makefile (const char* filename, struct sfvfs_options* options);









#ifdef __cplusplus
}
#endif

#endif /* end of include guard: SF_VFS_H */
