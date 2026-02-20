#ifndef DISK_MANAGER_H
#define DISK_MANAGER_H

#include "disk.h"

#define MAX_DISKS 10

void dm_init();
disk_t *dm_get_disk(int id);

#endif
