#ifndef SFVFS_DIR_H
#define SFVFS_DIR_H

#include "sfvfs/config.h"

struct sfvfs_item {
    uint64_t id;
    char filename[SFVFS_FILENAME_LENGTH]; /* 文件名数组 */
};





#endif /* end of include guard: SFVFS_DIR_H */
