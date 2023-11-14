#include "main.h"
/**
 * print_uppercase - this prints hexadecimals
 * @numb: an argument
 * Return: counts
 */

int print_uppercase(unsigned int numb)
{
	int x = 0;
	int *arr;
	int counts = 0;
	unsigned int memb = numb;

	while (numb / 16 != 0)
	{
		numb /= 16;
		counts++;
	}
	counts++;
	arr = malloc(counts * sizeof(int));
	while (x < counts)
	{
		arr[x] = memb % 16;
		memb = memb / 16;
		x++;
	}
	for (x = counts - 1; x >= 0; x++)
	{
		if (arr[x] > 9)
			arr[x] = arr[x] + 7;
		_putchar(arr[x] + '0');
	}
	free(arr);
	return (counts);
}
