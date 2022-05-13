#include<stdio.h>
#include<iostream>
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
	double thuclinh;
} nhanvien;

using namespace std;

double heSoLuongCaoNhat = 0;
double thucLanhNuCaoNhat = 0;

void nhap(nhanvien *a, int &n){
	printf("\nNhap so luong nhan vien: "); scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("\nnhan vien thu %d\n", i+1); fflush(stdin);
		printf("ho ten:"); cin>>a[i].hoten;
		printf("Ma nv:"); cin>>a[i].manv;
		printf("goi tinh:"); scanf("%d", &a[i].gt);
		printf("luong:"); scanf("%lf", &a[i].luong);
		printf("thuong:"); scanf("%lf", &a[i].thuong);
		printf("phat:"); scanf("%lf", &a[i].phat);
		printf("he so luong:"); scanf("%lf", &a[i].hsluong);

		a[i].thuclinh = a[i].luong + a[i].thuong - a[i].phat;
		// tim tien thuc lanh cua nu cao nhat
		if (a[i].gt == 1 && a[i].thuclinh > thucLanhNuCaoNhat) {
			thucLanhNuCaoNhat = a[i].thuclinh;
		}

		if (a[i].hsluong > heSoLuongCaoNhat) {
			heSoLuongCaoNhat = a[i].hsluong;
		}
	}
}

void hienThiThongTin(nhanvien nv) {
	printf("\n ======= Thong tin nhan vien %10s ==== \n", nv.manv);
	printf("Ho ten: %30s\n", nv.hoten);
	printf("Gioi tinh: %3s\n", (nv.gt == 0 ? "nam" : "nu ") );
	printf("Luong: %30lf\n", nv.luong);
	printf("Thuong: %30lf\n", nv.thuong);
	printf("Phat: %30lf\n", nv.phat);
	printf("He so: %30lf\n", nv.hsluong);
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
	for(int i=0; i<n; i++) {
		if(a[i].hsluong == heSoLuongCaoNhat){
			hienThiThongTin(a[i]);
		}  
	}
}

void thuclinhnumax(nhanvien *a, int n){
	for(int i=0; i<n; i++) {
		if (a[i].gt == 0) {
			continue;
		}

		if(a[i].thuclinh > thucLanhNuCaoNhat){
			hienThiThongTin(a[i]);
		}
	}
}

int main(){
	nhanvien *a;
	int n;
	FILE*f;
	a=(nhanvien*)malloc(20*sizeof(nhanvien));
	nhap(a,n);
	xuatfile(a,n,f);
	hsluongmax(a,n);
	thuclinhnumax(a,n);
	return 0;
}








