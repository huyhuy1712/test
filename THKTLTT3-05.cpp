#include <stdio.h>

struct node{
	int data;
	 node *next;
}; 
typedef node* NODE;

struct list{
	NODE head;
	NODE tail;
};

NODE createnode(int data){
	NODE p = new node;
	p->next = NULL;
	p->data = data;
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

bool searchX(list l,int x){
	NODE p = l.head;
	while( p != NULL){
		if(p->data == x){
			return true; 
		} 
		p = p->next;
	}
	return false; 
}

void swap(NODE &a, NODE &b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void sort(list &l){
	for(NODE p = l.head; p->next != NULL; p=p->next){
		for(NODE k = p->next; k!=NULL;k=k->next){
			if(p->data >= k->data){
			swap(p,k);
			}
		else continue;
		}
	}
}

void input(list &l){
	int n;
	printf("nhap so luong phan tu cua danh sach: ");
	scanf("%d",&n);
	for(int i = 0;i < n; i++){
		int data;
		printf("nhap phan tu cua node %d: ",i);
		scanf("%d",&data);
		chencuoi(l,createnode(data));
	}
}

void output(list l){
	for(NODE p = l.head; p != NULL; p = p->next){
		printf("%d ",p->data);
	}
}

int main(){
	list l;
	createlist(l);
	input(l);
	
	printf("cau a:\n");
	int sum = 0;
	for(NODE p = l.head; p != NULL; p=p->next){
	sum += p->data;
	}
	printf("tong cac phan tu trong danh sach la: %d",sum);
	
	printf("\ncau b:\n");
	int x;
	printf("nhap x: ");
	scanf("%d",&x);
	if(searchX(l,x)){
		printf("1"); 
	}
	else{
	printf("0"); 
	}
	
	printf("\ncau c:\n");
	sort(l);
	output(l); 
}
