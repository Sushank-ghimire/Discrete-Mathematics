#include <stdbool.h>
#include <stdio.h>
#include "helpers.h"

bool existsInArray(int set[], int num, int sizeOfSet)
{
  int i;
  for (i = 0; i < sizeOfSet; i++)
  {
    if (set[i] == num)
    {
      return true;
    }
  }
  return false;
}

void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
