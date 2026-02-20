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
 * Simulate writing a RAID stripe
 */
void stripe_write() {

  disk_t *d1 = dm_get_disk(1);
  disk_t *d2 = dm_get_disk(2);
  disk_t *d3 = dm_get_disk(3);
  disk_t *p_disk = dm_get_disk(4);
  disk_t *q_disk = dm_get_disk(5);
  int b1 = 11, b2 = 22, b3 = 33;

  int parity_p = b1 ^ b2 ^ b3;
  int parity_q = (b1 * 1) ^ (b2 * 2) ^ (b3 * 3);

  printf("\n--- Writing RAID Stripe ---\n");

  disk_write(d1, b1);
  disk_write(d2, b2);
  disk_write(d3, b3);
  disk_write(p_disk, parity_p);
  disk_write(q_disk, parity_q);

  printf("Stripe write complete\n");
}
