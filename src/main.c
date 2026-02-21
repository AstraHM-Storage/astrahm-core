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
#include <stdlib.h>
#include <string.h>
// #include <unistd.h>
int main() {

  /* Configure log level from environment */
  char *env = getenv("ASTRAHM_LOG");

  //  printf("ENV=%s\n", env);

  if (env && strcmp(env, "warn") == 0) {
    log_set_level(LOG_WARN);
  } else if (env && strcmp(env, "error") == 0) {
    log_set_level(LOG_ERROR);
  } else {
    log_set_level(LOG_INFO); // default
  }

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
  // log_info("INFO test");
  // log_warn("WARN test");
  // log_error("ERROR test");

  log_info("Storage engine run complete");

  printf("\n--- Async Worker Demo ---\n");

  io_enqueue(1, 501);
  io_enqueue(2, 502);
  io_enqueue(3, 503);

  printf("Engine continues working...\n");

  // ========================
  // Metadata mapping
  // ========================
  printf("\n--- METADATA SERVICE ---\n");

  metadata_init();
  metadata_map_block(1);
  metadata_map_block(2);
  metadata_map_block(3);

  printf("\n--- DISK READ VERIFICATION ---\n");

  disk_t *verify_disk = dm_get_disk(1);
  disk_read(verify_disk, 0);

  io_stop_worker();

  return 0;
}
