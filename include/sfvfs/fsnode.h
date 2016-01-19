#ifndef SFVFS_FSNODE_H
#define SFVFS_FSNODE_H

#include <stdint.h>

struct sfvfs_fsnode {
    uint64_t id;
    char filename[0];
};





#endif /* end of include guard: SFVFS_FSNODE_H */
