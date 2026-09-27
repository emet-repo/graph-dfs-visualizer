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
//  printf("%c ",(char)(t->v+'A'-1));
	}
  }

void init_grafics(void)
{

   /* request auto detection */
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

}
void main(int argc ,char *argv[])
{
FILE *in;
char v1,v2,Ch;
char *tmp = (char*)malloc(1);
int x1,y1,x2,y2;
unsigned len,enter =0 ;
float angle1,angle2,x_c,y_c,Radius,Dist=100.0,angle3;
init_grafics();
if ((in = fopen(argv[1], "rt"))== NULL)
  {
   printf("\nCannot open data file\n");
   return ;
  }
  fscanf(in,"%d %d\n",&V,&E);
  len = (unsigned)ceil(sqrt(V));
  z= (struct node *) malloc(sizeof(struct node));
  z->next =z;
  for (j=1;j<=V;j++) adj[j] = z;
  for (j=1;j<=E;j++) {
   fscanf(in,"%c %c\n",&v1,&v2);
   if(enter ==0 ) {Ch = v1;enter = 1;}
     x = v1 -Ch +1 ;
    y = v2 -Ch+1;
   y1 = (x)%len;
   if (y1==0) y1 = len;
   x1 = 1+(int)(x-y1)/len;

   y2 = (y)%len;
   if (y2==0) y2 = len;
   x2 = 1+(int)(y-y2)/len;
   setcolor(10);
   tmp = " ";
   tmp[0] =v1;
   setcolor(7);
   line(y1*100,x1*100,y2*100,x2*100);
   angle1 = atan((double)x2/(double)y2);
   angle2 = atan((double)x1/(double)y1);
   angle3 = atan(abs((x1-x2)/(y1-y2)));
   x_c = (y1+y2)*50;
   y_c = (x1+x2)*50;
   Radius = sqrt(Dist*Dist+(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
   moveto(x_c,y_c);

   linerel(100,0);
//   arc(x_c,y_c,angle1,angle2,100);
   delay(300);
 //  circle((y1+y2)*50,(x1+x2)*50,3);
   setcolor(10);
   circle(y1*100,x1*100,8);
   setfillpattern(EMPTY_FILL,0);
   floodfill(y1*100,x1*100,10);
   setcolor(12);
   outtextxy(y1*100-3,x1*100-3,tmp);
   setcolor(10);
   circle(y2*100,x2*100,8);
   setfillpattern(EMPTY_FILL,0);
   floodfill(y2*100,x2*100,10);
    tmp[0] =v2;
    setcolor(12);
   outtextxy(y2*100-3,x2*100-3,tmp);
   setcolor(10);

   t= (struct node *) malloc(sizeof(struct node));
   t->v = x;t->next = adj[y];adj[y] = t;
   t= (struct node *) malloc(sizeof(struct node));
   t->v = y;t->next = adj[x];adj[x] = t;
  }
// listdfs();
  getch();
}