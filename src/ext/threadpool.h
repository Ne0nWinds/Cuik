#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct threadpool_t threadpool_t;
typedef void work_routine(void*);

typedef struct {
    work_routine* fn;
    void* arg;
} work_t;

threadpool_t* threadpool_create(size_t worker_count, size_t workqueue_size);
void threadpool_submit(threadpool_t* threadpool, work_routine fn, void* arg);
void threadpool_wait(threadpool_t* threadpool);
void threadpool_free(threadpool_t* threadpool);
