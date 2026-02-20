/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */
#include "disk.h"
#include "disk_manager.h"
#include "io_queue.h"
#include "logger.h"
#include "metadata.h"
#include "parallel_io.h"
#include "raid6.h"
#include "rebuild.h"
#include "stripe.h"
#include "thread_io.h"
#include <stdio.h>
// #include <unistd.h>
int main() {
  printf("AstraHM Storage Engine Starting...\n");

  log_info("Storage engine boot sequence started");

  // RAID engine
  dm_init();
  io_start_worker();
  // RAID engine
  raid6_init();
  raid6_encode();
  raid6_recover();
  raid6_layout();
  stripe_write();
  stripe_rebuild();
  parallel_write_demo();
  threaded_write_demo();

  printf("\n--- Async Worker Demo ---\n");

  io_enqueue(1, 501);
  io_enqueue(2, 502);
  io_enqueue(3, 503);

  printf("Engine continues working...\n");

  // sleep(3); // allow worker to process

  // printf("\n--- Async IO Queue Demo ---\n");
  //
  // io_enqueue(1, 401);
  // io_enqueue(2, 402);
  // io_enqueue(3, 403);
  //
  // printf("Engine continues working while IO waits...\n");
  //
  // io_process_queue();

  // ========================
  // Metadata mapping
  // ========================
  metadata_init();
  metadata_map_block(1);
  metadata_map_block(2);
  metadata_map_block(3);

  io_stop_worker();

  return 0;
}
