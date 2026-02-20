/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 *
 * Provides parity generation and recovery simulation.
 * Tracks block placement and storage mapping.
 *
 */
#include "metadata.h"
#include <stdio.h>

/*
 * Metadata service tracks block placement
 * and determines which disk stores data.
 */

void metadata_init() { printf("Metadata service initialized\n"); }

/*
 * Simple disk mapping logic
 * (round-robin simulation)
 */

void metadata_map_block(int block_id) {

  int disk = block_id % 5;

  printf("Block %d stored on Disk %d\n", block_id, disk);
}
