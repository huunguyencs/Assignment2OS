#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if (q->size == MAX_QUEUE_SIZE)
		return;
	q->proc[q->size++] = proc;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (empty(q) == 1)
		return NULL;
	int index = 0;
	for (int i = 0; i < q->size; i++)
	{
		if (q->proc[i]->priority > q->proc[index]->priority)
			index = i;
	}
	struct pcb_t* pop = q->proc[index];
	for (int i = index; i < q->size - 1; i++)
	{
		q->proc[i] = q->proc[i + 1];
	}
	q->size--;
	return pop;
}

