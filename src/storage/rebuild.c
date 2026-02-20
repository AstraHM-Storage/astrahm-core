/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */

#include "disk.h"
#include "disk_manager.h"
#include <stdio.h>

/*
 * Simulate rebuilding a failed disk
 */
void stripe_rebuild() {
  disk_t *d2 = dm_get_disk(2);
  // disk_t *d1 = dm_get_disk(1);
  // disk_t *d2 = dm_get_disk(2);
  // disk_t *d3 = dm_get_disk(3);
  // disk_t *p_disk = dm_get_disk(4);

  int b1 = 11, b2 = 22, b3 = 33;

  int parity = b1 ^ b2 ^ b3;

  printf("\n--- DISK FAILURE & REBUILD ---\n");

  disk_fail(d2);

  printf("Reconstructing missing block...\n");

  int recovered = b1 ^ b3 ^ parity;

  printf("Recovered block: %d\n", recovered);

  printf("Writing recovered block to replacement disk...\n");

  disk_t replacement;
  disk_init(&replacement, 6);
  disk_write(&replacement, recovered);
  printf("Rebuild complete ✅\n");
}
