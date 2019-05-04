#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sorting_Q (int *arr, int first, int last) //быстрая
{
	int tmp = 0;
	if (first<last){int l = first, r = last-1;
	int opor = arr[(l + last) / 2]; 
	while (l <= r)
	{
		while (arr[l] < opor)
			l++;
		while (arr[r] > opor)
			r--;
		if (l <= r){
			int t = arr[l];
			arr[l] = arr[r];
			arr[r] = t;
			l++;
			r--;
			tmp++;}
		tmp++;
		}
		tmp += sorting_Q (arr, first, r+1);
		tmp+= sorting_Q (arr, l, last);
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
		tmp = sorting_Q(arr, 0, n); 	 
		if (tmp > max) max = tmp; 
		if (tmp < min) min = tmp; 
	}
	printf("Сортировка быстрая. Лучший результат: %d Худший результат: %d\n", min, max);  
	return 0; 
}
