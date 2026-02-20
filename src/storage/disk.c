#include "disk.h"
#include "checksum.h"
#include "logger.h"
#include <stdio.h>

/*
 * Initialize disk
 */
void disk_init(disk_t *d, int id) {
  d->id = id;
  d->online = 1;
  d->block = 0;
  d->checksum = 0;

  //  printf("Disk %d initialized\n", id);
}

/*
 * Simulate write operation
 */
void disk_write(disk_t *d, int block) {
  if (!d->online) {
    char msg[64];
    sprintf(msg, "Disk %d OFFLINE — write failed", d->id);
    log_warn(msg);
    // char buffer[64];
    // sprintf(buffer, "Disk %d OFFLINE — write failed", d->id);
    // log_warn(buffer);

    //    printf("Disk %d OFFLINE — write failed\n", d->id);
    return;
  }

  d->block = block;
  d->checksum = checksum_generate(block);

  printf("Writing block %d -> Disk %d\n", block, d->id);
}

/*
 * Simulate read operation
 */
void disk_read(disk_t *d, int block) {
  (void)block; // explicitly mark unused

  if (!d->online) {
    printf("Disk %d OFFLINE — read failed\n", d->id);
    return;
  }

  if (!checksum_verify(d->block, d->checksum)) {
    char buffer[64];
    sprintf(buffer, "Data corruption detected on Disk %d", d->id);
    log_error(buffer);
    //    printf("⚠ DATA CORRUPTION detected on Disk %d!\n", d->id);
    return;
  }
  printf("Reading block %d <- Disk %d (integrity OK)\n", d->block, d->id);
}

/*
 * Simulate disk failure
 */
void disk_fail(disk_t *d) {
  d->online = 0;
  printf("Disk %d has FAILED\n", d->id);
}
