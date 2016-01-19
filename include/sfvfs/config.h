#ifndef SFVFS_COFING_H
#define SFVFS_COFING_H

#include <stdint.h>

/**
 * @brief 这是配置结构体, 用来确定文件格式
 * TODO: 有时需要解决字节序问题, 暂时未考虑
 */
struct sfvfs_options {
    uint32_t magic_number;
    uint32_t block_size;
    uint32_t block_count;
    uint32_t filename_length;
};

#define SFVFS_OPTIONS_DEFAULT { \
    0xe53fd196, /* magic_number */ \
    1024 * 8, /* block_size */ \
    128, /* block_count */ \
    120 /* filename_length */ \
}



#endif /* end of include guard: SFVFS_COFING_H */
