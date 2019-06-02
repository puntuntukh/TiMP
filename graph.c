#include <stdio.h> 
#include <stdlib.h> 

void graph(int **Linkage, int n)
{
int *nodes = malloc(n * sizeof(int));
for (int i = 0; i < n; i++)
{
nodes[i] = i + 1;
printf("%d ", nodes[i]);
}
printf("\n");
for (int i = 0; i < n; i++)
{
Linkage[i] = malloc(n * sizeof(int));;
}

int amountTransit, t;
int nodeTransit;
for (int j = 0; j < n; j++)
{
t = 1;
printf("\nКоличество переходов в другие вершины %d: ", j + 1);
scanf("%d", &amountTransit);
int *nodesTransit = malloc(amountTransit * sizeof(int));
int *massiveWeight = malloc(amountTransit * sizeof(int));
for (int i = 0; i < amountTransit; i++)
{
if (t)
{
printf("В какие вершины переходит %d: ", j + 1);
t = 0;
}
scanf("%d", &nodesTransit[i]);
}
for (int i = 0; i < amountTransit; i++)
{

printf("Введите вес для %d - %d: ", j + 1, nodesTransit[i]);
scanf("%d", &massiveWeight[i]);
}
for (int i = 0; i < n; i++)
{
for (int q = 0; q < amountTransit; q++)
{
if (i + 1 == nodesTransit[q])
{
Linkage[j][i] = massiveWeight[q];
break;
}
else
{
Linkage[j][i] = 0;
}
}
}
}
}

void *path(int **Linkage, int n, int node)
{
int *s = malloc(n * sizeof(int));
int *d = malloc(n * sizeof(int));
for (int i = 0; i < n; i++)
{
s[i] = 0; 
d[i] = 1000; //типа бесконечность 
}
d[node - 1] = Linkage[node - 1][node - 1];
int min, nodeIndex;
do {
nodeIndex = 1000;
min = 1000;
for (int i = 0; i < n; i++)
{
if (d[i] < min && s[i] == 0)
{
min = d[i];
nodeIndex = i;
}
}
if (nodeIndex != 1000)
{
for (int i = 0; i < n; i++)
{
if (Linkage[nodeIndex][i] != 0)
{
int count = min + Linkage[nodeIndex][i];
if (count < d[i])
{
d[i] = count;
}
}
}
s[nodeIndex] = 1;
}
} while (nodeIndex < 1000);
return d;
}

int *ind_len(int **Linkage, int sum, int s, int n, int *mv, int *m)
{
int node = 1000;
int gr = 1000;
int min = 0;
for (int i = 0; i < n; i++)
{
if (Linkage[s][i] != 0 && mv[i] == 0)
if (Linkage[s][i] + Linkage[i][s] < gr)
{
node = i;
gr = Linkage[i][s] + Linkage[s][i];
min = Linkage[s][i];
}
}
m[0] = node;
m[1] = m[1] + sum + min; // возвращает массив из 2 переемен 1 - индекс вершины 2 - кратчайший суммированный путь до этой вершины 
// вернет массив (индекс; длина)
return m;
}

void circuit(int **Linkage, int sum, int s, int n, int *mv, int *m)
{
int t = 0; int summa = 0;
summa += m[1];
for (int i = 0; i < n; i++)
{
if (Linkage[i][s] != 0)
{
t++; //обход самого первого ненулевого элемента
break;
}
}
if (t)
{
int node, p;
mv[s] = 1;
printf("%d-", s + 1);
ind_len(Linkage, sum, s, n, mv, m);
node = m[0];
if (node != 1000)
circuit(Linkage, sum, node, n, mv, m);
else
{
m[1] = m[1] + sum + Linkage[s][0];
printf("%d\nДлина пути: %d", 1, summa);
return;
}
}
}

int main()
{
int n, node, sum = 0;
printf("Количество вершин в графе:");
scanf("%d", &n);
int **Linkage = malloc(n * sizeof(int));
int *mv = malloc(n * sizeof(int));

graph(Linkage, n);

printf("\nМатрица смежности:\n");
for (int i = 0; i < n; i++)
{
printf("\n");
for (int j = 0; j < n; j++)
{
printf("%d ", Linkage[i][j]);
}
} 

printf("\nНачальная вершина:\n");
scanf("%d", &node);

int *x = malloc(n * sizeof(int));
x = path(Linkage, n, node);

for (int i = 0; i < n; i++)
printf("Кратчайший путь от вершины %d до вершины %d: %d\n", node, i + 1, x[i]);

for (int i = 0; i < n; i++)
{
mv[i] = 0;
}

int m[2], s = 0; 
printf("\nКонтур минимальной длины:\n");
circuit(Linkage, sum, s, n, mv, m);
printf("\n");
return 0;
}
