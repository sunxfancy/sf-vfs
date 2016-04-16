
#include "sfvfs/header.h"
#include "sfvfs/sfvfs.h"
#include <string.h>
#include <assert.h>

extern void
sfvfs_init_header (struct sfvfs_fs * sfs) {
    struct sfvfs_header* sh = sfvfs_read_header(sfs, NULL);
    assert(sfs->options != NULL);
    memcpy(&(sh->option), sfs->options, sizeof(struct sfvfs_options));
    sh->version = 1;
    sh->block_count = 0;

    sfs->header = sh;
}

/**
 * @brief 读取当前文件系统的header
 * @param  sfs                  文件系统指针
 * @param  header               文件头指针
 * @return                      成功返回0, 否则返回异常号
 */
extern struct sfvfs_header*
sfvfs_read_header (struct sfvfs_fs* sfs, struct sfvfs_header* header) {
    struct sfvfs_fimage* header_img = sfvfs_cread(sfs->cntr, 0, sizeof(struct sfvfs_header));
    sfs->header_fimg = header_img;
    sfs->header = (struct sfvfs_header*) (header_img->data);
    if (!header) return sfs->header;
    memcpy(header, header_img->data, sizeof(struct sfvfs_header));
    return header;
}


/**
 * @brief 存储文件系统的header
 * @param  sfs                  文件系统指针
 * @param  header               文件头指针
 * @return                      成功返回0, 否则返回异常号
 */
extern int
sfvfs_save_header (struct sfvfs_fs* sfs, struct sfvfs_header* header) {
    if (!header)
        sfvfs_cwrite(sfs->cntr, sfs->header_fimg);
    else {
        memcpy(sfs->header, header, sizeof(struct sfvfs_header));
        sfvfs_cwrite(sfs->cntr, sfs->header_fimg);
    }
    return 0;
}



/**
 * @brief 将版本号转换为C风格字符串格式
 * @method voidsfvfs_version2string
 * @param  version                  版本号
 * @param  str                      储存数据的字符串数组
 */
extern void
sfvfs_version2string (int version, char str[16]) {

}

/**
 * @brief 将字符串转换为版本号
 * @method uint32_tsfvfs_string2version
 * @param  str                          字符串数组
 * @return                              转换后的版本号，失败返回-1
 */
extern uint32_t
sfvfs_string2version (char str[16]) {

    return 0;
}
