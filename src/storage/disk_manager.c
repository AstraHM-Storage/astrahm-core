#include "disk_manager.h"
#include "logger.h" // ✅ required for log_info()
#include <stdio.h>

static disk_t disks[MAX_DISKS];

/*
 * Initialize all disks
 */
void dm_init() {
  log_info("Initializing Disk Manager...");

  for (int i = 0; i < 5; i++) {
    disk_init(&disks[i], i + 1);

    char buffer[64];
    sprintf(buffer, "Disk %d initialized", disks[i].id);
    log_info(buffer);
  }
}
// void dm_init() {
//   char buffer[64];
//   sprintf(buffer, "Disk %d initialized", id);
//   log_info(buffer);
//   // printf("\nInitializing Disk Manager...\n");
//   //
//   // for (int i = 0; i < 5; i++) {
//   //   disk_init(&disks[i], i + 1);
//   // }
// }

/*
 * Retrieve disk by id
 */
disk_t *dm_get_disk(int id) {
  if (id < 1 || id > MAX_DISKS)
    return NULL;

  return &disks[id - 1];
}
