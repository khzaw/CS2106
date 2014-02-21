// Name : Kaung Htet
// Matric No : A0105860L
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int gb = 0;
  while(malloc(1024*1024*1024)) {
    ++gb;
  }
  printf("The number of gigs allocated is : %d\n",gb);
  return 0;
}
