#include <iostream>

using namespace std;

int main(){
	int n, i=1;
	while(scanf("%d", &n)!=EOF){
		if(n){
			printf("Caso %d: %d numeros\n0", i++, ((n*(n+1))/2)+1);
			for(int k=1; k<=n; k++){
				for(int o=1; o<=k; o++){
					printf(" %d", k);
				}
			}
			printf("\n");
		}
		else
			printf("Caso %d: 1 numero\n0\n", i++);
		printf("\n");
	}
	return 0;
}
