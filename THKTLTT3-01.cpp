#include <stdio.h>
#include <stdlib.h> 
int main(){
	int *a;
	int n;
	printf("nhap so luong phan tu: ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int)); // cap phat vung nho cho con tro 
	for(int i = 1; i <= n;i++){
		printf("pham tu %d: ",i);
		scanf("%d",(a+i)); 
	} 
	int k;
	printf("nhap vi tri can xoa: ");
	scanf("%d",&k); 
	for(int i = k; i <= n; i++){
		 *(a+i) = *(a +(i+1)); 
	}
	n--; 
	for(int i = 1; i <= n; i++){
		printf("%d ",*(a+i)); 
	} 
	free(a); // giai phong vung nho 
} 
