#include "stack.h"
#include <stdlib.h>
#include <iostream.h>
node *last;
Stack::~Stack()
{
node *current  ;
 while(top_mem!=NULL)
   {
    current = top_mem;
    top_mem = top_mem->next;
    delete current ;
    }
}
void Stack::makenull(void)
{
if(top_mem != NULL) top_mem = NULL;
}
int Stack::isempty(void)
{
if (top_mem==NULL) return(1);
	else return(0);
}

void Stack::push(int member )
{

node *ptr;
if(isempty())
      {
	 top_mem = new node ;
	 if(top_mem ==NULL)
     {
      cout<<"\nNot enough memory to allocate stack\n";
      exit(1);  /* terminate program if out of memory*/
      }

	 top_mem->data = member;
	 top_mem->next = NULL;
	 last = top_mem;
      }
	   else
      {
	  ptr = new node;
	  if(ptr== NULL)
		  {
		   cout<<"\nNot enough memory to allocate stack\n";
		   exit(1);  /* terminate program if out of memory*/
		  }
	  ptr->data = member ;
	  ptr->next =top_mem;
	  top_mem = ptr;
      }
}
char Stack::top(void)
{
if(isempty())
  {
	cout<<"Error .Stack is empty\n";
	exit(1);
  }
return(top_mem->data);
}
void Stack::pop(void)
{
node *tmp;
tmp = top_mem;
top_mem =top_mem->next;
delete tmp;
}
