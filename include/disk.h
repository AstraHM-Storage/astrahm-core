/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */

#ifndef DISK_H
#define DISK_H

/*
 * Disk abstraction layer
 * Simulates physical storage devices.
 */

typedef struct {
  int id;       // disk identifier
  int block;    // stored block value
  int online;   // disk status
  int checksum; // block checksum
  // unsigned int checksum; // block checksum
  int error_count;  // number of IO errors
  int health_score; // 100 = perfect, 0 = dead
  int offline_events;
  int checksum_failures;

} disk_t;

void disk_init(disk_t *d, int id);
void disk_write(disk_t *d, int block);
void disk_read(disk_t *d, int block);
void disk_fail(disk_t *d);

#endif
