#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char hoten[30];
	char manv[10];
	bool gt;
	double luong;
	double thuong;
	double phat;
	double hsluong;
}nhanvien;


void nhap(nhanvien *a, int &n){
	printf("\nNhap so luong nhan vien"); scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("\nnhan vien thu %d\n", i+1); fflush(stdin);
		printf("ho ten:"); gets(a[i].hoten);
		printf("Ma nv:"); gets(a[i].manv);
		printf("gioi tinh:"); scanf("%d", &a[i].gt);
		printf("luong:"); scanf("%lf", &a[i].luong);
		printf("thuong:"); scanf("%lf", &a[i].thuong);
		printf("phat:"); scanf("%lf", &a[i].phat);
		printf("he so luong:"); scanf("%lf", &a[i].hsluong);
	}
}

void xuatfile(nhanvien *a, int n, FILE*f){
	f=fopen("BAI8.OUT","at");
	for(int i=0; i<n; i++){
		fprintf(f,"\n%4d%30s%10s",i+1,a[i].hoten,a[i].manv);
			if(a[i].gt==0)  fprintf(f," nam  ");
				else fprintf(f," nu  ");
		fprintf(f,"\n%30lf%30lf%30lf%30lf",a[i].luong,a[i].thuong,a[i].phat,a[i].hsluong);
	}
	fclose(f);
}

void hsluongmax(nhanvien *a, int n){
	double m= a[0].hsluong;
	for(int i=0; i<n; i++)
		if(a[i].hsluong>m) m=a[i].hsluong;
	for(int i=0; i<n; i++)
		if(a[i].hsluong==m){
			printf("\n%4d%30s%10s",i+1,a[i].hoten,a[i].manv);
			if(a[i].gt==0)  printf(" nam  ");
				else printf(" nu  ");
			printf("\n%30lf%30lf%30lf%30lf",a[i].luong,a[i].thuong,a[i].phat,a[i].hsluong);
		}  
}

void thuclinhnumax(nhanvien *a, int n){
	double m;
	for(int i=0; i<n; i++)
		if(a[i].gt==1){
			m = a[i].thuong+a[i].luong-a[i].phat;
			break;
		}
	for(int i=0; i<n; i++)
		if(a[i].thuong+a[i].luong-a[i].phat>m && a[i].gt==1){
			m=a[i].thuong+a[i].luong-a[i].phat;
		}
	for(int i=0; i<n; i++){
		if(a[i].thuong+a[i].luong-a[i].phat==m && a[i].gt==1){
			printf("\n%4d%30s%10s",i+1,a[i].hoten,a[i].manv);
			if(a[i].gt==0)  printf(" nam  ");
				else printf(" nu  ");
			printf("\n%30lf%30lf%30lf%30lf",a[i].luong,a[i].thuong,a[i].phat,a[i].hsluong);
		}
	}
}

void luonglonhon(nhanvien *a, int n, double x){
	for(int i=0; i<n; i++)
		if(a[i].luong>=x){
			printf("\n%4d%30s%10s",i+1,a[i].hoten,a[i].manv);
				if(a[i].gt==0)  printf(" nam  ");
					else printf(" nu  ");
			printf("\n%30lf%30lf%30lf%30lf",a[i].luong,a[i].thuong,a[i].phat,a[i].hsluong);
		}
	
}

void ttnhanvien(nhanvien *a, int n, char z[30]){
	for(int i=0; i<n; i++)
		if (strcmp(a[i].hoten,z)==0){
			printf("\n%4d%30s%10s",i+1,a[i].hoten,a[i].manv);
				if(a[i].gt==0)  printf(" nam  ");
					else printf(" nu  ");
			printf("\n%30lf%30lf%30lf%30lf",a[i].luong,a[i].thuong,a[i].phat,a[i].hsluong);
	}
}
int main(){
	nhanvien *a;
	int n;
	double x; char z[30];
	FILE*f;
	a=(nhanvien*)malloc(20*sizeof(nhanvien));
	nhap(a,n);
	xuatfile(a,n,f);
	printf("nhan vien he so luong cao nhat");
	hsluongmax(a,n);
	printf("nhan vien nu thuc linh cao nhat");
	thuclinhnumax(a,n);
	printf("luong nhan vien lon hon hoac bang"); scanf("%lf", &x);
	luonglonhon(a,n,x);
	fflush(stdin);
	printf("nhap ten nhan vien");  gets(z);
	ttnhanvien(a,n,z);
	return 0;
}








