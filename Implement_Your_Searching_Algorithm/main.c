#include <stdio.h>

#include "My_search.h"




int main() {

	uint32_t arr[8] = {2,3,5,7,89,13,4,99};
	
	if ((sizeof(arr) / sizeof(arr[0])) > 255)
	{
		printf("Array size should be < 255\n");
		return;
	}
	uint8_t arr_size = sizeof(arr) / sizeof(arr[0]);
	
	uint8_t result = binary_search(arr, arr_size, 100); //hold the index
	
	if(result == 255)
		printf("NOT FOUND !!\n");
	else
		printf("index is : %d\nelement is: %d\n", result,arr[result]);
	
	
	return 0;
}