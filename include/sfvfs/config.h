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

#define SFVFS_FILENAME_LENGTH 120

#define SFVFS_OPTIONS_DEFAULT { \
    1024 * 8, /* block_size */ \
    128, /* block_count */ \
    SFVFS_FILENAME_LENGTH /* filename_length */ \
    0xe53fd196, /* magic_number */ \
}








#endif /* end of include guard: SFVFS_COFING_H */
