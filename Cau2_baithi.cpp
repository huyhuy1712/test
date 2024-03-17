#include <stdio.h>
#include <string.h>
#define MAX 1000
struct MH{
	int MMH;
	char TenMH[MAX];
	float DiemGiuaKi;
	float DiemCuoiKi;
}; 
struct sv{
	
	int MSSV;
	char HoTen[MAX]; 
	MH dsmh[MAX];
};
struct dssv{
	int n;
	sv a[MAX];
};
 void nhap1sv(sv &x){
	printf( "\nNhap MSSV: ");
	scanf("%d",&x.MSSV);
	fflush(stdin);
	printf( "\nNhap ho ten: ");
	gets(x.HoTen);
	printf( "\nNhap MMH: ");
	scanf( "%d",&x.dsmh->MMH);
	fflush(stdin);
	
	
	printf("\nNhap TenMH: ");
	gets(x.dsmh->TenMH);
	printf("\nNhap DiemGiuaKi: ");
	scanf("%f",&x.dsmh->DiemGiuaKi);
		gets(x.dsmh->TenMH);
	printf("\nNhap Diemcuoiki: ");
	scanf("%f",&x.dsmh->DiemCuoiKi);
 }
 int main(){
 	dssv x;
 	scanf("%d",&x.a->dsmh.MMH);
 } 
