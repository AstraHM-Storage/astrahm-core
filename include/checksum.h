/*
 * AstraHM Storage Engine
 *
 * Checksum Module
 *
 * Provides simple checksum generation
 * for data integrity verification.
 */

#ifndef CHECKSUM_H
#define CHECKSUM_H

unsigned int checksum_generate(int block);
int checksum_verify(int block, unsigned int checksum);

#endif
