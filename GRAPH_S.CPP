#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define maxV 200
Stack S;
struct graph_node
{ int v;struct graph_node *next;};
int j,x,y,V,E;
struct graph_node *t,*z =NULL;struct graph_node *adj[maxV];
int val[maxV];
int id =0;
void visit(int k)
  {
    struct graph_node *t;
    S.push(k);
    while(!S.isempty()) {
    k = S.top();
    S.pop();
    val[k] = ++id;
    printf("%c ",k+'A'-1);
    for (t = adj[k];t!=z;t=t->next)
    if(val[t->v] == 0)
    {S.push(t->v);    val[t->v] = -1; }

       }
   }
void listdfs(void)
    {
      int k;
      Stack S;
      S.makenull();
      for (k=1;k<=V;k++) val[k] = 0;
      for (k=1;k<=V;k++)
      if(val[k]==0) {
      visit(k);
//	  printf("%c ",(char)(t->v+'A'-1));
	}
  }


void main(int argc ,char *argv[])
{
FILE *in;
char v1,v2;
if ((in = fopen(argv[1], "rt"))== NULL)
  {
   printf("\nCannot open data file\n");
   exit(1);
  }
  fscanf(in,"%d %d\n",&V,&E);
  z= (struct graph_node *) malloc(sizeof(struct graph_node));
  z->next =z;
  for (j=1;j<=V;j++) adj[j] = z;
  for (j=1;j<=E;j++) {
   fscanf(in,"%c %c\n",&v1,&v2);
   x= v1-'A'+1;
   y = v2-'A'+1;
   t= (struct graph_node *) malloc(sizeof(struct graph_node));
   t->v = x;t->next = adj[y];adj[y] = t;
   t= (struct graph_node *) malloc(sizeof(struct graph_node));
   t->v = y;t->next = adj[x];adj[x] = t;
  }
  listdfs();
}