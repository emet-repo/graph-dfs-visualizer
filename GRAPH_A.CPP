#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <fstream.h>
#include <stdlib.h>
#include<iostream.h>

#include "graph.h"
#include "coord.h"
#define maxV 200

 struct node
 { int v;struct node *next;};
 int id =0,first,second,Dist,last_k;
 int  vert_count_in_line,adge_length;
  p_to_coord coordinate;
struct node *t,*z =NULL;struct node *adj[maxV];
int val[maxV];
int j,V,E;
char *tmp ,*tmp2;

void error (char *s,char *s2)
 {
  cerr<<s<<" " <<s2<<endl;
  exit(1);
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
    if(id ==1) {
     connect_vertexes(x_n,y_n,x_n,y_n);
     last_k = k;
     x_last = x_n;
    y_last = y_n;
    }
    else {
    y_last = get_curr_y();
    x_last = get_curr_x();
	p_to_connect(x_n,y_n,x_last,y_last,14);
	for (t = adj[k];t!=z;t=t->next)
	 if(t->v == last_k)  {
	connect_vertexes(x_last,y_last,x_n,y_n);
	break;
	}

   connect_vertexes(x_n,y_n,x_n,y_n);
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

void main(int argc,char* argv[])
{
char v1,v2,Ch;
   filebuf f1;

int y_f_1,x_f_1,y_f_2,x_f_2;
unsigned enter =0 ;
istream from(&f1);
init_graphics();
   if (f1.open(argv[1],ios::in) == 0)
   error("cannot open data file",argv[1]);
    from>>V>>E;
  vert_count_in_line = (unsigned)ceil(sqrt(V));
  adge_length = (unsigned)(480/vert_count_in_line);

  z= (struct node *) malloc(sizeof(struct node));
  z->next =z;
  for (j=1;j<=V;j++) adj[j] = z;
  for (j=1;j<=E;j++) {
   from>>v1>>v2;
   if(enter ==0 ) {Ch = v1;enter = 1;}
     first = v1 -Ch +1 ;
     second = v2 -Ch+1;

    coordinate = make_coordinats(first);
    x_f_1 = coordinate ->coord_x;
    y_f_1 = coordinate ->coord_y;
    coordinate = make_coordinats(second);
    x_f_2 = coordinate ->coord_x;
    y_f_2 = coordinate ->coord_y;
   tmp = (char*)malloc(1);
   tmp2 = (char*)malloc(2);
   tmp = " ";
 //  getch();

    Dist = adge_length/12;
    p_to_connect(x_f_1,y_f_1,x_f_2,y_f_2,7);
    connect_vertexes(x_f_1,y_f_1,x_f_2,y_f_2);
    tmp[0] =v1;
     draw_node(x_f_1,y_f_1,tmp,12);


    tmp[0] =v2;

    draw_node(x_f_2,y_f_2,tmp,12);

//   t= (struct node *) malloc(sizeof(struct node));
   t = new struct node;
   t->v = first;t->next = adj[second];adj[second] = t;
   t= (struct node *) malloc(sizeof(struct node));
   t->v = second;t->next = adj[first];adj[first] = t;
  }
 listdfs();
  getch();
}