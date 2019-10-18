/**
 * @author 5IGI0
 * @email 5IGI0@protonmail.com
 * @create date 2019-10-18 15:50:57
 * @modify date 2019-10-18 15:50:57
 * @desc tools for load/dump hexadecimal
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *hexDump(const unsigned char *data, size_t size) {
	char *output = calloc(size*2+1, 1);
	unsigned char byte = 0;

	if (!output) {
		fprintf(stderr, "allocation failed !\n");
		exit(EXIT_FAILURE);
	}
	
	for (size_t i = 0; i < size; i++) {
		byte = data[i];

		if (byte > 0xF)
			sprintf(output, "%s%X", output, byte);
		else
			sprintf(output, "%s0%X", output, byte);
	}

	return output;
}

// if dst is NULL, the allocation will be automatic
void *hexLoad(const char *data, unsigned char *dst) {
	size_t size = strlen(data);
	char tmpHexByte[3] = "";
	unsigned char tmpByte = 0;
	_Bool internalAlloc = false;

	if (size%2) // invalid hex
		return NULL;
	

	if (!dst) {
		dst = calloc(size/2, 1);
		internalAlloc = true;
		if (!dst) {
			fprintf(stderr, "allocation failed !\n");
			exit(EXIT_FAILURE);
		}
	}
	
	for (size_t i = 0; i < size/2; i++) {
		tmpHexByte[0] = data[i*2];
		tmpHexByte[1] = data[i*2+1];
		if (!sscanf(tmpHexByte ,"%hhX", &tmpByte)) { // if invalid hex byte
			if(internalAlloc)
				free(dst);
			return NULL;
		} else {
			dst[i] = tmpByte;
		}
	}
	
	return dst;
}