#include <stdio.h>
#include <stdlib.h>
//#include "myarraylib.h"

int binary_search(int *arr[],int low,int high,const int key);
int ternary_search();

int main() {
  const int arr[] = {-1,0,1,2,3,4,5};
  int i1 = 0,i2 = sizeof(arr)/sizeof(arr[0]) - 1;
  int *ptr[2];
  int *front_ptr = arr;
  int *back_ptr = arr+i2;

  ptr[0] = front_ptr;
  ptr[1] = back_ptr;

  const int key = 3;
  int index = binary_search(ptr,i1,i2,key);
  if(index == -1)
    puts("Key not found in the array!");
  else
    printf("Key was found at index %d\n",index);

  /*int low = i1;
  int high = i2;
  int mid = (low+high)/2;
  while (arr[mid]!=key && mid < i2 && mid > i1) { //iterative approach to binary search
    if(arr[mid] > key) {
      low = i1;
      high = mid - 1;
      mid = (low+high)/2;
    }
    else {
      low = mid + 1;
      high = i2;
      mid = (low+high)/2;
    }
  }
  if (arr[mid] != key) {
    puts("Key is not found");
    exit(0);
  }
  printf("The key is found at index %d\n",mid);*/
}

int binary_search(int *arr[],int low,int high,const int key) { /*recursive approach to binary_search*/
  int mid = (high+low)/2;
  int len = arr[1] - arr[0]; 

  if (*(arr[0]+mid) == key)
    return mid;
  else if (*(arr[0]+mid) > key && mid < len && mid > 0) {
    low = 0;
    high = mid - 1;
    return binary_search(arr,low,high,key);
  }
  else if (*(arr[0]+mid) < key && mid < len && mid > 0) {
    low = mid + 1;
    high = len;
    return binary_search(arr,low,high,key);
  }
  else 
    return -1;
  
}
