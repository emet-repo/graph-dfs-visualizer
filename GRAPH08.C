#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include <dos.h>
#include <math.h>
#define maxV 200
 struct two_coord{
  int coord_x;
  int coord_y;
  } ;
typedef struct two_coord *p_to_coord;
p_to_coord coordinate;
struct node
{ int v;struct node *next;};
struct node *t,*z =NULL;struct node *adj[maxV];
int val[maxV];
int j,V,E,id =0,first,second,vert_count_in_line,adge_length,last_k,Dist;
char *tmp ,*tmp2;
void draw_node(int x,int y ,char* data,unsigned color)
{
   setcolor(10);
   circle(x,y,10);
   setfillpattern(EMPTY_FILL,0);
   floodfill(x,y,10);
   setcolor(color);
 if(strlen(data)==1)  outtextxy(x-3,y-3,data);
    else
    outtextxy(x-8,y-3,data);

}
p_to_coord  make_coordinats(int num)
{
   int ff,ss;
    p_to_coord pp= (struct two_coord *) malloc(sizeof(struct two_coord));
   ff = (num)%vert_count_in_line;
   if (ff==0) ff = vert_count_in_line;
   ss = 1+(int)(num-ff)/vert_count_in_line;
      if(ff==1) pp->coord_x=15;
    else pp->coord_x=((ff-1)*adge_length)%630;
   if(ss==1) pp->coord_y=15;
     else pp->coord_y=((ss-1)*adge_length)%460;
     return pp;

}
 void p_to_connect(int x1,int y1,int x2,int y2,int color)
 {
    float angle ;
    int x_c,y_c;
    angle = abs(atan((y1-y2+0.01)/(x1-x2+0.01)));
     x_c = (x1+x2)/2;
     y_c = (y1+y2)/2;
   moveto(x_c,y_c);
   setcolor(0);
   linerel(Dist*cos(angle+M_PI_2),Dist*sin(angle+M_PI_2));
      setcolor(color);
 }
 void connect_vertexes(int x1,int y1,int x2,int y2)
 {
	line(x1,y1,getx(),gety());
	line(getx(),gety(),x2,y2);
 }

void visit(int k)
  {
    struct node *t;
    float angle ;
    int x_n,y_n,x_c,y_c,x_last,y_last;
    val[k] = ++id;
    tmp = " ";
    tmp2 =" ";
   if(id<10) tmp[0] =(char)(48+id);
     if(id>9)
	  gcvt(id,2, tmp2);

   coordinate = make_coordinats(k);
   x_n = coordinate ->coord_x;
   y_n = coordinate ->coord_y;
   setcolor(7);
    if(id ==1) {
    moveto(x_n,y_n);
    last_k = k;
    x_last = x_n;
    y_last = y_n;
    }
    else {
    y_last = gety();
    x_last = getx();
      p_to_connect(x_n,y_n,x_last,y_last,14);
	for (t = adj[k];t!=z;t=t->next)
	 if(t->v == last_k)  {
//	line(x_last,y_last,getx(),gety());
//	line(getx(),gety(),x_n,y_n);
	connect_vertexes(x_last,y_last,x_n,y_n);
	break;
	}

   moveto(x_n,y_n);
	}

if(id<10)  draw_node(x_n,y_n,tmp,11);
 else   draw_node(x_n,y_n,tmp2,11);

      tmp[0] =(char)(48+val[last_k]);
      gcvt(val[last_k],2, tmp2);

if(val[last_k]<10) draw_node(x_last,y_last,tmp,11);
   else draw_node(x_last,y_last,tmp2,11);
   getch();

    last_k = k;
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
void main(int argc,char* argv[])
{
FILE *in;
char v1,v2,Ch;

int y_f_1,x_f_1,y_f_2,x_f_2;
unsigned enter =0 ;
init_grafics();
if ((in = fopen(argv[1], "rt"))== NULL)
  {
   printf("\nCannot open data file\n");
   return ;
  }
  fscanf(in,"%d %d\n",&V,&E);
  vert_count_in_line = (unsigned)ceil(sqrt(V));
  adge_length = (unsigned)(480/vert_count_in_line);

  z= (struct node *) malloc(sizeof(struct node));
  z->next =z;
  for (j=1;j<=V;j++) adj[j] = z;
  for (j=1;j<=E;j++) {
   fscanf(in,"%c %c\n",&v1,&v2);
   if(enter ==0 ) {Ch = v1;enter = 1;}
     first = v1 -Ch +1 ;
     second = v2 -Ch+1;

   coordinate = make_coordinats(first);
   x_f_1 = coordinate ->coord_x;
   y_f_1 = coordinate ->coord_y;
   coordinate = make_coordinats(second);
   x_f_2 = coordinate ->coord_x;
   y_f_2 = coordinate ->coord_y;
   setcolor(10);
   tmp = (char*)malloc(1);
   tmp2 = (char*)malloc(2);
   tmp = " ";

   setcolor(7);

    Dist = adge_length/12;
   p_to_connect(x_f_1,y_f_1,x_f_2,y_f_2,7);
//   line(x_f_1,y_f_1,getx(),gety());
//   line(getx(),gety(),x_f_2,y_f_2);
    connect_vertexes(x_f_1,y_f_1,x_f_2,y_f_2);
    tmp[0] =v1;

    draw_node(x_f_1,y_f_1,tmp,12);
    tmp[0] =v2;

    draw_node(x_f_2,y_f_2,tmp,12);
   setcolor(10);

   t= (struct node *) malloc(sizeof(struct node));
   t->v = first;t->next = adj[second];adj[second] = t;
   t= (struct node *) malloc(sizeof(struct node));
   t->v = second;t->next = adj[first];adj[first] = t;
  }
 listdfs();
  getch();
}