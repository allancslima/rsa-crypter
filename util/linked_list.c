#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct _node {
	void *data;
	node_t *next;
};

struct _linked_list {
	node_t *head;
	node_t *tail;
};

linked_list_t* create_linked_list()
{
	linked_list_t *new_list = (linked_list_t*) malloc(sizeof(linked_list_t));
	new_list->head = NULL;
	new_list->tail = NULL;
	return new_list;
}

void add(linked_list_t *list, void *data)
{
	node_t *new_node = (node_t*) malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = NULL;

	if (list->head == NULL) {
		list->head = new_node;
		list->tail = new_node;
	}
	list->tail->next = new_node;
	list->tail = new_node;
}

int is_empty(linked_list_t *list)
{
	return list->head == NULL;
}
