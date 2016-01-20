#ifndef SFVFS_HEADER_H
#define SFVFS_HEADER_H

#include "sfvfs/config.h"


struct sfvfs_header {
    struct sfvfs_options option; /* 配置记录 */
    uint32_t version; /* 版本号 */
    uint16_t umask; /* 挂载文件权限掩码 */
    uint16_t dmast; /* 挂载目录权限掩码 */
    uint64_t block_count; /* block的数目 */
    uint64_t file_sum_size; /* 文件实际使用的总空间 */
    uint64_t block_sum_size; /* 文件系统真实占用的空间(不考虑空洞时) */
} __attribute__((__packed__));


/* 前向声明结构体 */
struct sfvfs_fs;


/**
 * @brief 读取当前文件系统的header
 * @method intsfvfs_read_header
 * @param  sfs                  文件系统指针
 * @param  header               文件头指针
 * @return                      成功返回0, 否则返回异常号
 */
extern int
sfvfs_read_header (struct sfvfs_fs * sfs, struct sfvfs_header * header);


/**
 * @brief 存储文件系统的header
 * @method intsfvfs_save_header
 * @param  sfs                  文件系统指针
 * @param  header               文件头指针
 * @return                      成功返回0, 否则返回异常号
 */
extern int
sfvfs_save_header (struct sfvfs_fs * sfs, struct sfvfs_header * header);



/**
 * @brief 将版本号转换为C风格字符串格式
 * @method voidsfvfs_version2string
 * @param  version                  版本号
 * @param  str                      储存数据的字符串数组
 */
extern void
sfvfs_version2string (int version, char str[16]);

/**
 * @brief 将字符串转换为版本号
 * @method uint32_tsfvfs_string2version
 * @param  str                          字符串数组
 * @return                              转换后的版本号，失败返回-1
 */
extern uint32_t
sfvfs_string2version (char str[16]);




#endif /* end of include guard: SFVFS_HEADER_H */
