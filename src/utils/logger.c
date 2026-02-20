/*
 * AstraHM Storage Engine
 * Logging System with Timestamp Support
 */

#include "logger.h"
#include <stdio.h>
#include <time.h>

static void log_timestamp() {
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  printf("[%04d-%02d-%02d %02d:%02d:%02d] ", t->tm_year + 1900, t->tm_mon + 1,
         t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

  //  printf("[%04d-%02d-%02d %02d:%02d:%02d] ", t->tm_year + 1900, t->tm_mon +
  //  1,
  //       t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
}

void log_info(const char *msg) {
  log_timestamp();
  printf("\033[32m[INFO]\033[0m %s\n", msg);
}

void log_warn(const char *msg) {
  log_timestamp();
  printf("\033[33m[WARN]\033[0m %s\n", msg); // bold yellow
}

void log_error(const char *msg) {
  log_timestamp();
  printf("\033[31m[ERROR]\033[0m %s\n", msg); // bright red
}
