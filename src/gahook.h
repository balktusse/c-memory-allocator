#ifndef GAHOOK_H_   /* Include guard */
#define GAHOOK_H_

#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>

void *galloc(size_t size);
void gfree(void *ptr);

#endif
