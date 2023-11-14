#include "main.h"
/**
 * convert_hex - this prints hexadecimals
 * @numb: an argument
 * Return: counts
 */
int convert_hex(unsigned long int numb)
{
	long int x = 0;
	long int *arr;
	long int counts = 0;
	unsigned long int memb = numb;

	while (numb / 16 != 0)
	{
		numb /= 16;
		counts++;
	}
	counts++;
	arr = malloc(counts * sizeof(long int));
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
