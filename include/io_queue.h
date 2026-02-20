/*
 * AstraHM Storage Engine
 *
 * IO Queue Module
 *
 * Provides a simple request queue to simulate
 * asynchronous disk IO processing.
 */

#ifndef IO_QUEUE_H
#define IO_QUEUE_H

void io_enqueue(int disk_id, int block);
void io_process_queue();
void io_start_worker();
void io_stop_worker();

#endif
