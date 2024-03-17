#include <stdio.h>
#include <stdlib.h> 
int main(){
	int n;
	int *a;
	printf("nhap so luong phan tu: ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++){
		printf("nhap phan tu %d: ",i);
		scanf("%d",a+i);
	} 
	int k,x;
	printf("nhap phan tu can chen: ");
	scanf("%d",&x);
	printf("nhap vi tri can chen: ");
	scanf("%d",&k);
	for(int i = n-1; i >= k; i-- ){
		*(a+i+1) = *(a+i);
	}
	*(a+k) = x;
		n++;
	for(int i = 0; i < n; i++){
		printf("%d ",*(a+i));
	}
	free(a); 

} 
