#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct _node node_t;
typedef struct _linked_list linked_list_t;

linked_list_t* create_linked_list();

void add(linked_list_t *list, void *data);

int is_empty(linked_list_t *list);

#endif
