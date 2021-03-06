#ifndef SFVFS_COFING_H
#define SFVFS_COFING_H

#include <stdint.h>

/**
 * @brief 这是配置结构体, 用来确定文件格式
 * TODO: 有时需要解决字节序问题, 暂时未考虑
 */
struct sfvfs_options {
    uint32_t block_size;
    uint32_t block_count;
    uint32_t filename_length;
    uint32_t magic_number;
} __attribute__((__packed__));


/**
 * 文件系统中文件名的最大长度
 */
#define SFVFS_FILENAME_LENGTH 120

/**
 * 文件系统的最大深度
 */
#define SFVFS_MAX_DEPTH 64


#define SFVFS_BLOCK_SIZE (1024 * 8)


#define SFVFS_BLOCK_COUNT 128


#define SFVFS_MAGIC 0xe53fd196

/**
 * 初始化结构体
 */
#define SFVFS_OPTIONS_DEFAULT { \
    SFVFS_BLOCK_SIZE, /* block_size */ \
    SFVFS_BLOCK_COUNT, /* block_count */ \
    SFVFS_MAGIC, /* magic_number */ \
    SFVFS_FILENAME_LENGTH /* filename_length */ \
}








#endif /* end of include guard: SFVFS_COFING_H */
