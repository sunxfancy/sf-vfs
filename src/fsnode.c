
#include "sfvfs/fsnode.h"
#include "sfvfs/sfvfs.h"

static size_t block_2level_max = SFVFS_BLOCK_SIZE / 8;
static size_t block_base = 9;

extern int
sfvfs_fsnode_find_block(struct sfvfs_fs * sfs, struct sfvfs_fsnode * node, size_t k) {
    if (k < block_base) return node->data_list[k];
    if (k < block_2level_max + block_base) {
        size_t level2_id = node->data_list[k];
        size_t level2_k  = k - block_base;
        struct sfvfs_fimage* img = sfvfs_cread_block(sfs->cntr, level2_id);
        uint64_t* pData = (uint64_t*)(img->data);
        uint64_t ret = pData [level2_k];
        sfvfs_cwrite(sfs->cntr, img);
        return ret;
    }
    if (k < block_2level_max * block_2level_max + block_base) {
        size_t level2_id = node->data_list[k];
        size_t level2_k  = (k - block_base) / block_2level_max;

        struct sfvfs_fimage* img = sfvfs_cread_block(sfs->cntr, level2_id);
        uint64_t* pData = (uint64_t*)(img->data);

        size_t level3_id = pData [level2_k];
        size_t level3_k  = (k - block_base) % block_2level_max;

        sfvfs_cwrite(sfs->cntr, img);

        img = sfvfs_cread_block(sfs->cntr, level3_id);
        pData = (uint64_t*)(img->data);
        uint64_t ret = pData [level3_k];
        sfvfs_cwrite(sfs->cntr, img);
        return ret;
    }
    return 0;
}


extern int
sfvfs_fsnode_open(struct sfvfs_fs * sfs, struct sfvfs_fsnode * node) {

    return 0;
}

extern int
sfvfs_fsnode_close(struct sfvfs_fs * sfs, int fid) {

    return 0;
}
