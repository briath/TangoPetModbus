#include <stdio.h>

enum qq{A, B, C, D=5, E, F = 5};


int main(){
  int a = A;
  int e = E;
  int c = C;
  int d = D;

  printf("%d %d %d %d\n", a, e, c, d);
  printf("%d", F);



  return 0;
}
