/*
 * AstraHM Storage Engine
 *
 * IO Queue Module
 *
 * Simulates asynchronous IO by queueing requests
 * and processing them later.
 */

#include "disk.h"
#include "disk_manager.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_QUEUE 32

typedef struct {
  int disk_id;
  int block;
} io_request_t;

static io_request_t queue[MAX_QUEUE];
static int queue_size = 0;

static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static pthread_t worker;
static int running = 0;
// static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
// static pthread_t worker;
// static int running = 0;

/* Add request to queue */
void io_enqueue(int disk_id, int block) {
  pthread_mutex_lock(&lock);

  if (queue_size < MAX_QUEUE) {
    queue[queue_size].disk_id = disk_id;
    queue[queue_size].block = block;
    queue_size++;

    printf("Queued write: block %d -> Disk %d\n", block, disk_id);

    pthread_cond_signal(&cond); // wake worker
  }

  pthread_mutex_unlock(&lock);
}
// void io_enqueue(int disk_id, int block) {
//   if (queue_size >= MAX_QUEUE) {
//     printf("IO queue full\n");
//     return;
//   }
//
//   queue[queue_size].disk_id = disk_id;
//   queue[queue_size].block = block;
//   queue_size++;
//
//   printf("Queued write: block %d -> Disk %d\n", block, disk_id);
// }

/* worker thread */
void *worker_loop(void *arg) {
  (void)arg;

  pthread_mutex_lock(&lock);

  while (running) {

    while (queue_size == 0 && running) {
      pthread_cond_wait(&cond, &lock);
    }

    if (!running) {
      break;
    }

    printf("\n[Worker] Processing IO queue...\n");

    for (int i = 0; i < queue_size; i++) {
      disk_t *d = dm_get_disk(queue[i].disk_id);
      disk_write(d, queue[i].block);
    }

    queue_size = 0;
  }

  pthread_mutex_unlock(&lock);
  return NULL;
}
// void *worker_loop(void *arg) {
//   (void)arg;
//   while (running) {
//     pthread_mutex_lock(&lock);
//
//     if (queue_size > 0) {
//       printf("\n[Worker] Processing IO queue...\n");
//
//       for (int i = 0; i < queue_size; i++) {
//         disk_t *d = dm_get_disk(queue[i].disk_id);
//         disk_write(d, queue[i].block);
//       }
//
//       queue_size = 0;
//     }
//
//     pthread_mutex_unlock(&lock);
//
//     sleep(1); // simulate async processing interval
//   }
//   return NULL;
// }
//
/* start background worker */
void io_start_worker() {
  running = 1;
  pthread_create(&worker, NULL, worker_loop, NULL);
}

/* stop worker */
void io_stop_worker() {
  pthread_mutex_lock(&lock);
  running = 0;
  pthread_cond_signal(&cond); // wake worker to exit
  pthread_mutex_unlock(&lock);

  pthread_join(worker, NULL);
}
// void io_stop_worker() {
//   running = 0;
//   pthread_join(worker, NULL);
// }
//
/* Process queued requests */
void io_process_queue() {
  printf("\n--- Processing IO Queue ---\n");

  for (int i = 0; i < queue_size; i++) {
    disk_t *d = dm_get_disk(queue[i].disk_id);
    disk_write(d, queue[i].block);
  }

  queue_size = 0; // clear queue
}
