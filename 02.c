#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

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
		tmp = sorting_Sh(arr, n); 	 
		if (tmp > max) max = tmp; 
		if (tmp < min) min = tmp; 
	}
	printf("Сортировка Шелла. Лучший результат: %d Худший результат: %d\n", min, max);  
	return 0; 
}
