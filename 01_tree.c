#include <stdio.h>
#include <stdlib.h>

typedef struct node_tree {
	struct node_tree *left;
	struct node_tree *right;
	struct node_tree *parent;
	int value;
}node;

typedef struct bin_tree {
	node *root;
	int size;
}tree;

typedef struct node_ochered {
	struct node_ochered *next;
	node *ptr_node_tree;
}node_ochered;

typedef struct ochered {
	node_ochered *head;
	node_ochered *tail; 
}ochered;

void init_ochered(ochered *och){
	och -> head = NULL;
	och -> tail = NULL;
};

int isEmpty(ochered *och) {
	if (och -> head == NULL && och -> tail == NULL)
		return 1;
	return 0;
}

int push(ochered *och , node* n){
	node_ochered *new_node_ochered = malloc(sizeof(node_ochered));
	new_node_ochered -> ptr_node_tree = n;
	new_node_ochered -> next = NULL;
	if (!(och -> head))
		och -> head = new_node_ochered;
	else och -> tail -> next = new_node_ochered;
	och -> tail = new_node_ochered; 
	return 1;
}

node* pop(ochered *och){

	if (!(och -> head))
		return 0;

	node_ochered *node_ochered_pop;
	node *node_ochered_return = NULL;
	node_ochered_return = och -> head -> ptr_node_tree;
	node_ochered_pop = och -> head;
	och -> head = och -> head -> next;

	if (och -> head == NULL)
		och -> tail = NULL;
	free(node_ochered_pop);
	return node_ochered_return;
}

void clear_ochered(ochered *och) 
{
	node_ochered *tmp , *node_ochered_pop;
	tmp = och -> head;
	do{
		node_ochered_pop = tmp;
		tmp = tmp -> next;
		free(node_ochered_pop); 
 	} while(tmp);
	och -> head = NULL;
	och -> tail = NULL;
}

void init(tree* t){
	t -> root = NULL;
	t -> size = 0;
}

int insert(tree* t, int var){
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL)
		return 2;
	new_node -> value = var;
	new_node -> left = NULL;
	new_node -> right = NULL;
	node *tmp = t -> root;
	node *node_dop = NULL;
	if (!(tmp)){
		new_node -> parent = NULL;
		t -> root = new_node;
		t -> size = 1;
		return 0;
	}

	while(tmp) {
		if ( var < tmp -> value){
			node_dop = tmp;
			tmp = tmp -> left;
		}
	else if(var == tmp -> value)
		return 1;
	else{ 
		node_dop = tmp;
		tmp = tmp -> right;
 		} 
	}
	new_node -> parent = node_dop;
	if ( new_node -> value > new_node -> parent -> value )
		new_node -> parent -> right = new_node;
	else new_node -> parent -> left = new_node;

	(t -> size)++; 
	return 0;
}

int removeMin(tree *t , node* n){
	node *tmp = n -> left , *node_rem;
	if (tmp == NULL ){
		node_rem = t -> root;
		t -> root = t-> root -> right;
		free(node_rem);
		(t -> size)--;
		return 0;
	}
	while(tmp -> left != NULL){
	 tmp = tmp -> left;
	}

	 if (tmp -> right == NULL){
		 tmp -> parent -> left = NULL;
		 free(tmp);
	 }
	 else{ 
		 tmp -> parent -> left = tmp -> right;
		 tmp -> right -> parent = tmp -> parent;
		 free(tmp);
	 }

	 (t -> size)--;
	 return 0;
}

void clear(tree* t){
		 while(t -> root)
		 removeMin(t , t-> root);
	}

int find(tree* t, int var , node **n){
	 int flack_node = 1;
	 node *tmp = t -> root , *node_dop = NULL;
	 while( tmp -> value != var) {
	 	if ( var < tmp -> value){
	 	node_dop = tmp;
	 	tmp = tmp -> left;
	 	}
	 	else{ 
	 	node_dop = tmp;
	 	tmp = tmp -> right;
	 	}	
		 if (!tmp){
		 flack_node = 0;
		 break;
 		}
 	}
 	if (flack_node == 0)
	 	return 1;
 	*n = tmp;
	 return 0;
}

int Remove(tree* t, int var){
	int flack_node = 1;
 	node *tmp = t -> root , *node_dop = NULL;
 	while( tmp -> value != var) {
 	if ( var < tmp -> value){
 	node_dop = tmp;
 	tmp = tmp -> left;
 	}
	else{ 
 	node_dop = tmp;
 	tmp = tmp -> right;
 	}
	if (!tmp){
		flack_node = 0;
		break;
		}
	}
 	if (flack_node == 0)
 		return 1;
 	(t -> size)--;
 	if (tmp -> left == NULL && tmp -> right == NULL){
 		node_dop = tmp;
		 if (tmp -> parent -> value > var)
 		tmp -> parent -> left = NULL;
 		else tmp -> parent -> right = NULL;
 		free(node_dop);
 		return 0;
 	}
 if (tmp -> left != NULL && tmp -> right == NULL){
 	node_dop = tmp;
 	if ( tmp -> value < tmp -> parent -> value )
 	tmp -> parent -> left = tmp -> left;
 	else tmp -> parent -> right = tmp -> left;
 	tmp -> left -> parent = tmp -> parent;
 	free(node_dop);
	 return 0;
 }

 if (tmp -> left == NULL && tmp -> right != NULL){
	 node_dop = tmp;
 	if ( tmp -> value < tmp -> parent -> value )
	 tmp -> parent -> left = tmp -> right;
	 else tmp -> parent -> right = tmp -> right;
	 tmp -> right -> parent = tmp -> parent;
	 free(node_dop);
	 return 0;
 }

 if (tmp -> left != NULL && tmp -> right != NULL){
 	node *tmp2 = NULL;
 	tmp2 = tmp -> right;
	if (tmp2 -> left == NULL){
	 	tmp -> value = tmp2 -> value;
	 	if (tmp -> right -> right == NULL){
		 tmp -> right = NULL;
 		 free(tmp -> right);
 		 return 0;
	 	}
	 tmp -> right = tmp -> right -> right;
	 tmp -> right -> parent = tmp;
 	 free(tmp2);
 	 return 0;
 	}
 	while(tmp2 -> left){
 	tmp2 = tmp2 -> left;
 	} 

	tmp -> value = tmp2 -> value;

 	if (tmp2 -> right){
		 tmp -> value = tmp2 -> value;
		 tmp2 -> value = tmp2 -> right -> value;
		 tmp -> right = NULL;
 		free(tmp2 -> right);
		 return 0;
 	}
 	else {
	 tmp -> value = tmp2 -> value;
	 tmp2 -> parent -> left = NULL;
 	 free(tmp2);
 	 return 0;
	  }
 }
}

void print(node* n)
{
 	if (n == NULL){
 		printf("%s\n","-" );
 		return;
 	}

 ochered ochered1 , ochered2 , *ptr_ochered1 , *ptr_ochered2;
 ptr_ochered1 = &ochered1;
 ptr_ochered2 = &ochered2;
 init_ochered(ptr_ochered1);
 init_ochered(ptr_ochered2);

 node *temp = NULL; 
 node_ochered *temp1 = NULL; 
 int root_check = 0 , root_value = n -> value , flag_null_str = 0;
 node *left = n -> left;
 node *right = n -> right;
 push(ptr_ochered1 , n);
 while(1){
 	while(!(isEmpty(ptr_ochered1))){
 		temp = pop(ptr_ochered1);
 		if (isEmpty(ptr_ochered1)){
 			if ((temp -> value == root_value) && root_check == 1)
 				printf("%s\n" , "_" );
			else printf("%d\n", temp -> value );
 		} 
 		else{
 			if ((temp -> value == root_value) && root_check == 1)
 			printf("%s " , "_" ); 
 			else printf("%d " , temp -> value);
 		}
 		if(temp -> left != NULL)
 			push(ptr_ochered2 , temp -> left);
		else {
 			push(ptr_ochered2 , n);
 		} 
 		if (temp -> right != NULL)
 			push(ptr_ochered2 , temp -> right);
 		else push(ptr_ochered2 , n);
	 }
n -> left = NULL;
n -> right = NULL;
root_check = 1;
temp1 = ptr_ochered2 -> head;
while(ptr_ochered2 -> head -> ptr_node_tree -> value == root_value){
	ptr_ochered2 -> head = ptr_ochered2 -> head -> next;
	if (ptr_ochered2 -> head -> next == NULL){
		if (ptr_ochered2 -> head -> ptr_node_tree -> value == root_value){
		flag_null_str = 1;
		n -> left = left;
		n -> right = right;
		clear_ochered(ptr_ochered2);
		break;
		}
	}
 }
 ptr_ochered2 -> head = temp1;
 if (flag_null_str == 1){
 	break;
 }

 ptr_ochered1 -> head = ptr_ochered2 -> head;
 ptr_ochered1 -> tail = ptr_ochered2 -> tail;
 ptr_ochered2 -> head = NULL;
 ptr_ochered2 -> tail = NULL;
 } 
}

void printTree(tree* t){
	print(t -> root);
}

int rotateLeft(node **n){
 node* right_node = (*n) -> right;
 if (right_node == NULL)
 	return 1;
 (*n) -> right = right_node -> left;
 right_node -> left = *n;
 right_node -> parent = (*n) -> parent;
 (*n) -> parent = right_node;
 *n = right_node;
 return 0;
}

int rotateRight(node **n){
 node* left_node = (*n) -> left;
 if (left_node == NULL)
 	return 1;
 (*n) -> left = left_node -> right;
 left_node -> right = *n;
 left_node -> parent = (*n) -> parent;
 (*n) -> parent = left_node;
 *n = left_node;
 return 0;
}

int main(void) {

	tree tree;
	init(&tree);
	int num; 
	
	for (int i = 0 ; i < 4 ; i++){
		scanf("%d" , &num);
		insert(&tree , num);
	}
	printTree(&tree);

for (int i = 0 ; i < 3 ; i++){
scanf("%d" , &num);
insert(&tree , num);
}
printTree(&tree);

node *ptr= NULL;

int m1;
scanf("%d" , &m1);
find(&tree , m1 , &ptr);
if (ptr -> parent == NULL)
	printf("%s ", "_");
else printf("%d ", ptr -> parent -> value );
if (ptr -> left == NULL)
	printf("%s ", "_");
else printf("%d ", ptr -> left -> value );
if (ptr -> right == NULL)
	printf("%s\n", "_");
else printf("%d\n", ptr -> right -> value );

int m2;
scanf("%d" , &m2);
if (find(&tree , m2 , &ptr) == 0) {
	if (ptr -> parent == NULL)
	printf("%s ", "_");
	else printf("%d ", ptr -> parent -> value );
	if (ptr -> left == NULL)
	printf("%s ", "_");
	else printf("%d ", ptr -> left -> value );
	if (ptr -> right == NULL)
	printf("%s\n", "_");
	else printf("%d\n", ptr -> right -> value );
}
else printf("%s\n", "-");

int m3;
scanf("%d" , &m3);
Remove(&tree , m3);
printTree(&tree);

while( rotateLeft(&tree.root) == 0){ ; }
printTree(&tree);
while( rotateRight(&tree.root) == 0){ ; }
printTree(&tree);
printf("%d\n", tree.size ); 

clear(&tree);

printTree(&tree);
return 0;
}	
