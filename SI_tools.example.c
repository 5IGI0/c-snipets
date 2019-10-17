#include <stdio.h>

#include "SI_tools.h"

#define COUNT_OF(x) (sizeof(x)/sizeof(x[0]))

int main(void){
	unsigned long long units[] = {
		21,
		7066,
		3130006,
		5782565443,
		8086416977232,
		8001593884963935,
		5761519630425467854
	};

	for (size_t i = 0; i < COUNT_OF(units); i++) {
		printf("%.2f%co\n", IS_GetNumber(units[i]), IS_GetSymbol(units[i]));
	}
	return 0;
}