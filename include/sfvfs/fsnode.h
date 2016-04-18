#ifndef SFVFS_FSNODE_H
#define SFVFS_FSNODE_H

#include <stdint.h>
#include <stdlib.h>

struct sfvfs_fsnode {
    uint64_t id;
    uint64_t data_size; /* 实际的数据长度 */
    uint64_t block_size; /* 一共存放了多少块 */
    uint64_t mtime;
    uint64_t open_count;

    uint64_t data_list[11]; /* 存块号 */
};



struct sfvfs_fs;

extern int
sfvfs_fsnode_open(struct sfvfs_fs * sfs, struct sfvfs_fsnode * node);

extern int
sfvfs_fsnode_close(struct sfvfs_fs * sfs, int fid);

extern int
sfvfs_fsnode_find_block(struct sfvfs_fs * sfs, struct sfvfs_fsnode * node, size_t k);






#endif /* end of include guard: SFVFS_FSNODE_H */
