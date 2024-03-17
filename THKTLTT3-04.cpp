#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,m;
	printf("nhap so luong phan tu day a: ");
	scanf("%d",&n);
	printf("nhap so luong phan tu day b: ");
	scanf("%d",&m);
	int *a;
	int *b;
	int *c;
	a =(int*)malloc(n*sizeof(int));
	b = (int*)malloc(m*sizeof(int));
	c = (int*)malloc((n+m)*sizeof(int));
	for(int i = 0; i < n; i++){
		printf("nhap phan tu a[%d]: ",i);
		scanf("%d",a+i);
	}
		for(int i = 0; i < m; i++){
		printf("nhap phan tu b[%d]: ",i);
		scanf("%d",b+i);
	}
	  for(int i = 0; i < n; i++){
	  	*(c+i) = *(a+i);
	  }
	  	int j = 0;
	for(int i = n; i < m+n; i++){
	  	*(c+i) = *(b+j);
	  	j++;
	  }
	for(int i = 0; i < m+n; i++){
		printf("%d ",*(c+i));
}
free(c); 
}
