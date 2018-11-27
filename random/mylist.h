#ifndef GRAPH_H
#define GRAPH_H

struct node{
	int val;
	node* next;
};

void add_front(node** head, int key);
void add_back(node** head, int key);
void add_before(node** head, int add_key, int before_key);
void add_after(node** head, int add_key, int after_key);
void delete_front(node** head, int key);
void delete_back(node** head, int key);
void delete_before(node** head, int before_key);
void delete_after(node** head, int after_key);
void reverse_iterative(node** head);
void reverse_recursive(node** head);
node* get_last(node* head);
node* get_first(node* head);
void merge_sort(node** head);
void quick_sort(node** head);
void heap_sort(node** head);
void bubble_sort(node** head);
bool detect_loop(node* head);
void detect_and_delete_loop(node** head);
bool is_palindrome(node** head);
int count_nodes(node* head);
node* find_node(node* head, int item);