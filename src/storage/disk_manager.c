#include "disk_manager.h"
#include <stdio.h>

static disk_t disks[MAX_DISKS];

/*
 * Initialize all disks
 */
void dm_init() {
  printf("\nInitializing Disk Manager...\n");

  for (int i = 0; i < 5; i++) {
    disk_init(&disks[i], i + 1);
  }
}

/*
 * Retrieve disk by id
 */
disk_t *dm_get_disk(int id) {
  if (id < 1 || id > MAX_DISKS)
    return NULL;

  return &disks[id - 1];
}
