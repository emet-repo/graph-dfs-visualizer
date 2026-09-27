#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define maxV 200
struct node
{ int v;struct node *next;};
int j,x,y,V,E;
struct node *t,*z =NULL;struct node *adj[maxV];
int val[maxV];
int id =0,last;
int step = 20,X_s = 1,Y_s =1,X_G,Y_G;
int is_exist(int a,int b) {
struct node *t;
if(a==b) return 1 ;
for (t = adj[a];t!=z;t=t->next){
if (t->v==b)    {
			return 1;
			break;
		}
	}
return 0;
}
void visit(int k)

  {
    struct node *t;
    val[k] = ++id; /*
    if(is_exist(last,k)){
    printf("%c",(char)(last+'A'-1));
    printf("%c ",(char)(k+'A'-1));
     lineto(last*20,k*20);
     }
     last = k ;
		     */
    for (t = adj[k];t!=z;t=t->next){
    if(val[t->v] == 0)  {
    visit(t->v);
			}

       }
   }
void listdfs(void)
    {
      int k;
      last  = 1;
      for (k=1;k<=V;k++) val[k] = 0;
      for (k=1;k<=V;k++)
      if(val[k]==0) {
      visit(k);

	}
  }


void main(int argc ,char *argv[])
{
FILE *in;
char v1,v2;

    int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);

   }
      cleardevice();

if ((in = fopen(argv[1], "rt"))== NULL)
  {
   printf("\nCannot open data file\n");
   return ;
  }
  fscanf(in,"%d %d\n",&V,&E);
  z= (struct node *) malloc(sizeof(struct node));
  z->next =z;
  for (j=1;j<=V;j++) adj[j] = z;
  for (j=1;j<=E;j++) {
   fscanf(in,"%c %c\n",&v1,&v2);
   x= v1-'A'+1;
   y = v2-'A'+1;
//   if(x==1) X_G = 11 ;else X_G = x*step ;
  // if(y==1) X_G = 11 ;else Y_G = y*step ;
//   line(X_G,X_G,Y_G,X_G);
  // circle(X_G,X_G,10);
 //  circle(Y_G,X_G,10);
   t= (struct node *) malloc(sizeof(struct node));
   t->v = x;t->next = adj[y];adj[y] = t;
   t= (struct node *) malloc(sizeof(struct node));
   t->v = y;t->next = adj[x];adj[x] = t;
  }
  listdfs();
    for (j=1;j<=V;j++)
	 for (t = adj[j];t!=z;t=t->next)
	      line(j*step,(t->v)*step,j*step,(t->v)*step);
}