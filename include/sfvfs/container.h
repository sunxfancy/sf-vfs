#ifndef SFVFS_CONTAINER_H
#define SFVFS_CONTAINER_H

struct sfvfs_container;

struct sfvfs_fimage {
    void* data;
    int pos;
    int lenght;
};


extern struct sfvfs_container*
sfvfs_copen (const char* filename, const char* mode);


extern void
sfvfs_cclose (struct sfvfs_container* cntr);


extern struct sfvfs_fimage*
sfvfs_cread (struct sfvfs_container* cntr, int pos, int length);


extern int
sfvfs_cwrite (struct sfvfs_container* cntr, struct sfvfs_fimage* image);





#endif /* end of include guard: SFVFS_CONTAINER_H */
