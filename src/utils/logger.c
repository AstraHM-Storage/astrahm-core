/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 *
 * Logging subsystem.
 * Provides runtime logging utilities.
 */

#include "logger.h"
#include <stdio.h>

/*
 * Basic logging system
 */

void log_info(const char *message) { printf("[INFO] %s\n", message); }
