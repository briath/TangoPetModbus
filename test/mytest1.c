#include <stdio.h>

enum qq{A, B, C, D=5, E, F};


int main(){
  int a = A;
  int e = E;
  int c = C;
  int d = D;

  printf("%d %d %d %d", a, e, c, d);



  return 0;
}
