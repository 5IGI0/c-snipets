#ifndef HEX_H
#define HEX_H

#include <stdlib.h>

char *hexDump(const unsigned char *data, size_t size);
void *hexLoad(const char *data, unsigned char *dst);

#endif