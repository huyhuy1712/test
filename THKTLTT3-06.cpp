#include <stdio.h>
#include <math.h>
struct dathuc{
	int n;
	 int a[100]; 
}; 

struct node{
	dathuc data;
	node *next; 
}; 
typedef node* NODE;

struct list{
	NODE head;
	NODE tail;
};
NODE createnode(dathuc P){
	NODE p = new node;
	p->next = NULL;
	p->data.n = P.n;
	for(int i = 0; i <= P.n; i++){
	p->data.a[i] = P.a[i];
	}
	return p; 
}

void createlist(list &l){
	l.head = NULL;
	l.tail = NULL;
}

void chencuoi(list &l, NODE p){
	if(l.head == NULL){
		l.head = l.tail = p;
	}
	else{
		l.tail->next = p;
		l.tail = p;
	}
}

void nhapdathuc(dathuc &p){
	printf("nhap bac cua da thuc: ");
	scanf("%d",&p.n);
	while(p.n < 0){
		printf("bac cua da thuc khong dc nho hon 0 !!\n");
}
	for(int i = 0; i <= p.n; i++){
		printf("nhap he so thu %d: ",i);
		scanf("%d",&p.a[i]);
	}	
}

 void input(list &l, int k){
 	for(int i = 0; i < k; i++){
 		dathuc p;
 		printf("\t\t\t--- da thuc %d ---\t\t\t\n",i);
 		nhapdathuc(p);
 		chencuoi(l,createnode(p));
	 }
}
	 
void output(list l){
	for(NODE p = l.head; p != NULL; p=p->next){
		printf("P(a,%d,x)= ",p->data.n);
		if(p->data.n >= 2){
	 	printf("%d + %d*x + ",p->data.a[0],p->data.a[1]);
		for(int i = 2 ; i < p->data.n; i++){
			printf("%d*x^%d + ",p->data.a[i],i); 
		}
		printf("%d*x^%d",p->data.a[p->data.n],p->data.n);
	}
	else if(p->data.n == 0){
		printf("%d",p->data.a[0]);
	}
	else if(p->data.n == 1){
		printf("%d + %d*x",p->data.a[0],p->data.a[1]);
	}
		printf("\n"); 
	}
}
	
	dathuc search(list l, int m){
		NODE k = l.head;
		while(k->data.n != m && k != NULL){
			k = k->next; 
		}
		return k->data; 
	}
	
int tinhgt(list l,int x,int m){
	dathuc p = search(l,m);
	int sum = 0;
	if(p.n == 0){
	return p.a[0];
	}
	else{
		for(int i = 0; i <= p.n; i++){
			sum += p.a[i]*pow(x,i);
		}
		return sum;
	}
} 

void cong2dathuc( dathuc d, dathuc b){
	dathuc c;
	if(d.n > b.n){
		c.n = d.n;
	}
	else if(d.n < b.n) {
	c.n = b.n;
	}
	else{
		c.n = d.n;
	}
	if(c.n == 0){
		printf("tong hai da thuc la = %d",d.a[0]+b.a[0]);
	}
	else if(c.n == 1){
		printf("tong 2 da thuc = %d +%d*x",d.a[0]+b.a[0],d.a[1]+b.a[1]);
	}
	else if(c.n >= 2){
	printf("tong 2 da thuc = %d +%d*x + ",d.a[0]+b.a[0],d.a[1]+b.a[1]);
	for(int i = 2; i < c.n; i++){
		printf("%d*x^%d + ",d.a[i]+b.a[i],i);
	}
	printf("%d*x^%d",d.a[c.n]+b.a[c.n],c.n);	
	}
	printf("\n"); 
} 

void nhan2dathuc(dathuc b,dathuc c){
	dathuc result;
	result.n = b.n + c.n;
	for(int i = 0; i <= result.n; i++){ // gan toan bo he so thanh 0
		result.a[i] = 0; 
	}
	for(int i = 0; i <= b.n;i++){
		for(int j = 0; j<=c.n;j++){
			result.a[i+j] += b.a[i] * c.a[j];
		}
	}
	printf("tich 2 da thuc = ");
	if(result.n == 0){
	printf("%d",result.a[0]);	
	}
	else if(result.n == 1){
		printf("%d + %d*x",result.a[0],result.a[1]);
	}
	else if(result.n >= 2){
		printf("%d + %d*x + ",result.a[0],result.a[1]);
	for(int i = 2; i < result.n; i++){
		printf("%d*x^%d + ",result.a[i],i);
	}
	printf("%d*x^%d",result.a[result.n],result.n);
	}
	printf("\n");
} 
int main(){
		int k;
 	printf("nhap so da thuc: ");
 	scanf("%d",&k);
	list l;
	createlist(l);
	printf("cau a: \n");
	input(l,k);
	printf("cau b: \n");
	output(l);
	
	printf("cau c: \n");
	int n,x;
	printf("nhap x: ");
	scanf("%d",&x);
	printf("nhap bac cua phuong trinh can tinh: ");
	scanf("%d",&n);
	printf("P(a,%d,%d)= %d\n",n,x,tinhgt(l,x,n));

	printf("cau d: \n");
	int q,w;
	printf("nhap bac cua da thuc 1: ");
	scanf("%d",&q);
	printf("nhap bac cua da thuc 2: ");
	scanf("%d",&w);
	dathuc d = search(l,q);
	dathuc b = search(l,w);
	cong2dathuc(d,b);
	
	printf("cau e: \n");
	nhan2dathuc(d,b);
}
