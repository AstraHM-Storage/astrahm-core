/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */

#include "logger.h"
#include <stdio.h>

/*
 * Basic logging system
 */

void log_info(const char *message) { printf("[INFO] %s\n", message); }
