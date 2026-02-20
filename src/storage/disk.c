#include "disk.h"
#include <stdio.h>

/*
 * Initialize disk
 */
void disk_init(disk_t *d, int id) {
  d->id = id;
  d->online = 1;
  printf("Disk %d initialized\n", id);
}

/*
 * Simulate write operation
 */
void disk_write(disk_t *d, int block) {
  if (!d->online) {
    printf("Disk %d OFFLINE — write failed\n", d->id);
    return;
  }
  printf("Writing block %d -> Disk %d\n", block, d->id);
}

/*
 * Simulate read operation
 */
void disk_read(disk_t *d, int block) {
  if (!d->online) {
    printf("Disk %d OFFLINE — read failed\n", d->id);
    return;
  }
  printf("Reading block %d <- Disk %d\n", block, d->id);
}

/*
 * Simulate disk failure
 */
void disk_fail(disk_t *d) {
  d->online = 0;
  printf("Disk %d has FAILED\n", d->id);
}

//
// #include "disk.h"
// #include <stdio.h>
//
// /*
//  * Initialize disk
//  */
// void disk_init(disk_t *d, int id) {
//   d->id = id;
//   d->online = 1;
//   printf("Disk %d initialized\n", id);
// }
//
// /*
//  * Simulate write operation
//  */
// void disk_write(disk_t *d, int block) {
//   if (!d->online) {
//     printf("Disk %d OFFLINE — write failed\n", d->id);
//     return;
//   }
//   printf("Writing block %d -> Disk %d\n", block, d->id);
// }
//
// /*
//  * Simulate read operation
//  */
// void disk_read(disk_t *d, int block) {
//   if (!d->online) {
//     printf("Disk %d OFFLINE — read failed\n", d->id);
//     return;
//   }
//   printf("Reading block %d <- Disk %d\n", block, d->id);
// }
//
// /*
//  * Simulate disk failure
//  */
// void disk_fail(disk_t *d) {
//   d->online = 0;
//   printf("Disk %d has FAILED\n", d->id);
// }
//
// #include "disk.h"
// #include <stdio.h>
//
// /*
//  * Initialize disk
//  */
// void disk_init(disk_t *d, int id) {
//   d->id = id;
//   d->online = 1;
//   printf("Disk %d initialized\n", id);
// }
//
// /*
//  * Simulate write operation
//  */
// void disk_write(disk_t *d, int block) {
//   if (!d->online) {
//     printf("Disk %d OFFLINE — write failed\n", d->id);
//     return;
//   }
//   printf("Writing block %d -> Disk %d\n", block, d->id);
// }
//
// /*
//  * Simulate read operation
//  */
// void disk_read(disk_t *d, int block) {
//   if (!d->online) {
//     printf("Disk %d OFFLINE — read failed\n", d->id);
//     return;
//   }
//   printf("Reading block %d <- Disk %d\n", block, d->id);
// }
//
// /*
//  * Simulate disk failure
//  */
// void disk_fail(disk_t *d) {
//   d->online = 0;
//   printf("Disk %d has FAILED\n", d->id);
// }
