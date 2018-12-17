/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Program calculates statistics of an array
 *
 * Program runs various statistical functions for a defined array 'test'.
 *
 * @author Alexes
 * @date 12/15/18
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char median;
  unsigned char mean;
  unsigned char max;
  unsigned char min;

  /* Statistics and Printing Functions Go Here */
	sort_array(test, SIZE);  
	print_array(test, SIZE);
  
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  max = find_maximum(test, SIZE);
  min = find_minimum(test, SIZE);

  
  print_statistics(mean, median, max, min);
  
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char mean, unsigned char median, unsigned char maximum, unsigned char minimum) {
	
  printf("\nMedian: %d, Mean: %d, Max: %d, Min: %d\n", median, mean, maximum, minimum);
}

void print_array(unsigned char * ptr, unsigned int size) {
  int i;

  if (ptr == NULL){
    return;
  }

  for(i = 0; i < size; i++) {
    printf("%d\n", *ptr);
    ptr++;
  }
}

unsigned char find_median(unsigned char * ptr, unsigned int size) {
  int i;
	unsigned int split = size/2;
	unsigned int med1;
	unsigned int med2;

	if(size%2 != 0) {
		//split at half
 		return *(ptr + (sizeof(unsigned char) * split));
  }
	else {
		med1 = *(ptr + (sizeof(unsigned char) * split));
		med2 = *(ptr + (sizeof(unsigned char) * (split + 1)));
		return (med1 + med2)/2;
  }
  
}

unsigned char find_mean(unsigned char * ptr, unsigned int size) {
  int i;
  unsigned int sum = 0;

  if (ptr == NULL) {
    return 0;
  }

  for(i = 0; i < size; i++) {
    sum += *ptr;
    ptr++;
  }
  return (sum/size);
}

unsigned char find_maximum(unsigned char * ptr, unsigned int size) {
  unsigned int max = 0;
  int i;
 
  if(ptr == NULL) {
    return 0;
  }

  for(i = 0; i < size; i++) {
    if (*ptr > max) {
      max = *ptr;
    }
    ptr++;

  }

  return max;
}

unsigned char find_minimum(unsigned char * ptr, unsigned int size) {
  unsigned int min = *ptr;
  int i;
  ptr++;

  for(i = 1; i < size; i++) {
    if (*ptr < min) {
      min = *ptr;
    }
    ptr++;
  }

  return min; 

}

void sort_array(unsigned char * ptr, unsigned int size) {
  unsigned int i;
  unsigned int j;
  unsigned char temp;
	unsigned char valuei;
 	unsigned char valuej;

  for(i = 0; i < size; i++) {
    for(j = i+1; j < size; j++) {
			valuei = *(ptr + (sizeof(unsigned char) * i));
			valuej = *(ptr + (sizeof(unsigned char) * j));
 		
      if( valuei < valuej ) {
      	temp = valuei;
				*(ptr + (sizeof(unsigned char) * i)) = valuej;
				*(ptr + (sizeof(unsigned char) * j)) = temp;
      }
    }
  }
}
