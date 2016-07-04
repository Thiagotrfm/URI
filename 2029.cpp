#include <iostream>

using namespace std;

int main(){
	float v, r, x;
	while(scanf("%f %f", &v, &r)!=EOF){
		x = 3.14*(r/2.0)*(r/2.0);
		printf("ALTURA = %.2f\nAREA = %.2f\n", v/x, x);
	}
	return 0;
}
