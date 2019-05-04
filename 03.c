#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int siftDown(int *arr, int root, int bottom)
{
 	int max;
	int tmp =0;	
	
 	while (root * 2 <= bottom)
	{
		if ((root * 2 == bottom) || (arr[root * 2] > arr[root * 2 + 1]))
		{
			max = root * 2;
		}
		else
		{
			max = root * 2 + 1;
		}
		if (arr[root] < arr[max]) 
		{ 
			int t = arr[root]; 
			arr[root] = arr[max];
			arr[max] = t;
			root = max;
			tmp++;
		}
		else 
		{
			tmp++;
			break;
		}
	}
	return tmp;
}

int sorting_Pyr(int *arr, int arr_len) //пирамидальная
{
	int tmp =0;
	for (int i = (arr_len / 2) - 1; i >= 0; i--)
		tmp += siftDown(arr, i, arr_len - 1);
	for (int i = arr_len - 1; i >= 1; i--)
	{
    		int t = arr[0];
    		arr[0] = arr[i];
    		arr[i] = t;
		tmp += siftDown(arr, 0, i - 1);
	}
return tmp;
}

int main() 
{ 
	int tmp; 
	int n = 100; 
	int max, min; 
	int *arr = malloc(n*sizeof(int)); 
	max = 0; min = 10000; 
	for (int j = 0; j < 1000; j++) 
	{ 
		for (int x = 0; x < n; x++) 
		{ 	
			arr[x] = rand()%2000-1000; 
		} 
		tmp = sorting_Pyr(arr, n); 	 
		if (tmp > max) max = tmp; 
		if (tmp < min) min = tmp; 
	}
	printf("Сортировка пирамидальная. Лучший результат: %d Худший результат: %d\n", min, max);  
	return 0; 
}
