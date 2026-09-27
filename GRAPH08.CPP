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
int y_f_1,x_f_1,y_f_2,x_f_2;
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
   x_f_1 = (x)%len;
   if (x_f_1==0) x_f_1 = len;
   y_f_1 = 1+(int)(x-x_f_1)/len;

   x_f_2 = (y)%len;
   if (x_f_2==0) x_f_2 = len;
   y_f_2 = 1+(int)(y-x_f_2)/len;
   setcolor(10);
   tmp = " ";
   tmp[0] =v1;
   setcolor(7);
   line(x_f_1*100,y_f_1*100,x_f_2*100,y_f_2*100);
   angle1 = atan((double)y_f_2/(double)x_f_2);
   angle2 = atan((double)y_f_1/(double)x_f_1);
   angle3 = atan((y_f_1-y_f_2+0.01)/(x_f_1-x_f_2+0.01));

   x_c = (x_f_1+x_f_2)*50;
   y_c = (y_f_1+y_f_2)*50;
   Radius = sqrt(Dist*Dist+(y_f_2-y_f_1)*(y_f_2-y_f_1)+(x_f_2-x_f_1)*(x_f_2-x_f_1));
   moveto(x_c,y_c);
   setcolor(4);
   linerel(30*cos(angle3+M_PI_2),30*sin(angle3+M_PI_2));
//    arc(getx(),gety(),angle3,angle3+M_PI_2,100);
   delay(700);
 //  circle((x_f_1+x_f_2)*50,(y_f_1+y_f_2)*50,3);
   setcolor(10);
   circle(x_f_1*100,y_f_1*100,8);
   setfillpattern(EMPTY_FILL,0);
   floodfill(x_f_1*100,y_f_1*100,10);
   setcolor(12);
   outtextxy(x_f_1*100-3,y_f_1*100-3,tmp);
   setcolor(10);
   circle(x_f_2*100,y_f_2*100,8);
   setfillpattern(EMPTY_FILL,0);
   floodfill(x_f_2*100,y_f_2*100,10);
    tmp[0] =v2;
    setcolor(12);
   outtextxy(x_f_2*100-3,y_f_2*100-3,tmp);
   setcolor(10);

   t= (struct node *) malloc(sizeof(struct node));
   t->v = x;t->next = adj[y];adj[y] = t;
   t= (struct node *) malloc(sizeof(struct node));
   t->v = y;t->next = adj[x];adj[x] = t;
  }
// listdfs();
  getch();
}