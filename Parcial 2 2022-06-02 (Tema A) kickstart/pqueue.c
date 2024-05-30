#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    /* COMPLETAR*/
    struct s_node *front;
    unsigned int size;
};

struct s_node {
    /*COMPLETARDI*/
    pqueue_elem elem;
    unsigned int priority;
    struct s_node *next;

};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = NULL;
    // Completardox
   new_node = malloc(sizeof(struct s_node));

    assert(new_node!=NULL);
    /*COMPLETARDI*/
    new_node->elem = e;
    new_node->priority = priority;
    new_node->next = NULL;
//  assert(e==e && priority == priority); // BORRAR ESTE ASSERT
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    /*COMPLETARDO*/
    free(node);
    node = NULL;
    return node;
}


static bool invrep(pqueue q) {
    /*COMPLETAR*/
	if (q == NULL) return true;
    struct s_node *current = q->front;
    while (current != NULL && current->next != NULL) {
        if (current->priority > current->next->priority) {
            return false;
        }
        current = current->next;
    }
//    assert(q==q); // BORRAR ESTE ASSERT
    return true;
}

pqueue pqueue_empty(void) {
    pqueue q=NULL;
    /*COMPLETARDI*/
    q = malloc(sizeof(struct s_pqueue));
    assert(q != NULL);
    q->front = NULL;
    q->size = 0;
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    /*COMPLETARDI*/
        if (q->front == NULL || q->front->priority > priority) {
        new_node->next = q->front;
        q->front = new_node;
    } else {
        struct s_node *current = q->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    q->size++;
    assert(invrep(q));
//    assert(e==e && priority==priority && new_node==new_node); // BORRAR ESTE ASSERT
    return q;
}

bool pqueue_is_empty(pqueue q) {
    /*COMPLETARDO*/
//    assert(q==q); // BORRAR ESTE ASSERT
    return q->front == NULL;
}

pqueue_elem pqueue_peek(pqueue q) {
    /*COMPLETAR*/
//    assert(q==q); // BORRAR ESTE ASSERT
	assert(!pqueue_is_empty(q));
    return q->front->elem;
}

unsigned int pqueue_peek_priority(pqueue q) {
    /*COMPLETAR*/
	assert(!pqueue_is_empty(q));
//    assert(q==q); // BORRAR ESTE ASSERT
    return q->front->priority;
;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));
    /*COMPLETAR*/
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    /*COMPLETAR*/
    assert(!pqueue_is_empty(q));
    struct s_node *node_to_remove = q->front;
    q->front = q->front->next;
    destroy_node(node_to_remove);
    q->size--;
    assert(invrep(q));

//    assert(q==q); // BORRAR ESTE ASSERT
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    /*COMPLETAR*/
    assert(invrep(q));
    while (!pqueue_is_empty(q)) {
        q = pqueue_dequeue(q);
    }
    free(q);
    q = NULL;
//    assert(q == NULL);
    return q;
}
