/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */
#ifndef LOGGER_H
#define LOGGER_H

#define LOG_INFO 1
#define LOG_WARN 2
#define LOG_ERROR 3

void log_set_level(int level);

void log_info(const char *msg);
void log_warn(const char *msg);
void log_error(const char *msg);

#endif
