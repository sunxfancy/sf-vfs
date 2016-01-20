#include "sfvfs/dir.h"

/**
 * @brief 为当前节点初始化一个仅有‘.’和‘..’的目录，或额外添加初始化后的节点
 * @method intsfvfs_create_dir_file
 * @param  inode                    要初始化目录的fsnode
 * @param  ptr                      要初始化的目录指针，为空时仅包含‘.’和‘..’
 * @return                          成功返回0，否则返回异常号
 */
extern int
sfvfs_create_dir_file (struct sfvfs_fsnode* inode, struct sfvfs_dir* ptr) {
    return 0;
}



/**
 * @brief 寻找对应目录下的文件名（包括目录）
 * @method uint64_tsfvfs_dir_find
 * @param  filename               文件名
 * @return                        对应的id，-1为不存在
 */
extern uint64_t
sfvfs_dir_find (const char* filename) {
    return 0;
}


/**
 * @brief 插入一个新的文件名节点
 * @method intsfvfs_dir_insert
 * @param  filename            新的文件名
 * @param  id                  id号
 * @return                     成功返回0，否则返回异常号
 */
extern int
sfvfs_dir_insert (const char* filename, uint64_t id) {
    return 0;
}


/**
 * @brief 删除一个目录
 * @method intsfvfs_dir_del
 * @param  filename         目录名
 * @return                  成功返回0，否则返回异常号
 */
extern int
sfvfs_dir_del (const char* filename) {
    return 0;
}
