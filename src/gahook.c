#include "gahook.h"

typedef struct block {
    size_t size;
    int free;
} block_t;

#define BLOCK_SIZE sizeof(block_t)

size_t page_size() {
    static size_t size = 0;
    if (size == 0)
        size = sysconf(_SC_PAGESIZE);
    return size;
}

size_t align(size_t size) {
    size_t alignment = sizeof(void*);
    return (size + alignment - 1) & ~(alignment - 1);
}

void *galloc(size_t size) {
    if (size == 0)
        return NULL;

    size = align(size);

    size_t total_size = size + BLOCK_SIZE;

    void *mem = mmap(
        NULL,
        total_size,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    if (mem == MAP_FAILED)
        return NULL;

    block_t *block = (block_t *)mem;
    block->size = size;
    block->free = 0;

    return (void *)(block + 1);
}

void gfree(void *ptr) {
    if (!ptr)
        return;

    block_t *block = (block_t *)ptr - 1;

    size_t total_size = block->size + BLOCK_SIZE;

    munmap((void *)block, total_size);
}