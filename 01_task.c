#include <stdio.h> 
#include <stdlib.h> 

typedef struct node //описание элемента списка
{ 
    int value; 
    struct node *next; //ссылка на след элемент
} node; 

void printNode(node *a){ 
    while (a){ 
        printf("%d ", a->value); 
        a = a->next; 
    }     
    printf("\n"); 
}  

typedef struct list // описание всего списка
{ 
    int value; 
    struct node * next; 
    struct node * tale; 
} list; 

void init(node * a){ 
    a = (node *)malloc(sizeof(node)); 
} 

void clear(node * a){ 
 
    node * b = a; 
    node * next = b->next;
    while (b->next != NULL){
        free(b); 
        b = b->next;

        *a = *b;
    }     

    free(a);
  
} 
 
int isEmpty(node *a){ 
    if (a == NULL){ 
        return 1;  
    } else { 
        return 0; 
    } 
} 

node * find (node * a, int value){ 
    node * b = a; 
    while (b){ 
      if (b->value == value){ 
          return b; 
      } 
      b = b->next; 
    } 
    return NULL; 
} 


int push_back(node **a, int value) { 
    node *b = (node*) malloc(sizeof(node)); 
    b->value = value; 
    if (*a == NULL){ 
        b->next = NULL; 
    } else { 
        b->next = (*a); 
    } 
    *a = b; 
    return 0;
} 
 
int push_front(node **a, int value) { 
    node * b = (node *) malloc(sizeof(node)); 
    b->value = value; 
    b->next = NULL; 
    if (*a == NULL){
      *a = b;
    } else {
      node * c = *a; 
           while (c->next != NULL){ 
           c = c->next; 
      } 
      c->next = b;
    }
    return 0;
} 

int insertAfter (node * n, int value){
    node * next = n->next;
    node * b = (node *) malloc(sizeof(node)); 
    b->value = value;
    b->next = next;
    n->next = b;
    return 0;
}

int remove (node * a, int value){

    node * b = a; 
    node * last = NULL;
    while (b){ 
      if (b->value == value){ 
          node * next = b->next;          
          
          free(b);
          
          if (last != NULL){
            last->next = next;
          } else {
            *a = *next;
          }
          

                  
          return 0; 
      } 
      last = b;
      b = b->next; 
    } 

    return 1;
}
  

int main() 

{ 

    int n;
    scanf("%d", &n);

    node* a = NULL; 
    init(a); 

    for (int i = 0; i < n; i++){
      int ni;
      scanf("%d", &ni);
      push_front(&a, ni);
    }

    printNode(a);

    int k;
    for (int i = 0; i < 3; i++){
      scanf("%d", &k);
      node * f = find(a, k);
      if (f == NULL){
        printf("0");
      } else {
        printf("1");
      }
    }

    printf("\n");

    int m;
    scanf("%d", &m);
    push_front(&a, m);
    printNode(a);

    int t;
    scanf("%d", &t);
    push_back(&a, t);
    printNode(a);

    int j, x;
    scanf("%d %d", &j, &x);

    node * b = a;
    for (int i = 1; i < j; i++){
      b = b->next;
    }
    insertAfter(b, x);
    printNode(a);
    
    int z;
    scanf("%d", &z);
    removeA(a, z);
    printNode(a);

    return 0; 

} 
