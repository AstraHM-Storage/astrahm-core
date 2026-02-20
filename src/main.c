/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */
#include "disk.h"
#include "disk_manager.h"
#include "logger.h"
#include "metadata.h"
#include "parallel_io.h"
#include "raid6.h"
#include "rebuild.h"
#include "stripe.h"
#include "thread_io.h"
#include <stdio.h>
int main() {
  printf("AstraHM Storage Engine Starting...\n");

  log_info("Storage engine boot sequence started");

  dm_init();

  // RAID engine
  raid6_init();
  raid6_encode();
  raid6_recover();
  raid6_layout();
  stripe_write();
  stripe_rebuild();
  parallel_write_demo();
  threaded_write_demo();

  // ========================
  // Disk abstraction layer
  // ========================
  // disk_t d1, d2, d3;
  //
  // disk_init(&d1, 1);
  // disk_init(&d2, 2);
  // disk_init(&d3, 3);
  //
  // disk_write(&d1, 101);
  // disk_write(&d2, 102);
  // disk_read(&d1, 101);
  //
  // disk_fail(&d2);
  // disk_write(&d2, 999); // should fail

  // ========================
  // Metadata mapping
  // ========================
  metadata_init();
  metadata_map_block(1);
  metadata_map_block(2);
  metadata_map_block(3);

  return 0;
}
