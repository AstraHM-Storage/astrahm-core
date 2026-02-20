/*
 * AstraHM Storage Engine
 *
 * Threaded IO Module
 *
 * Performs concurrent disk writes using POSIX threads.
 */

#include "disk.h"
#include "disk_manager.h"
#include <pthread.h>
#include <stdio.h>

typedef struct {
  disk_t *disk;
  int block;
} io_task_t;

void *write_task(void *arg) {
  io_task_t *task = (io_task_t *)arg;
  disk_write(task->disk, task->block);
  return NULL;
}

void threaded_write_demo() {

  printf("\n--- THREADED PARALLEL WRITE ---\n");

  pthread_t t1, t2, t3;

  io_task_t task1 = {dm_get_disk(1), 301};
  io_task_t task2 = {dm_get_disk(2), 302};
  io_task_t task3 = {dm_get_disk(3), 303};

  pthread_create(&t1, NULL, write_task, &task1);
  pthread_create(&t2, NULL, write_task, &task2);
  pthread_create(&t3, NULL, write_task, &task3);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);

  printf("Threaded write complete\n");
}
