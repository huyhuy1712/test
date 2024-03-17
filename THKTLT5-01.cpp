#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000

bool is_nguyen_am(char c){
	if(c == 'b' || c == 'c' || c =='d' || c == 'g' || c == 'h' || c == 'k' || c == 'l'  || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'x') return false;
	else return true;	
}


void swap(char **a, char **b){
	char *temp;
	temp = *a;
	*a = *b;
	*b = temp;
} 

void SelectionSort(char **s,int length[],int n){
	for(int i = 0; i < n-1; i++){
	int pos_min = i;
	int min = length[i];
	for(int j = i; j < n; j++){
		if(length[j] <= min) {
		min = length[j];
		pos_min = j;
	}
	}
swap(s + i, s + pos_min);
}
}

int main(){
	char s[MAX]; 
	FILE* f = fopen("THI3.INP.txt","r");
	int i = 0;
	int n = 0;
	while(fscanf(f,"%c",&s[i]) != EOF){
		i++;
	}
	char* str[MAX];
	char* token = strtok(s,"\n");
	int j = 0;
	while(token != NULL){
		str[j] = token;
		j++;
		n++;
		token = strtok(NULL,"\n");
	}
	
	
	//Cau 1:
	int count = 0;
	for(int i = 0; i < n; i++){
	 char* temp = strstr(str[i],"que huong"); 
	 if(temp){
	 	count++;
	 }
}
printf("Cau 1: %d\n",count);

//Cau 2:
printf("Cau 2: "); 
for(int i = 0; i < n; i++){
	int c1 = 0;
char t[MAX];
strcpy(t,str[i]);
char* token1 = strtok(t," ");
while(token1 != NULL){
	int len = strlen(token1);
	if(len == 5){
		c1++;
	}
	token1 = strtok(NULL," ");	
}
printf("%d ",c1);
}

// cau 3:
printf("\nCau 3: ");
for(int i = 0; i < n; i++){
	char t[MAX];
	strcpy(t,str[i]);
char* token2 = strtok(t," ");
while(token2){
	int num = 0;
	for(int i = 0; i < strlen(token2); i++){
		if(isalpha(token2[i]) && is_nguyen_am(token2[i])) num++;
	}
	printf("%d ",num);
	token2 = strtok(NULL," ");
}
printf("\n");	
}


//cau 4: 
int k = 0;
int length[n] = {0};
printf("Cau 4: ");
for(int i = 0; i < n; i++){
char t2[MAX];
strcpy(t2,str[i]);
char* token3 = strtok(t2," ");
while(token3){
	length[k]++;
	token3 = strtok(NULL," ");
}
  k++;
}

int length_max = 0;
for(int i = 0; i < n; i++){
	if(length[i] > length_max) length_max = length[i];
}

for(int i = 0; i < n; i++){
	if(length[i] == length_max){
		puts(str[i]);
		printf("%d\n",length_max);
		break;
	}
}


// Cau 5

printf("Cau 5: ");
		SelectionSort(str,length,n);
	for(int i = 0; i < n; i++){
		printf("%s\n",str[i]);
	}
	return 0; 
} 
