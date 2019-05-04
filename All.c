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


int sorting_Sh(int *arr,int arr_len) //Шелла
{ 
        int j, step, tmp = 0;
        for(step = arr_len/2; step > 0; step = step/2)
		{
                for (int i = step; i < arr_len; i++)
			{
                        int t = arr[i];
                        for ( j= i; j >= step; j = j - step)
				{
                                if (t < arr[j - step])
					{arr[j] = arr[j - step]; tmp++;}
                                else {tmp++; break;}
                        	}
                        arr[j] = t;
			tmp++;
                }
		tmp++;
        }
return tmp;
}

int siftDown(int *arr, int root, int bottom)
{
 	int max;
	int tmp = 0;	
	
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
		sorting_Q (arr, first, r+1);
		sorting_Q (arr, l, last);
	}
	return tmp;
}    

int main() 
{ 
	clock_t TIME, all_time;
	srand(time(NULL)); 

	int length_arr[15] = {1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 50, 75, 100, 250, 500}; 
	int tmp; 

	for (int x = 0; x < 4; x++) 
	{ 
		for (int i = 0; i < 15; i++) 
		{ 
		all_time = 0; 
		tmp = 0; 
		int n = length_arr[i]; 
		int *arr = malloc(n*sizeof(int));
		

		for (int j = 0; j < 1000; j++) 
		{ 
			for (int p = 0; p < n; p++) 
			{ 
				arr[p] = rand()%2000-1000; 
			} 
			TIME = clock(); 

			switch(x) { 
				case 0: 
					tmp += sorting_R(arr, n); 
					break; 
				case 1: 
					tmp += sorting_Sh(arr, n); 
					break; 
				case 2: 
					tmp += sorting_Pyr(arr, n); 
					break; 
				case 3: 
					tmp += sorting_Q(arr, 0, n); 
					break; 
			} 
			TIME = clock() - TIME; 
			all_time += TIME;  
		} 

		switch(x) { 
			case 0: 
				printf("Сортировка расчёской. Элементов: %d\n" , n); 
				break; 
			case 1: 
				printf("Сортировка Шелла. Элементов: %d\n" , n); 
				break; 
			case 2: 
				printf("Быстрая сортировка. Элементов: %d\n" , n); 
				break; 
			case 3: 
				printf("Пирамидальная сортировка. Элементов: %d\n" , n); 
				break; 
		} 	

		printf("Время: %f\n", (double)all_time/CLOCKS_PER_SEC);
		all_time /= 1000;
		printf("Среднее время: %f\n", (double)all_time/CLOCKS_PER_SEC); 
		printf("Операций: %d\n", tmp); 
		printf("Среднее количество операций: %d\n", tmp/1000); 
		printf("\n\n");			 
		} 
	} 
	return 0; 
}
