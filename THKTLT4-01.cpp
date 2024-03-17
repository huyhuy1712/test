#include <stdio.h>
#include <math.h>
bool is_scp(int n){
		int c = 0;
		for(int i = n ; i > 0; i--){
			if(sqrt(n) == i) c++;
		}
		if(c != 0) return true;
		else return false;
}
 
 bool is_shc(int n){
	int temp = 0;
 	for(int i = 1; i < n; i++){
 		if(n%i == 0){
 			temp += i; 
			}
	 }    
	  if(temp == n && n != 1) return true;
	 else return false; 
}
	int sl(int n){
	int count = 0;  
	while(n != 0){
		n/=10;
		count++; 
	} 	
	 return count; 
}

bool is_arm(int n){
int Ar = 0, t = n;
	while(n != 0){
		int temp = n % 10;
		Ar += pow(temp,sl(t));
		n/=10;
	} 
	if(t == Ar) return true;
	else return false;
}

bool is_snt(int n){
	if(n <= 1) return false;
	else{
		int c = 0;
		for(int i = 2; i <= sqrt(n); i++){
			if(n%i == 0) c++;
		}
		if(c == 0) return true;
		else return false;
	}
}

bool is_sdx(int n){
	int t = n;
		int sdx = 0;
		while(n != 0){
			int temp = n % 10;
			sdx = sdx*10 + temp; 
			n /= 10;
		} n = t;
		if( n == sdx) return true;
		else return false;
}
int main(){
	FILE *f;
	FILE *fo; 
	f = fopen("THI2.INP.txt","r");
	fo = fopen("THI2.OUT.txt","w"); 
	if(f == NULL){
		printf("Loi Khong doc duoc file!!");
		return 1; 
	}
	else{ 
	 int a[100];
	int n = 0;
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%d",&a[i]);
		n++;
		i++; 
	}
	
fprintf(fo,"Cau a: ");
int c0 = 0,c1 = 0,c2 = 0,c3 = 0,c4 = 0;
	for(int i = 0; i < n; i++){
		if(is_scp(a[i]) == true) c0++;
		if(is_shc(a[i]) == true) c1++;
		if(is_arm(a[i]) == true) c2++;
		if(is_snt(a[i]) == true) c3++;
		if(is_sdx(a[i]) == true) c4++;
	}
	fprintf(fo,"%d %d %d %d %d\n",c0,c1,c2,c3,c4);
	fclose(f); 
	fclose(fo); 
} 
}
