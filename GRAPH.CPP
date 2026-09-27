#include <stdio.h>
#include <stdlib.h>
#define maxV 200
struct node
{ int v;struct node *next;};
int j,x,y,V,E;
struct node *t,*z =NULL;struct node *adj[maxV];
int val[maxV];
int id =0;
void visit(int k)
  {
    struct node *t;
    val[k] = ++id;

    for (t = adj[k];t!=z;t=t->next){
    if(val[t->v] == 0)  {
    visit(t->v);
			}

       }
   }
void listdfs(void)
    {
      int k;
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
   return 1;
  }
  fscanf(in,"%d %d\n",&V,&E);
  z= (struct node *) malloc(sizeof(struct node));
  z->next =z;
  for (j=1;j<=V;j++) adj[j] = z;
  for (j=1;j<=E;j++) {
   fscanf(in,"%c %c\n",&v1,&v2);
   x= v1-'A'+1;
   y = v2-'A'+1;
   t= (struct node *) malloc(sizeof(struct node));
   t->v = x;t->next = adj[y];adj[y] = t;
   t= (struct node *) malloc(sizeof(struct node));
   t->v = y;t->next = adj[x];adj[x] = t;
  }
  listdfs();
}