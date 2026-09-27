 struct two_coord{
  int coord_x;
  int coord_y;
  } ;
 typedef struct two_coord *p_to_coord;
 p_to_coord coordinate;
 int id =0,first,second,vert_count_in_line,adge_length,last_k,Dist;
 void draw_node(int x,int y ,char* data,unsigned color);
 p_to_coord  make_coordinats(int num);
 void p_to_connect(int x1,int y1,int x2,int y2,int color);
 void connect_vertexes(int x1,int y1,int x2,int y2)