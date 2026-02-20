/*
 * AstraHM Storage Engine
 *
 * Checksum Module
 *
 * Detects silent data corruption.
 */

#include "checksum.h"

/* simple checksum algorithm */
unsigned int checksum_generate(int block) {
  return (block * 2654435761u) ^ (block << 5);
}

/* verify block integrity */
int checksum_verify(int block, unsigned int checksum) {
  return checksum_generate(block) == checksum;
}
