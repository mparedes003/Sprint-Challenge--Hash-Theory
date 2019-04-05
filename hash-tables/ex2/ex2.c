#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "hashtable.c" // import hashtable.c so you have access to the hash_table functions
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // YOUR CODE HERE
  // Use a for loop to construct the ht
  for (int i = 0; i < length; i++)
  {
    // insert all tickets inside the ht
    // key = source and value = destination
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  // Build the route
  // Route is an array
  // Use a for loop to construct the array
  for (int i = 1; i < length; i++)
  {
    // Assign the value of each destination in the route[i] array
    // To get the 'i'th location in the route
    // Use hash_table_retrieve function where key = route[i - 1]
    route[i] = hash_table_retrieve(ht, route[i - 1]);
  }

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
