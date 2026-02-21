#include "disk.h"
#include "checksum.h"
#include "disk_health.h"
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
  d->error_count = 0;
  d->offline_events = 0;
  d->checksum_failures = 0;
  d->health_score = 100;
  d->isolated = 0;
}

/*
 * Simulate write operation
 */
void disk_write(disk_t *d, int block) {

  if (!d->online || d->isolated) {
    char msg[64];
    sprintf(msg, "Disk %d unavailable — write blocked", d->id);
    log_warn(msg);
    //
    //    char msg[64];
    //    sprintf(msg, "Disk %d OFFLINE — write failed", d->id);
    //    log_warn(msg);

    d->error_count++;
    d->offline_events++;
    // d->isolated = 0;
    disk_update_health(d);
    d->health_score -= 10;
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
    char msg[64];
    sprintf(msg, "Disk %d OFFLINE — write failed", d->id);
    log_warn(msg);

    d->error_count++;
    d->checksum_failures++;
    disk_update_health(d);
    d->health_score -= 10;
    return;
  }

  if (!checksum_verify(d->block, d->checksum)) {
    char buffer[64];
    sprintf(buffer, "Data corruption detected on Disk %d", d->id);
    log_error(buffer);
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
