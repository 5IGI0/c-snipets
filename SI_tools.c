/**
 * @author 5IGI0
 * @email 5IGI0@protonmail.com
 * @create date 2019-10-17 08:11:33
 * @modify date 2019-10-17 08:11:33
 * @desc tools for the International System of Units (IS)
 */

#include <stdio.h>

char IS_GetSymbol(unsigned long long unit) {
	if (unit < 1000ULL)
		return '\0';
	if (unit < 1000000ULL)
		return 'k';
	if (unit < 1000000000ULL)
		return 'M';
	if (unit < 1000000000000ULL)
		return 'G';
	if (unit < 1000000000000000ULL)
		return 'T';
	if (unit < 1000000000000000000ULL)
		return 'P';
	else
		return 'E';
}

double IS_GetNumber(unsigned long long unit) {
	if (unit < 1000ULL)
		return (double)unit;
	if (unit < 1000000ULL)
		return (double)unit / 1000;
	if (unit < 1000000000ULL)
		return (double)unit / 1000000;
	if (unit < 1000000000000ULL)
		return (double)unit / 1000000000;
	if (unit < 1000000000000000ULL)
		return (double)unit / 1000000000000;
	if (unit < 1000000000000000000ULL)
		return (double)unit / 1000000000000000;
	else
		return (double)unit / 1000000000000000000;
}