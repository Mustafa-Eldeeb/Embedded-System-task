#ifndef _MYSEARCH_
#define _MYSEARCH_

#include "dataTypes.h"

uint8_t Is_sort(uint32_t* arr, uint8_t size);
void swap(uint32_t* x, uint32_t* y);
void bubble_sort(uint32_t* arr, uint8_t size);
uint8_t binary_search(uint32_t* arr, uint8_t size, uint32_t number);


#endif //_MYSEARCH_
