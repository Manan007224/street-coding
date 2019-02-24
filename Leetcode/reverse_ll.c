#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node* next;
};

struct node* new_node(int val){
	struct node* just = malloc(sizeof(struct node));
	just->val = val;
	just->next = NULL;
	return just;
}

struct node* reverse_recursive(struct node** head_node, struct node* curr_node){
	if(curr_node->next==NULL){
		*(head_node)=curr_node;
		return curr_node;
	}
	struct node* now = reverse_recursive(head_node, curr_node->next);
	now->next = curr_node;
	curr_node->next = NULL;
	return curr_node;
}

void delete_node(struct node** head_node, struct node* to_delete){
	struct node* check = *(head_node);
	if(check == to_delete){
		*(head_node) = check->next;
		free(check);
	}
	struct node* iter = *(head_node);
	while(iter->next != NULL){
		if(iter->next == to_delete){
			struct node* temp = iter->next;
			iter->next = iter->next->next;
			free(temp);
			return;
		}
		iter = iter->next;
	}
	if(iter == to_delete){
		free(iter);
	} 
}

int main(){
	struct node* root = new_node(1);
	root->next = new_node(2);
	root->next->next = new_node(3);
	root->next->next->next = new_node(4);
	root->next->next->next->next = new_node(5);
	struct node* to_pass = root;
	// reverse_recursive(&root, to_pass);
	delete_node(&root, root->next->next);
	struct node* iter = root;
	while(iter){
		printf("%d\n",iter->val);
		iter=iter->next;
	}
	return 0;
}