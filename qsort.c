#include<stdio.h>
int Partition(int a[],int low,int high)
{ 
    int i = low,j = high;
	int pivot = a[low],temp;
	while(i < j)
	{
		while(a[i] <= pivot && i <= high)
		     i = i + 1;
		while(a[j] > pivot)
		     j = j - 1;
		if(i < j)
		{
		   temp = a[i];
		   a[i] = a[j];
		   a[j] = temp;
		}
	}
	a[low] = a[j];
	a[j] = pivot;
	return j;
}
void quicksort(int a[],int low, int high)
{
	int j,l = low,h = high;
	if(low < high)
   {
        j = Partition(a, l, h);
    	quicksort(a, l, j-1);
	   	quicksort(a, j+1, h); 
	}
}
int main()
{
	int low = 0,high = 10, i;
	int a[10]= {9,0,8,1,7,2,6,3,4,5};
	printf("given array elements:\n");
	for(i = 0;i < high;i++)
		printf("%d ",a[i]);
	quicksort(a,low, high-1);
	printf("\narray sorted by quick sort:\n");
	for(i=0;i < high;i++)
		printf("%d ",a[i]);
	return 0;
}
