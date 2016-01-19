#include "sfvfs/sfvfs.h"


/**
 * @brief 打开一个文件系统
 * @method sfvfs_openfs
 * @param  filename     要打开的文件的名字
 * @param  options      选项结构体
 * @return              文件系统结构体
 */
extern struct sfvfs_fs*
sfvfs_openfs (const char* filename, struct sfvfs_options* options) {

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

}



/**
 * @brief 打开一个文件指针
 * @method sfvfs_fopen
 * @param  fs          文件系统指针
 * @param  filepath    文件在内部文件系统中的路径
 * @param  mode        打开选项, 类似fopen
 * @return             返回一个文件指针
 */
extern FILE*
sfvfs_fopen (struct sfvfs_fs* fs, const char* filepath, const char* mode) {

}
