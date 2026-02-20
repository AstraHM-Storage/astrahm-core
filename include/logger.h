/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */
#ifndef LOGGER_H
#define LOGGER_H

typedef enum { LOG_INFO = 1, LOG_WARN = 2, LOG_ERROR = 3 } log_level_t;

void log_set_level(log_level_t level);

void log_info(const char *msg);
void log_warn(const char *msg);
void log_error(const char *msg);
// void log_info(const char *message);

#endif
