/**
 * \file join_list.c
 * \brief  join list
 * \author MailG <gomailgm@gmail.com>
 * \date  Thursday, February 20, 2014 05:37:55 CST
 * 
 */
/* $Id */

#include <stdio.h>
#include <stdlib.h>

// asc order 
typedef struct LinkNode{
	int value;
	struct LinkNode *next;
} LN;


LN* join_link(LN *h, LN *k)
{
	LN *last = NULL;
	LN *out = NULL;

	out = k;
		
	while (h) {
		if (!k) {
			break;
		}
		if (h->value > k->value) {
			last = k;
			k = k->next;
		} else {
			LN *next_iterator = h->next;
			if (!last) { 
				out = h;				
				out->next = k;
				last = out;
			} else {
				last->next = h;
				last->next->next = k;
			}
			h = next_iterator;
		}
	}
	
	if (last && h && h->value > last->value) {
		last->next = h;
	}

	return out;
}

int display_link(LN* l)
{
	while (l) {
		fprintf(stderr, "%d ", l->value);
		l = l->next;
	}
}

int main()
{
	LN a[10];
	LN b[10];
	int i, j;
	
	for (i = 0; i < 9; i++) {
		a[i].next = &a[i+1];
		a[i].value = 2*i;
		b[i].next = &b[i+1];
		b[i].value = 2*i+1;
	}
	a[9].value = 2*9;
	a[9].next = NULL;
	b[9].value = 2*9 + 1;
	b[9].next = NULL;


	display_link(a);
	fprintf(stderr, "\n");
	display_link(b);
	fprintf(stderr, "\n");
	display_link(join_link(a, b));
	fprintf(stderr, "\n");
}
