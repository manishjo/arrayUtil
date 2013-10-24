#include <stdio.h>
#define sum(x) sumof##x(5)


void sumofint(x){
	int b=x+x;
	printf("%d",b);
}

int main(){
	sum(int);
	return 0;
}