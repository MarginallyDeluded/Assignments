#include <stdio.h>

void sort(int *arr,int n,void (*sort_method)(int *,int));
void selectionSort(int *arr,int n);
void mergeSort(int *arr,int n);

int main() {
  int arr[] = {38,27,43,10};
  sort(arr,5,selectionSort); //Selection sort algorithm, time complexity O(n*n) and space complexity O(1). Number of swaps least other than cycle sort.
  //sort(arr,5,mergeSort);

}

void mergeSort(int *arr,int n) {

}

void selectionSort(int *arr,int n) {
  int num;
  int j = 0;
  while(j<n-1) {
    int min = j;
    int i=j; 
    while(i<n) {
      if(arr[i]<arr[min])
        min = i;
      i++;
    }
    //Stable selection sort//
    num = arr[min];
    for (int k=min;k>j;k--)
      arr[k] = arr[k-1];
    arr[j]=num;
    //Unstable selection sort//
    /*num = arr[j];
    arr[j]=arr[min];
    arr[min]=num;*/
    j++;
  }
}

void sort(int *arr,int n,void (*sort_method)(int *,int)) {
  sort_method(arr,n);
  puts("This is the sorted array: ");
  for (int i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
}
