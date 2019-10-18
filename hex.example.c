#include <stdio.h>
#include <string.h>

#include "hex.h"

#define USAGE_TEXT "Usage : %s <encode/decode> <data>"
#define INVALID_HEX_TEXT "Error : invalid hex"

int main(int argc, char const *argv[]) {

	if (argc != 3) {
		fprintf(stderr, USAGE_TEXT"\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	
	if (!strcmp("encode", argv[1])) {
		char *hex = hexDump(argv[2], strlen(argv[2]));
		printf("%s\n", hex);
		free(hex);
	} else if (!strcmp("decode", argv[1])) {

		if (strlen(argv[2])%2){
			fprintf(stderr, INVALID_HEX_TEXT"\n");
			exit(EXIT_FAILURE);
		}

		char *data = calloc(strlen(argv[1])/2+1, 1);

		if (!hexLoad(argv[2], data)) {
			fprintf(stderr, INVALID_HEX_TEXT"\n");
			exit(EXIT_FAILURE);
		}
		
		printf("%s\n", data);
		free(data);
	} else {
		fprintf(stderr, USAGE_TEXT"\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	return 0;
}
