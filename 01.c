#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sorting_R (int *arr, int arr_len) //рассчестка
{
	int step;
	int tmp = 0;
	double fakt = 1.2473309;
	step = arr_len;	
	while (step > 1)
	{	
		step = step/fakt;
		int swap = 0;
		for (int i = 0; i + step < arr_len; ++i)
			if (arr[i + step] < arr[i])
			{
				int t = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = t;
				swap = 1;
				tmp++;
			}
	tmp++;			
		
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
		
		tmp = sorting_R(arr, n); 	 
		if (tmp > max) max = tmp; 
		if (tmp < min) min = tmp; 
		
	}
	printf("Сортировка расчёской. Лучший результат: %d Худший результат: %d\n", min, max);  
	
return 0; 
}
