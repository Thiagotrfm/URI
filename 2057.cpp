#include <iostream>

using namespace std;

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int d = (24+a+b+c)%24;
	if(d==24) printf("0\n");
	else printf("%d\n", d);
	return 0;
}
