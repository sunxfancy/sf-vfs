#ifndef SFVFS_FSNODE_H
#define SFVFS_FSNODE_H

#include <stdint.h>

struct sfvfs_fsnode {
    uint64_t id;
    uint64_t data_size;
    uint64_t mtime;
    uint64_t open_count;

    uint64_t data_list[16];
};





#endif /* end of include guard: SFVFS_FSNODE_H */
