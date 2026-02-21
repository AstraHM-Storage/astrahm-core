/*
 * AstraHM Storage Engine
 * Disk Health Monitoring & Scorin g
 */
#include "disk_health.h"
#include "disk.h"
#include "logger.h"
#include <stdio.h>

void disk_update_health(disk_t *d) {
  int score = 100 - (d->error_count * 5) - (d->offline_events * 10) -
              (d->checksum_failures * 15);

  if (score < 0)
    score = 0;

  d->health_score = score;
}

void disk_health_check(disk_t *d) {
  if (d->health_score < 40) {
    log_error("Disk health CRITICAL");
    //    disk_isolate(d);
  } else if (d->health_score < 60) {
    log_warn("Disk health DEGRADED");
  }
}

void disk_isolate(disk_t *d) {

  if (d->isolated)
    return;

  d->isolated = 1;

  char msg[80];
  sprintf(msg, "Disk %d isolated due to poor health", d->id);
  log_warn(msg);
}
//
// #include "disk_health.h"
// #include "logger.h"
//
// void disk_update_health(disk_t *d) {
//
//   int score = 100 - (d->error_count * 5) - (d->offline_events * 10) -
//               (d->checksum_failures * 15);
//
//   if (score < 0)
//     score = 0;
//
//   d->health_score = score;
//
//   if (score < 40) {
//     log_error("Disk health CRITICAL");
//   } else if (score < 60) {
//     log_warn("Disk health DEGRADED");
//   }
// }

// /*
//  * AstraHM Storage Engine
//  * Disk Health Monitoring & Scoring
//  */
//
// #include "disk.h"
// #include "logger.h"
//
// void disk_update_health(disk_t *d) {
//   if (d->error_count > 5)
//     d->health_score -= 20;
//
//   int score = 100 - (d->error_count * 5) - (d->offline_events * 10) -
//               (d->checksum_failures * 15);
//
//   if (score < 0)
//     score = 0;
//
//   d->health_score = score;
//
//   if (score < 40) {
//     log_error("Disk health CRITICAL");
//   } else if (score < 60) {
//     log_warn("Disk health DEGRADED");
//   }
// }
