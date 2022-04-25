#include <stdio.h>
 
void inc (int *n) //funcao normal
{
  (*n)++ ;
}
 
int main ()
{
  void (*fp) (int *) ;		// ponteiro para funcao
 
  fp = inc ;			// ponteiro fp recebe enderedo da funcao inc
 
  int a = 0 ;
  printf ("a vale %d\n", a) ;
 
  inc(&a) ;			// chamada normal
  printf ("a vale %d\n", a) ;
 
  fp(&a) ;			// chamada usando ponteiro para funcao
  printf ("a vale %d\n", a) ;
}