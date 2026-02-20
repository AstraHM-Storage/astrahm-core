/*
 * AstraHM Storage Engine
 * Copyright (c) 2026 AstraHM
 *
 * Author: Mohammad Javed
 * Description: RAID6 module implementation.
 */

#ifndef RAID6_H
#define RAID6_H

/**
 * @file raid6.h
 * @brief RAID-6 simulation interface for AstraHM storage engine.
 *
 * Provides initialization, parity generation,
 * recovery simulation, and stripe layout display.
 */

/**
 * @brief Initialize RAID6 engine.
 */
void raid6_init();

/**
 * @brief Generate RAID6 P and Q parity blocks.
 */
void raid6_encode();

/**
 * @brief Simulate disk failure recovery.
 */
void raid6_recover();

/**
 * @brief Display stripe layout across disks.
 */
void raid6_layout();

#endif
