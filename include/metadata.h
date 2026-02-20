/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */

#ifndef METADATA_H
#define METADATA_H

/**
 * @brief Initialize metadata service.
 */
void metadata_init();

/**
 * @brief Map data block to disk.
 */
void metadata_map_block(int block_id);

#endif
