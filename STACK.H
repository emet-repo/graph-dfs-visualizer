struct elem {
int data;
struct elem *next;
	     };
typedef struct elem node;
class Stack
 {
 node *top_mem;
     public:
     ~Stack();
     void makenull();
     void push(int member);
     void pop(void);
     char top(void);
     int isempty(void);
 };