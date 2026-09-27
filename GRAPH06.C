#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#define maxV 200
struct node
{ int v;struct node *next;};
int j,x,y,V,E;
char Ch;
struct node *t,*z =NULL;struct node *adj[maxV];
int val[maxV];
int id =0,x,y,vert_count_in_line,adge_length;
void visit(int k)
  {
    struct node *t;
    char Ch;
    int x_n,y_n;
    val[k] = ++id;

   x = (k)%vert_count_in_line;
   if (x==0) x = vert_count_in_line;
   y = 1+(int)(k-x)/vert_count_in_line;
   if(x == 1 ) x_n = 10;
    else  x_n = ((x-1)*adge_length)%620;
   if(y == 1 ) y_n = 10;
    else  y_n = ((y-1)*adge_length)%460;

   if(id==1)
     moveto(x_n,y_n);

   else     {
    setcolor(13);
    lineto(x_n,y_n);
    }
   setcolor(14);
   circle(x_n,y_n,10);
    delay(600);
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
//  printf("%c ",(char)(t->v+'A'-1));
	}
  }

void init_grafics(void)
{

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode ,tt;
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

}
void main(int argc ,char *argv[])
{
FILE *in;
char v1,v2;
char *tmp = (char*)malloc(1);
int y_f_1,x_f_1,y_f_2,x_f_2;
unsigned enter =0 ;
init_grafics();
if ((in = fopen(argv[1], "rt"))== NULL)
  {
   printf("\nCannot open data file\n");
   return ;
  }
  fscanf(in,"%d %d\n",&V,&E);
  if(V>E) vert_count_in_line = V;
  else  vert_count_in_line = (unsigned)ceil(sqrt(V));
  adge_length = (unsigned)(480/vert_count_in_line);
  z= (struct node *) malloc(sizeof(struct node));
  z->next =z;
  for (j=1;j<=V;j++) adj[j] = z;
  for (j=1;j<=E;j++) {
   fscanf(in,"%c %c\n",&v1,&v2);
   if(enter ==0 ) {Ch = v1;enter = 1;}
     x = v1 -Ch +1 ;
    y = v2 -Ch+1;
   x_f_1 = (x)%vert_count_in_line;
   if (x_f_1==0) x_f_1 = vert_count_in_line;
   y_f_1 = 1+(int)(x-x_f_1)/vert_count_in_line;

   x_f_2 = (y)%vert_count_in_line;
   if (x_f_2==0) x_f_2 = vert_count_in_line;
   y_f_2 = 1+(int)(y-x_f_2)/vert_count_in_line;
   setcolor(10);
   tmp = " ";
   tmp[0] =v1;
   setcolor(7);
   if(x_f_1==1) x_f_1=10;
    else x_f_1=((x_f_1-1)*adge_length)%620;
   if(y_f_1==1) y_f_1=10;
     else y_f_1=((y_f_1-1)*adge_length)%460;
   if(x_f_2==1) x_f_2=10;
       else x_f_2=((x_f_2-1)*adge_length)%620;
   if(y_f_2==1) y_f_2=10;
    else y_f_2=((y_f_2-1)*adge_length)%460;
   line(x_f_1,y_f_1,x_f_2,y_f_2);
   setcolor(10);
   circle(x_f_1,y_f_1,8);
   setfillpattern(EMPTY_FILL,0);
   floodfill(x_f_1,y_f_1,10);
   setcolor(12);
   outtextxy(x_f_1-3,y_f_1-3,tmp);
   setcolor(10);
   circle(x_f_2,y_f_2,8);
   setfillpattern(EMPTY_FILL,0);
   floodfill(x_f_2,y_f_2,10);
    tmp[0] =v2;
    setcolor(12);
   outtextxy(x_f_2-3,y_f_2-3,tmp);
   setcolor(10);

   t= (struct node *) malloc(sizeof(struct node));
   t->v = x;t->next = adj[y];adj[y] = t;
   t= (struct node *) malloc(sizeof(struct node));
   t->v = y;t->next = adj[x];adj[x] = t;
  }
 listdfs();
  getch();
}