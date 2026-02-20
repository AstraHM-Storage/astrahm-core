/*
 * AstraHM Storage Engine
 *
 * Parallel IO Simulation Module
 *
 * Demonstrates multi-disk write behavior and
 * failure tolerance during parallel operations.
 */
#include "disk.h"
#include "disk_manager.h"
#include <stdio.h>

/*
 * Simulate parallel disk writes
 */
void parallel_write_demo() {

  printf("\n--- Parallel Disk Write Simulation ---\n");

  disk_t *d1 = dm_get_disk(1);
  disk_t *d2 = dm_get_disk(2);
  disk_t *d3 = dm_get_disk(3);

  printf("Writing blocks in parallel...\n");

  disk_write(d1, 201);
  disk_write(d2, 202);
  disk_write(d3, 203);

  printf("Parallel write complete\n");
}
