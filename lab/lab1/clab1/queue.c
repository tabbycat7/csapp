

/*
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
  queue_t *q = (queue_t *)malloc(sizeof(queue_t));
  if (q != NULL)
  {
    q->q_size = 0;
    q->tail = q->head = NULL; // tail shoudl be modified as same as the head
    return q;
  }
  /* Remember to handle the case if malloc returned NULL */
  return NULL;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
  /* Remember to free the queue structue and list elements */
  if (q == NULL)
    return;
  list_ele_t *p = q->head;
  while (p)
  {
    // The address of the p should be recorded, otherwise the p will be NULL!!!
    list_ele_t *t = p;
    p = p->next;
    free(t);
    q->q_size--;
  }
  if (q)
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
  /* What should you do if the q is NULL? */
  /* What if malloc returned NULL? */
  if (q == NULL)
    return false;
  list_ele_t *temp = (list_ele_t *)malloc(sizeof(list_ele_t));
  if (temp == NULL)
    return false;
  // if head is NULL
  if (!q->head)
  {
    q->q_size++;
    q->head = temp;
    q->tail = q->head;
    q->head->value = v;
    q->tail->next = NULL;
    return true;
  }
  // Other cases
  temp->value = v;
  temp->next = q->head;
  q->head = temp;
  q->q_size++;
  return true;
}

/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
  /* Remember: It should operate in O(1) time */
  if (!q)
    return false;
  list_ele_t *temp = (list_ele_t *)malloc(sizeof(list_ele_t));
  if (!temp)
    return false;
  if (!q->head)
  {
    q->head = temp;
    q->tail = q->head;
    q->head->value = v;
    q->tail->next = NULL;
    q->q_size++;
    return true;
  }
  temp->value = v;
  q->tail->next = temp;
  q->tail = temp;
  temp->next = NULL;
  q->q_size++;
  return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
  // if queue is NULL or empty
  if (!q || !q->q_size)
    return false;
  list_ele_t *t = q->head->next;
  // The size of queue should descend
  if (vp)
    *vp = q->head->value;
  // free the storage
  free(q->head);
  q->q_size--;
  q->head = t;
  return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
  /* Remember: It should operate in O(1) time */
  if (q)
    return q->q_size;
  return 0;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
  // Just reverse the pointer!
  if (!q || !q->q_size)
    return;
  list_ele_t *p = q->head;
  list_ele_t *nextp = p->next;
  q->tail = p;
  while (nextp)
  {
    list_ele_t *t = nextp->next;
    nextp->next = p;
    p = nextp;
    nextp = t;
  }
  q->head = p;
  q->tail->next = NULL;
}
