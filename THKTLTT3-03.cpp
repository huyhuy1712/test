#include <stdio.h>
#include <stdlib.h>
#include <math.h>
bool checksnt(int a){
	if(a <= 1) return false;
	else{
	for(int i = a - 1; i >= 2; i--){
		if(a%i == 0) return false;
	}
	return true;
	} 
} 
void xoa(int *a,int& n,int k){
	for(int i = k; i <= n; i++){
	*(a+i) = *(a+i+1);
	} n--;
}
int main(){
	int n;
	int *a;
	printf("nhap so luong phan tu: ");
	scanf("%d",&n); 
	a = (int*)malloc(n*sizeof(int));
	for(int i = 1; i <= n; i++){
		printf("nhap phan tu %d: ",i);
		scanf("%d",a+i);
	}
	for(int i = 1; i <= n; i++){
		if(checksnt(*(a+i))){
		xoa(a,n,i);
		i--;
		}
		else continue;
	}
	for(int i = 1; i <= n; i++ ){
		printf("%d ",*(a+i));
	}
	free(a);
} 
