#include "stdio.h"
#include "string.h"
#include "mylib.h"
#include "conio.h"
void foo(){
    exit(0);
}
void menu(){

	gotoxy(30,5); vebang(1,195);
	gotoxy(31,5); vebang(50,196); printf("%c",180);
	gotoxy(30,6); printf("%c",179);
	gotoxy(81,6); printf("%c",179);
	gotoxy(30,7); printf("%c",179);
	gotoxy(81,7); printf("%c",179);
	gotoxy(81,9); printf("%c",179);
	gotoxy(81,11); printf("%c",179);
	gotoxy(81,8); printf("%c",179);
	gotoxy(30,9); printf("%c",179);
	gotoxy(30,10); printf("%c",179);
	gotoxy(30,11);printf("%c",179);
	gotoxy(30,11);printf("%c",179);
	gotoxy(81,10); printf("%c",179);
	gotoxy(30,8);printf("%c",179);
	gotoxy(30,14); printf("%c",179);
	gotoxy(30,13);printf("%c",179);
	gotoxy(30,14); printf("%c",179);
	gotoxy(30,15); printf("%c",195);	
	gotoxy(81,12);printf("%c",179);
	gotoxy(30,12);printf("%c",179);
	gotoxy(81,14);printf("%c",179);
	gotoxy(81,13);printf("%c",179);
	gotoxy(31,15);vebang(50,196); printf("%c",180);
	gotoxy(31,17);vebang(50,196); printf("%c",217);
	gotoxy(81,16);printf("%c",179);
	gotoxy(30,16);printf("%c",179);
	gotoxy(30,17);printf("%c",192);
	gotoxy(31,3);vebang(50,196); printf("%c",191);
	gotoxy(30,4);printf("%c",179);
	gotoxy(30,3);printf("%c",218);
	gotoxy(81,4);printf("%c",179);
	gotoxy(48,4);printf("MENU HE THONG");
	gotoxy(44,6);  printf("1. QUAN LY SAN PHAM");
	gotoxy(44,8);  printf("2. QUAN LY NHAN VIEN");
	gotoxy(44,10); printf("3. QUAN LY KHACH HANG");
	gotoxy(44,12); printf("4. THONG KE BAO CAO");
	gotoxy(44,14); printf("6. THOAT KHOI HE THONG");
	
	
	
	
}

void pressAnyKey() {
   gotoxy(0,29) ;printf ("Bam phim bat ky de tiep tuc...");
    getch();
    system("cls");
    menu();
}
 struct Ngaynhap{
	int ngay;// 1<= ngay <= 31
	int thang;// 1<= thang <= 12
	int nam; //0 <= nam <= 65535
}date;

typedef struct 
{
	char masp[8];
	char tensp[30];
	Ngaynhap date;
	int soluong;
	long int giasp;
	char hang[10];
	char kieudang[10];
	char a[5];
}SP; 
void xoasp()
{
	char maspcx[40];
	FILE *f, *f2;
	SP pf;
	int var = 0; 
	fflush(stdin);
	printf("\nNhap Ma sp can xoa: ");
	gets(maspcx);
	f = fopen("Sanpham.txt", "r");
	f2 = fopen("Sanphamcpy.txt", "w");  
	int kt=0;
	while(!feof(f)) 
	{
		fread(&pf, sizeof(pf), 1, f);
		if(strcmp(pf.masp, maspcx) == 0) 
		kt=1;
		else 
		{
			fwrite(&pf, sizeof(pf), 1, f2);
			var++;
		} 
			 
	}
	fclose(f);
	fclose(f2);
	if (kt==1)
	{
		printf("\nXoa thanh cong: %s ", pf.masp); 
	}
	
	f = fopen("Sanpham.txt", "w"); 
	f2 = fopen("Sanphamcpy.txt", "r");
	int i = var; 
	for(i = 1; i <= var; i++) 
	{
			fread(&pf, sizeof(pf), 1, f2);
			fwrite(&pf, sizeof(pf), 1, f); 			

	}
	fclose(f); 
	fclose(f2); 
} 

void timsp()
{
	FILE *f;
	char maspct[40];
	int found = 0;
	SP pf; 
	fflush(stdin);
	gotoxy(30,5);printf("Nhap ma sp can tim: "); 
	gets(maspct);
	f = fopen("Sanpham.txt", "r");
	while(!feof(f) && found == 0)
	{
		fread(&pf, sizeof(pf), 1, f);
		if(strcmp(pf.masp, maspct) == 0)
		found = 1;
	}
	fclose(f);
	if(found == 1)
	{
	gotoxy(55,2); printf("THONG TIN SAN PHAM CAN TIM");
	//Header - Phan dau cua bang
	gotoxy(1,3); vebang(1,218);//Ve goc trai tren cua bang
	gotoxy(2,3); vebang(4,196); printf("%c",194);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,3); vebang(15,196);printf("%c",194);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,3); vebang(30,196);printf("%c",194);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,3); vebang(12,196);printf("%c",194);//do rong cot ngay nhap hang=12,ky tu chia cot
	gotoxy(67,3); vebang(12,196);printf("%c",194);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,3); vebang(11,196);printf("%c",194);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,3); vebang(11,196);printf("%c",194);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,3); vebang(11,196);printf("%c",191);//do rong cot hang =11 , ky tu chia cot
	gotoxy(1,4);  printf("%c%s%c%10s%6c%23s%8c%11s%2c%10s%3c%8s%4c%8s%4c%11s%1c",179," TT ",179,"Ma SP",179," Ten San Pham",179,"Ngay Nhap",179,"So luong",179," Gia SP",179,"Hang",179,"Kieu dang",179);
	gotoxy(1,5); vebang(1,195);
	gotoxy(2,5); vebang(4,196); printf("%c",197);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,5); vebang(30,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,5); vebang(12,196);printf("%c",197);//do rong cot ngay nhap hang,ky tu chia cot
	gotoxy(67,5); vebang(12,196);printf("%c",197);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,5); vebang(11,196);printf("%c",197);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,5); vebang(11,196);printf("%c",197);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,5); vebang(11,196);printf("%c",180);//do rong cot hang =11 , ky tu chia cot
		
		gotoxy(1,6); printf("%c",179);
		gotoxy(1,7); printf("%c",192);
		gotoxy(2,7);vebang(113,196); printf("%c",217);		
		gotoxy(6,6); printf("%c",179);		
		gotoxy(22,6); printf("%c",179);		
		gotoxy(53,6); printf("%c",179);		
		gotoxy(66,6); printf("%c",179);		
		gotoxy(79,6); printf("%c",179);		
		gotoxy(91,6); printf("%c",179);
		gotoxy(103,6); printf("%c",179);	
		gotoxy(115,6); printf("%c",179);

		gotoxy(6,7); printf("%c",193);
		gotoxy(22,7); printf("%c",193);
		gotoxy(53,7); printf("%c",193);
		gotoxy(66,7); printf("%c",193);
		gotoxy(79,7); printf("%c",193);
		gotoxy(91,7); printf("%c",193);
		gotoxy(103,7); printf("%c",193);
		gotoxy(8,6);printf("%s",pf.masp);
		gotoxy(24,6);printf("%s",pf.tensp);
		gotoxy(55,6);printf("%d/%d/%d",pf.date.ngay,pf.date.thang,pf.date.nam);
		gotoxy(68,6);printf("%d",pf.soluong);
		gotoxy(81,6);printf("%li",pf.giasp);	
		gotoxy(93,6);printf("%s",pf.hang);
		gotoxy(105,6);printf("%s",pf.kieudang); 	
	}
	else 
	{
		printf("\nKhong tim thay san pham can tim %s", maspct);
	}
} 
void inra() 
{	int b=6;
	SP pf;
	FILE *f;
	int i, n;
	f = fopen("Sanpham.txt","r");
	gotoxy(55,2); printf("THONG TIN SAN PHAM TRONG KHO");
	//Header - Phan dau cua bang
	gotoxy(1,3); vebang(1,218);//Ve goc trai tren cua bang
	gotoxy(2,3); vebang(4,196); printf("%c",194);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,3); vebang(15,196);printf("%c",194);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,3); vebang(30,196);printf("%c",194);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,3); vebang(12,196);printf("%c",194);//do rong cot ngay nhap hang=12,ky tu chia cot
	gotoxy(67,3); vebang(12,196);printf("%c",194);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,3); vebang(11,196);printf("%c",194);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,3); vebang(11,196);printf("%c",194);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,3); vebang(11,196);printf("%c",191);//do rong cot hang =11 , ky tu chia cot
	gotoxy(1,4);  printf("%c%s%c%10s%6c%23s%8c%11s%2c%10s%3c%8s%4c%8s%4c%11s%1c",179," TT ",179,"Ma SP",179," Ten San Pham",179,"Ngay Nhap",179,"So luong",179," Gia SP",179,"Hang",179,"Kieu dang",179);
	gotoxy(1,5); vebang(1,195);
	gotoxy(2,5); vebang(4,196); printf("%c",197);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,5); vebang(30,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,5); vebang(12,196);printf("%c",197);//do rong cot ngay nhap hang,ky tu chia cot
	gotoxy(67,5); vebang(12,196);printf("%c",197);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,5); vebang(11,196);printf("%c",197);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,5); vebang(11,196);printf("%c",197);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,5); vebang(11,196);printf("%c",180);//do rong cot hang =11 , ky tu chia cot

	
	
	
	
			//Phan than bang
	
	
	fread(&pf, sizeof(pf), 1, f); 
	while(!feof(f))
	{
		
		gotoxy(8,b);printf("%s",pf.masp);
		gotoxy(24,b);printf("%s",pf.tensp);
		gotoxy(55,b);printf("%d/%d/%d",pf.date.ngay,pf.date.thang,pf.date.nam);
		gotoxy(68,b);printf("%d",pf.soluong);
		gotoxy(81,b);printf("%li",pf.giasp);	
		gotoxy(93,b);printf("%s",pf.hang);
		gotoxy(105,b);printf("%s",pf.kieudang); 
		
		gotoxy(1,b); printf("%c",179);
		gotoxy(6,b); printf("%c",179);
		gotoxy(22,b); printf("%c",179);
		gotoxy(53,b); printf("%c",179);
		gotoxy(66,b); printf("%c",179);
		gotoxy(79,b); printf("%c",179);
		gotoxy(91,b); printf("%c",179);
		gotoxy(103,b); printf("%c",179);
		gotoxy(115,b); printf("%c",179);
		b++;
		int l=0;
		l=l+b-6;
	gotoxy(3,b-1);printf("%d",l);
	
		
	
		fread(&pf, sizeof(pf), 1, f); 
	} 
	
	fclose(f); 
		gotoxy(2,b); vebang(4,196); printf("%c",193);//Do rong cot Thu tu = 4, ky tu chia cot
		gotoxy(7,b); vebang(15,196);printf("%c",193);//Do rong cot masp = 30, ky tu chia cot
		gotoxy(23,b); vebang(30,196);printf("%c",193);//
		gotoxy(54,b); vebang(12,196);printf("%c",193);
		gotoxy(67,b); vebang(12,196);printf("%c",193);
		gotoxy(80,b); vebang(11,196);printf("%c",193);
		gotoxy(92,b); vebang(11,196);printf("%c",193);
		gotoxy(104,b); vebang(11,196);printf("%c",217);
		gotoxy(1,b); printf("%c",192);
}
void suasp()
{
	char maspcs[40];
	FILE *f, *f2;
	SP pf;
	int var = 0; 
	fflush(stdin);
	printf("\nNhap ma sp can sua: ");
	gets(maspcs);
	f = fopen("Sanpham.txt", "r");
	f2 = fopen("Sanphamcpy.txt", "w");  
	while(!feof(f)) 
	{
		fread(&pf, sizeof(pf), 1, f);
		if(strcmp(pf.masp, maspcs) == 0) 
		{
			printf("\nMa sp muon sua %s: ",pf.masp);
			fflush(stdin);
			gets(pf.masp);
			printf("\nTen sp muon sua %s: ", pf.tensp);
			fflush(stdin);
			gets(pf.tensp);
			printf("\nngay san pham muon sua %d/%d/%d ",pf.date.ngay,pf.date.thang,pf.date.nam);
			scanf("%d%d%d", &pf.date.ngay,&pf.date.thang,&pf.date.nam);
			printf("\nso luong muon sua %d: ",pf.soluong);
			scanf("%d",&pf.soluong);
			printf("\ngia sp muon sua %li: ",pf.giasp);
			scanf("%li",&pf.giasp);
			printf("\nhang muon sua %s : ",pf.hang);
			fflush(stdin);
			gets(pf.hang);
			printf("\nkieu dang muon sua %s : ",pf.kieudang);
			fflush(stdin);
			gets(pf.kieudang);
			fwrite(&pf, sizeof(pf), 1, f2);
		} 
		else 
		{
			fwrite(&pf, sizeof(pf), 1, f2);
			var++;
		} 
			 
	}
	fclose(f);
	fclose(f2); 
	f = fopen("Sanpham.txt", "w"); 
	f2 = fopen("Sanphamcpy.txt", "r");
	int i = var; 
	for(i = 0; i < var; i++) 
	{
			fread(&pf, sizeof(pf), 1, f2);
			fwrite(&pf, sizeof(pf), 1, f); 			

	}
	fclose(f); 
	fclose(f2); 
} 	

 int ngaynhap(char maspct[])
{
	FILE *f; 
	f = fopen("Sanpham.txt", "r");
	int kt = 0;
	SP pf;
	while(!feof(f) && kt == 0) 
	{
		fread(&pf, sizeof(pf), 1, f);
		if(strcmp(pf.masp, maspct) == 0)
		{
			return pf.date.ngay; 
			kt = 1; 
		}	
	}
	fclose(f); 
} 

 int thangnhap(char maspct[])
{
	FILE *f; 
	f = fopen("Sanpham.txt", "r");
	int kt = 0;
	SP pf;
	while(!feof(f) && kt == 0) 
	{
		fread(&pf, sizeof(pf), 1, f);
		if(strcmp(pf.masp, maspct) == 0)
		{
			return pf.date.thang; 
			kt = 1; 
		}	
	}
	fclose(f); 
} 

 int namnhap(char maspct[])
{
	FILE *f; 
	f = fopen("Sanpham.txt", "r");
	int kt = 0;
	SP pf;
	while(!feof(f) && kt == 0) 
	{
		fread(&pf, sizeof(pf), 1, f);
		if(strcmp(pf.masp, maspct) == 0)
		{
			return pf.date.nam; 
			kt = 1; 
		}	
	}
	fclose(f); 
} 
 int soluong(char maspct[])
{
	FILE *f; 
	f = fopen("Sanpham.txt", "r");
	int kt = 0;
	SP pf;
	while(!feof(f) && kt == 0) 
	{
		fread(&pf, sizeof(pf), 1, f);
		if(strcmp(pf.masp, maspct) == 0)
		{
			return pf.soluong; 
			kt = 1; 
		}	
	}
	fclose(f); 
} 

long int giasp(char maspct[])
{
	FILE *f; 
	f = fopen("Sanpham.txt", "r");
	int kt = 0;
	SP pf;
	while(!feof(f) && kt == 0) 
	{
		fread(&pf, sizeof(pf), 1, f);
		if(strcmp(pf.masp, maspct) == 0)
		{
			return pf.giasp; 
			kt = 1; 
		}	
	}
	fclose(f); 
} 
 
 
/*int maspnl(char a[8])
{	
int nl;
	FILE *fsp;
	int found1 = 0;
	SP sp;
	fsp = fopen("Sanpham.txt", "r");
	while(!feof(fsp) && found1 == 0)
	{
		fread(&sp, sizeof(sp), 1, fsp);
		if (strcmp(sp.masp,a)==0)
		found1 = 1; 
}
	fclose(fsp);	
	if(found1 == 1){

	gotoxy(1,1);printf("MA SAN PHAM TON TAI"); 
	gotoxy(1,2);printf("NHAN 1 DE NHAP LAI:");
	gotoxy(20,2);scanf("%d",&nl);}
	if (nl==1){
	//	goto nhap;
	}
	 

}
*/



void nhapttsp()
{
/*	FILE *fsp;
	int found1 = 0;
	FILE *doc;
	int nl;
	SP sp;
	char *a;*/
	
	
	
	int m=NULL;
		int *p=&m;
		do {
		
	gotoxy(30,5); vebang(1,195);
	gotoxy(31,5); vebang(50,196); printf("%c",180);
	gotoxy(30,6); printf("%c",179);
	gotoxy(81,6); printf("%c",179);
	gotoxy(30,7); printf("%c",179);
	gotoxy(81,7); printf("%c",179);
	gotoxy(81,9); printf("%c",179);
	gotoxy(81,11); printf("%c",179);
	gotoxy(81,8); printf("%c",179);
	gotoxy(30,9); printf("%c",179);
	gotoxy(30,10); printf("%c",179);
	gotoxy(30,11);printf("%c",179);
	gotoxy(30,11);printf("%c",179);
	gotoxy(81,10); printf("%c",179);
	gotoxy(30,8);printf("%c",179);
	gotoxy(30,14); printf("%c",179);
	gotoxy(30,13);printf("%c",179);
	gotoxy(30,14); printf("%c",179);
	gotoxy(30,15); printf("%c",195);	
	gotoxy(81,12);printf("%c",179);
	gotoxy(30,12);printf("%c",179);
	gotoxy(81,14);printf("%c",179);
	gotoxy(81,13);printf("%c",179);
	gotoxy(31,15);vebang(50,196); printf("%c",180);
	gotoxy(31,17);vebang(50,196); printf("%c",217);
	gotoxy(81,16);printf("%c",179);
	gotoxy(30,16);printf("%c",179);
	gotoxy(30,17);printf("%c",192);
	gotoxy(31,3);vebang(50,196); printf("%c",191);
	gotoxy(30,4);printf("%c",179);
	gotoxy(30,3);printf("%c",218);
	gotoxy(81,4);printf("%c",179);
	gotoxy(47,4);printf("QUAN LY SAN PHAM");
	gotoxy(44,6);  printf("1. NHAP SAN PHAM VAO KHO");
	gotoxy(44,8);  printf("2. HIEN SAN PHAM TRONG KHO");
	gotoxy(44,10); printf("3. TIM SAN PHAM TRONG KHO");
	gotoxy(44,12); printf("4. XOA SAN PHAM TRONG KHO");
	gotoxy(44,14); printf("5. SUA SAN PHAM TRONG KHO");
		
		gotoxy(44,16);printf("HAY CHON CHUC NANG: ");scanf("%d",&m);
		system("cls");
		if(m==1){	
	SP pf; 
	FILE *f;
	int i,n;

	f = fopen("Sanpham.txt", "a");
	gotoxy(30,5);printf("BAN MUON NHAP BAO NHIEU SAN PHAM: ");
	scanf("%d", &n);
	nhap:
	system("cls");
	gotoxy(55,2); printf("THONG TIN SAN PHAM");
	//Header - Phan dau cua bang
	gotoxy(1,3); vebang(1,218);//Ve goc trai tren cua bang
	gotoxy(2,3); vebang(4,196); printf("%c",194);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,3); vebang(15,196);printf("%c",194);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,3); vebang(30,196);printf("%c",194);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,3); vebang(12,196);printf("%c",194);//do rong cot ngay nhap hang=12,ky tu chia cot
	gotoxy(67,3); vebang(12,196);printf("%c",194);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,3); vebang(11,196);printf("%c",194);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,3); vebang(11,196);printf("%c",194);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,3); vebang(11,196);printf("%c",191);//do rong cot hang =11 , ky tu chia cot
	gotoxy(1,4);  printf("%c%s%c%10s%6c%23s%8c%11s%2c%10s%3c%8s%4c%8s%4c%11s%1c",179," TT ",179,"Ma SP",179," Ten San Pham",179,"Ngay Nhap",179,"So luong",179," Gia SP",179,"Hang",179,"Kieu dang",179);
	gotoxy(1,5); vebang(1,195);
	gotoxy(2,5); vebang(4,196); printf("%c",197);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,5); vebang(30,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,5); vebang(12,196);printf("%c",197);//do rong cot ngay nhap hang,ky tu chia cot
	gotoxy(67,5); vebang(12,196);printf("%c",197);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,5); vebang(11,196);printf("%c",197);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,5); vebang(11,196);printf("%c",197);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,5); vebang(11,196);printf("%c",180);//do rong cot hang =11 , ky tu chia cot
	fflush(stdin);

	for(int i = 1; i <= n; i++)
	{
		gotoxy(1,6+i); vebang(1,192);//Ve goc trai tren cua bang
		gotoxy(2,6+i); vebang(4,196); printf("%c",193);//Do rong cot Thu tu = 4, ky tu chia cot
		gotoxy(7,6+i); vebang(15,196);printf("%c",193);//Do rong cot masp = 30, ky tu chia cot
		gotoxy(23,6+i); vebang(30,196);printf("%c",193);//
		gotoxy(54,6+i); vebang(12,196);printf("%c",193);
		gotoxy(67,6+i); vebang(12,196);printf("%c",193);
		gotoxy(80,6+i); vebang(11,196);printf("%c",193);
		gotoxy(92,6+i); vebang(11,196);printf("%c",193);
		gotoxy(104,6+i); vebang(11,196);printf("%c",217);
		
			//Phan than bang
		gotoxy(1,6+i-1);printf("%c%5c%16c%31c%4c%3c%6c%13c%12c%12c%12c",179,179,179,179,47,47,179,179,179,179,179);//Ve cac vach thang dung cho bang
		gotoxy(2,6+i-1); printf("%2d",i);//Dien so thu tu tu dong
		fflush(stdin);//Chi thi bien dich de xu ly cho nhap xau ky tu
		gotoxy(8,6+i-1); gets(pf.masp);
			
/*int nl;
char *a;
	FILE *fsp;
	int found1 = 0;
	SP sp;
	fsp = fopen("Sanpham.txt", "r");
	while(!feof(fsp) && found1 == 0)
	{
		fread(&sp, sizeof(sp), 1, fsp);
		if (strcmp(pf.masp,a)==0)
		found1 = 1; 
}
	fclose(fsp);	
	if(found1 == 1){
	gotoxy(1,1);printf("MA SAN PHAM TON TAI"); 
	gotoxy(1,2);printf("NHAN 1 DE NHAP LAI:");
	gotoxy(20,2);scanf("%d",&nl);
}
	if (nl==1){
		goto nhap;
	}
	 while(nl=0);

		//maspnl(pf.masp);
*/
		gotoxy(24,6+i-1); gets(pf.tensp); //nhap ten sp
		gotoxy(55,6+i-1); scanf("%d",&pf.date.ngay);//Nhap ngay nhap
		gotoxy(58,6+i-1); scanf("%d",&pf.date.thang);//Nhap thang nhap
		gotoxy(61,6+i-1); scanf("%d",&pf.date.nam);//Nhap nam nhap
		


		fflush(stdin);//Chi thi bien dich de xu ly cho nhap xau ky tu
		gotoxy(69,6+i-1); scanf("%d",&pf.soluong);//nhap so luong
		gotoxy(81,6+i-1); scanf("%li",&pf.giasp);//nhap gia sp
		fflush(stdin);//Chi thi bien dich de xu ly cho nhap xau ky tu
		gotoxy(93,6+i-1);gets(pf.hang);//nhap hang
		fflush(stdin);//Chi thi bien dich de xu ly cho nhap xau ky tu
		gotoxy(106,6+i-1);gets(pf.kieudang);//nhap kieu dang
		fwrite(&pf, sizeof(pf), 1, f); 
		fflush(stdin); 
	} 
	fclose(f); 
} 
system("cls");
menu();
if(m==2){
	system("cls");
	inra();
	pressAnyKey();
}
if (m==3){
	system("cls");
timsp();
pressAnyKey();
}
if (m==4){
	system("cls");
	xoasp();
	pressAnyKey();
}
if (m==5){
	system("cls");
	suasp();
	pressAnyKey();
}
}while(m=0);

}






//============================================================================================================
// bang nhan vien

struct Ngaysinhnv{
	unsigned char ngay;// 1<= ngay <= 31
	unsigned char thang;// 1<= thang <= 12
	unsigned short nam; //0 <= nam <= 65535
}datenv;
typedef struct{
	char mnv[8];
	char tennv[30];
	Ngaysinhnv datenv;
	char diachi[10];
	int sdt;
	char gioitinh[3];
	int cccd;
}NV;
 void inranv() 
{
	NV nv;
	FILE *fnv;
	int i, n=6;
	fnv = fopen("Nhanvien.txt", "r");
	gotoxy(45,2); printf("THONG TIN NHAN VIEN CUA HANG");
	gotoxy(1,3); vebang(1,218);//Ve goc trai tren cua bang
	gotoxy(2,3); vebang(4,196); printf("%c",194);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,3); vebang(15,196);printf("%c",194);//Do rong cot manv = 8, ky tu chia cot
	gotoxy(23,3); vebang(30,196);printf("%c",194);//do rong cot tennv = 30, ky tu chia cot
	gotoxy(54,3); vebang(12,196);printf("%c",194);//do rong cot ngay sinh =12,ky tu chia cot
	gotoxy(67,3); vebang(12,196);printf("%c",194);//do rong cot dia chi =11, ky tu chia cot
	gotoxy(80,3); vebang(11,196);printf("%c",194);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,3); vebang(11,196);printf("%c",194);//do rong cot gioi tinh =5 , ky tu chia cot
	gotoxy(104,3); vebang(11,196);printf("%c",191);//do rong cot hang =13 , ky tu chia cot
	gotoxy(1,4);  printf("%c%s%c%10s%6c%23s%8c%11s%2c%10s%3c%7s%5c%9s%2c%7s%5c",179," TT ",179,"MA NV",179,
	"Ten nhan vien",179,"Ngay Sinh",179,"dia chi",179,"SDT",179," Gioi tinh",179,"CCCD",179);
	gotoxy(1,5); vebang(1,195);
	gotoxy(2,5); vebang(4,196); printf("%c",197);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,5); vebang(30,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,5); vebang(12,196);printf("%c",197);//do rong cot ngay nhap hang,ky tu chia cot
	gotoxy(67,5); vebang(12,196);printf("%c",197);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,5); vebang(11,196);printf("%c",197);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,5); vebang(11,196);printf("%c",197);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,5); vebang(11,196);printf("%c",180);//do rong cot hang =11 , ky tu chia cot

	
		 	
	

	
	fread(&nv, sizeof(nv), 1, fnv); 
	while(!feof(fnv))
	{
		gotoxy(8,n);printf("%s",nv.mnv);
		gotoxy(24,n);printf("%s",nv.tennv);
		gotoxy(55,n);printf("%d/%d/%d",nv.datenv.ngay,nv.datenv.thang,nv.datenv.nam);
		gotoxy(68,n);printf("%s",nv.diachi);
		gotoxy(81,n);printf("%d",nv.sdt);	
		gotoxy(93,n);printf("%s",nv.gioitinh);
		gotoxy(105,n);printf("%d",nv.cccd);



		gotoxy(1,n); printf("%c",179);
		gotoxy(6,n); printf("%c",179);
		gotoxy(22,n); printf("%c",179);
		gotoxy(53,n); printf("%c",179);
		gotoxy(66,n); printf("%c",179);
		gotoxy(79,n); printf("%c",179);
		gotoxy(91,n); printf("%c",179);
		gotoxy(103,n); printf("%c",179);
		gotoxy(115,n); printf("%c",179);
		n++;
		fread(&nv, sizeof(nv), 1, fnv); 
	int l=0;
	l=l+n-6;
	gotoxy(3,n-1);printf("%d",l);
	
		
	} 
	fclose(fnv); 
		gotoxy(1,n);printf("%c",192);//Do rong cot Thu tu = 4, ky tu chia cot
		gotoxy(2,n); vebang(4,196); printf("%c",193);//Do rong cot Thu tu = 4, ky tu chia cot
		gotoxy(7,n); vebang(15,196);printf("%c",193);//Do rong cot masp = 30, ky tu chia cot
		gotoxy(23,n); vebang(30,196);printf("%c",193);//
		gotoxy(54,n); vebang(12,196);printf("%c",193);
		gotoxy(67,n); vebang(12,196);printf("%c",193);
		gotoxy(80,n); vebang(11,196);printf("%c",193);
		gotoxy(92,n); vebang(11,196);printf("%c",193);
		gotoxy(104,n); vebang(11,196);printf("%c",217);
	
}

void xoanv()
{
	char manvcx[40];
	FILE *f, *f2;
	NV nv;
	int var = 0; 
	fflush(stdin);
	gotoxy(0,25);printf("Nhap ma nv can xoa: ");
	gets(manvcx);
	f = fopen("Nhanvien.txt", "r");
	f2 = fopen("Nhanviencpy.txt", "w");  
	int kt=0;
	while(!feof(f)) 
	{
		fread(&nv, sizeof(nv), 1, f);
		if(strcmp(nv.mnv, manvcx) == 0) 
	 kt=1;
		else 
		{
			fwrite(&nv, sizeof(nv), 1, f2);
			var++;
		} 
			 
	}
	fclose(f);
	fclose(f2);
	if(kt==1){
	printf("\nXoa thanh cong!!! ", nv.mnv);
	}
 
	f = fopen("Nhanvien.txt", "w"); 
	f2 = fopen("Nhanviencpy.txt", "r");
	int i = var; 
	for(i = 1; i <= var; i++) 
	{
			fread(&nv, sizeof(nv), 1, f2);
			fwrite(&nv, sizeof(nv), 1, f); 			

	}
	fclose(f); 
	fclose(f2); 
} 

void timnv()
{
	FILE *f;
	char manvct[40];
	int found = 0;
	NV nv; 
	fflush(stdin);
	printf("\nNhap ma nv can tim: "); 
	gets(manvct);
	system("cls");
	f = fopen("Nhanvien.txt", "r");
	while(!feof(f) && found == 0)
	{
		fread(&nv, sizeof(nv), 1, f);
		if(strcmp(nv.mnv, manvct) == 0)
		found = 1;
	}
	fclose(f);
	if(found == 1)
	{
		gotoxy(45,2); printf("THONG TIN NHAN VIEN CAN TIM");
	gotoxy(1,3); vebang(1,218);//Ve goc trai tren cua bang
	gotoxy(2,3); vebang(4,196); printf("%c",194);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,3); vebang(15,196);printf("%c",194);//Do rong cot manv = 8, ky tu chia cot
	gotoxy(23,3); vebang(30,196);printf("%c",194);//do rong cot tennv = 30, ky tu chia cot
	gotoxy(54,3); vebang(12,196);printf("%c",194);//do rong cot ngay sinh =12,ky tu chia cot
	gotoxy(67,3); vebang(12,196);printf("%c",194);//do rong cot dia chi =11, ky tu chia cot
	gotoxy(80,3); vebang(11,196);printf("%c",194);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,3); vebang(11,196);printf("%c",194);//do rong cot gioi tinh =5 , ky tu chia cot
	gotoxy(104,3); vebang(11,196);printf("%c",191);//do rong cot hang =13 , ky tu chia cot
	gotoxy(1,4);  printf("%c%s%c%10s%6c%23s%8c%11s%2c%10s%3c%7s%5c%9s%2c%7s%5c",179," TT ",179,"MA NV",179,
	"Ten nhan vien",179,"Ngay Sinh",179,"dia chi",179,"SDT",179," Gioi tinh",179,"CCCD",179);
	gotoxy(1,5); vebang(1,195);
	gotoxy(2,5); vebang(4,196); printf("%c",197);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,5); vebang(30,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,5); vebang(12,196);printf("%c",197);//do rong cot ngay nhap hang,ky tu chia cot
	gotoxy(67,5); vebang(12,196);printf("%c",197);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,5); vebang(11,196);printf("%c",197);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,5); vebang(11,196);printf("%c",197);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,5); vebang(11,196);printf("%c",180);//do rong cot hang =11 , ky tu chia cot
		gotoxy(1,6); printf("%c",179);
		gotoxy(1,7); printf("%c",192);
		gotoxy(2,7);vebang(113,196); printf("%c",217);		
		gotoxy(6,6); printf("%c",179);		
		gotoxy(22,6); printf("%c",179);		
		gotoxy(53,6); printf("%c",179);		
		gotoxy(66,6); printf("%c",179);		
		gotoxy(79,6); printf("%c",179);		
		gotoxy(91,6); printf("%c",179);
		gotoxy(103,6); printf("%c",179);	
		gotoxy(115,6); printf("%c",179);

		gotoxy(6,7); printf("%c",193);
		gotoxy(22,7); printf("%c",193);
		gotoxy(53,7); printf("%c",193);
		gotoxy(66,7); printf("%c",193);
		gotoxy(79,7); printf("%c",193);
		gotoxy(91,7); printf("%c",193);
		gotoxy(103,7); printf("%c",193);
	gotoxy(8,6);printf("%s",nv.mnv);
		gotoxy(24,6);printf("%s",nv.tennv);
		gotoxy(55,6);printf("%d/%d/%d",nv.datenv.ngay,nv.datenv.thang,nv.datenv.nam);
		gotoxy(68,6);printf("%s",nv.diachi);
		gotoxy(81,6);printf("%d",nv.sdt);	
		gotoxy(93,6);printf("%s",nv.gioitinh);
		gotoxy(105,6);printf("%d",nv.cccd);
	}
	else 
	{
		printf("\nKhong tim thay nhan vien can tim %s", manvct);
	}
} 
void suanv()
{
	char manvcs[40];
	FILE *f, *f2;
	NV nv;
	int var = 0; 
	fflush(stdin);
	printf("\nNhap ma nv  can sua: ");
	gets(manvcs);
	f = fopen("Nhanvien.txt", "r");
	f2 = fopen("Nhanviencpy.txt", "w");  
	while(!feof(f)) 
	{
		fread(&nv, sizeof(nv), 1, f);
		if(strcmp(nv.mnv,manvcs) == 0) 
		{
			printf("\nMa nhan vien muon sua (%s): ",nv.mnv);
			fflush(stdin);
			gets(nv.mnv);
			printf("\nTen nhan vien muon sua (%s): ", nv.tennv);
			fflush(stdin);
			gets(nv.tennv);
			printf("\nNgay sinh nhan vien muon sua (%d/%d/%d): ", nv.datenv.ngay,nv.datenv.thang,nv.datenv.nam);
			scanf("%d%d%d",&nv.datenv.ngay,&nv.datenv.thang,&nv.datenv.nam);
			fflush(stdin);	
			printf("\nDia chi nhan vien muon sua %s : ", nv.diachi);
			fflush(stdin);
			gets(nv.diachi);
			printf("\nSo dien thoai nhan vien muon sua (%d): ",nv.sdt);
			scanf("%d",&nv.sdt);
			printf("\nGioi tinh nhan vien muon sua (%s): ", nv.gioitinh);
			fflush(stdin);
			gets(nv.gioitinh);
			printf("\nCccd nhan vien muon sua (%d): ", nv.cccd);
			scanf("%d",&nv.cccd);
			printf("\nSua thanh cong!!!");
			fwrite(&nv, sizeof(nv), 1, f2);
		} 
		else 
		{
			fwrite(&nv, sizeof(nv), 1, f2);
			var++;
		} 
			 
	}
	fclose(f);
	fclose(f2); 
	f = fopen("Nhanvien.txt", "w"); 
	f2 = fopen("Nhanviencpy.txt", "r");
	int i = var; 
	for(i = 0; i < var; i++) 
	{
			fread(&nv, sizeof(nv), 1, f2);
			fwrite(&nv, sizeof(nv), 1, f); 			

	}
	fclose(f); 
	fclose(f2); 
}

int ngaynv(	char ngaynvct[])
{
	FILE *f; 
	f = fopen("Nhanvien.txt", "r");
	int kt = 0;
	NV nv;
	while(!feof(f) && kt == 0) 
	{
		fread(&nv, sizeof(nv), 1, f);
		if(strcmp(nv.mnv, ngaynvct) == 0)
		{
			return nv.datenv.ngay; 
			kt = 1; 
		}	
	}
	fclose(f); 
}
int thangnv(char thangnvct[])
{
	FILE *f; 
	f = fopen("Nhanvien.txt", "r");
	int kt = 0;
	NV nv;
	while(!feof(f) && kt == 0) 
	{
		fread(&nv, sizeof(nv), 1, f);
		if(strcmp(nv.mnv, thangnvct) == 0)
		{
			return nv.datenv.thang; 
			kt = 1; 
		}	
	}
	fclose(f); 
}
int namnv(	char namnvct[])
{
	FILE *f; 
	f = fopen("Nhanvien.txt", "r");
	int kt = 0;
	NV nv;
	while(!feof(f) && kt == 0) 
	{
		fread(&nv, sizeof(nv), 1, f);
		if(strcmp(nv.mnv, namnvct) == 0)
		{
			return nv.datenv.nam; 
			kt = 1; 
		}	
	}
	fclose(f); 
}

int sdtnv(	char sdtnvct[])
{
	FILE *f; 
	f = fopen("Nhanvien.txt", "r");
	int kt = 0;
	NV nv;
	while(!feof(f) && kt == 0) 
	{
		fread(&nv, sizeof(nv), 1, f);
		if(strcmp(nv.mnv, sdtnvct) == 0)
		{
			return nv.sdt; 
			kt = 1; 
		}	
	}
	fclose(f); 
}

int ccnv(	char ccnvct[])
{
	FILE *f; 
	f = fopen("Nhanvien.txt", "r");
	int kt = 0;
	NV nv;
	while(!feof(f) && kt == 0) 
	{
		fread(&nv, sizeof(nv), 1, f);
		if(strcmp(nv.mnv, ccnvct) == 0)
		{
			return nv.cccd; 
			kt = 1; 
		}	
	}
	fclose(f); 
}
void nhapttnv()
{	
	int m=NULL;
	int *p=&m;
	do { 
				gotoxy(30,5); vebang(1,195);
	gotoxy(31,5); vebang(50,196); printf("%c",180);
	gotoxy(30,6); printf("%c",179);
	gotoxy(81,6); printf("%c",179);
	gotoxy(30,7); printf("%c",179);
	gotoxy(81,7); printf("%c",179);
	gotoxy(81,9); printf("%c",179);
	gotoxy(81,11); printf("%c",179);
	gotoxy(81,8); printf("%c",179);
	gotoxy(30,9); printf("%c",179);
	gotoxy(30,10); printf("%c",179);
	gotoxy(30,11);printf("%c",179);
	gotoxy(30,11);printf("%c",179);
	gotoxy(81,10); printf("%c",179);
	gotoxy(30,8);printf("%c",179);
	gotoxy(30,14); printf("%c",179);
	gotoxy(30,13);printf("%c",179);
	gotoxy(30,14); printf("%c",179);
	gotoxy(30,15); printf("%c",195);	
	gotoxy(81,12);printf("%c",179);
	gotoxy(30,12);printf("%c",179);
	gotoxy(81,14);printf("%c",179);
	gotoxy(81,13);printf("%c",179);
	gotoxy(31,15);vebang(50,196); printf("%c",180);
	gotoxy(31,17);vebang(50,196); printf("%c",217);
	gotoxy(81,16);printf("%c",179);
	gotoxy(30,16);printf("%c",179);
	gotoxy(30,17);printf("%c",192);
	gotoxy(31,3);vebang(50,196); printf("%c",191);
	gotoxy(30,4);printf("%c",179);
	gotoxy(30,3);printf("%c",218);
	gotoxy(81,4);printf("%c",179);
	gotoxy(47,4);printf("QUAN LY NHAN VIEN");
	gotoxy(44,6);  printf("1. NHAP NHAN VIEN BAN HANG");
	gotoxy(44,8);  printf("2. HIEN NHAN VIEN BAN HANG");
	gotoxy(44,10); printf("3. XOA NHAN VIEN BAN HANG");
	gotoxy(44,12); printf("4. TIM NHAN VIEN BAN HANG");
	gotoxy(44,14); printf("5. SUA NAHN VIEN BAN HANG");
		gotoxy(44,16);printf("HAY CHON CHUC NANG: ");scanf("%d",&m);
system("cls");
	if (m==1){
	NV nv; 
	FILE *fnv;
	int i, n;
		gotoxy(40,2);printf("BAN MUON NHAP BAO NHIEU NHAN VIEN:"); scanf("%d",&n);
	system("cls");
	char tieude[] = "THONG TIN NHAN VIEN";
	gotoxy(60-strlen(tieude),2); printf(tieude);
	//Header - Phan dau cua bang
	gotoxy(1,3); vebang(1,218);//Ve goc trai tren cua bang
	gotoxy(2,3); vebang(4,196); printf("%c",194);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,3); vebang(15,196);printf("%c",194);//Do rong cot manv = 8, ky tu chia cot
	gotoxy(23,3); vebang(30,196);printf("%c",194);//do rong cot tennv = 30, ky tu chia cot
	gotoxy(54,3); vebang(12,196);printf("%c",194);//do rong cot ngay sinh =12,ky tu chia cot
	gotoxy(67,3); vebang(12,196);printf("%c",194);//do rong cot dia chi =11, ky tu chia cot
	gotoxy(80,3); vebang(11,196);printf("%c",194);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,3); vebang(11,196);printf("%c",194);//do rong cot gioi tinh =5 , ky tu chia cot
	gotoxy(104,3); vebang(11,196);printf("%c",191);//do rong cot hang =13 , ky tu chia cot
	gotoxy(1,4);  printf("%c%s%c%10s%6c%23s%8c%11s%2c%10s%3c%7s%5c%9s%2c%7s%5c",179," TT ",179,"MA NV",179,
	"Ten nhan vien",179,"Ngay Sinh",179,"dia chi",179,"SDT",179," Gioi tinh",179,"CCCD",179);
	gotoxy(1,5); vebang(1,195);
	gotoxy(2,5); vebang(4,196); printf("%c",197);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(7,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(23,5); vebang(30,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(54,5); vebang(12,196);printf("%c",197);//do rong cot ngay nhap hang,ky tu chia cot
	gotoxy(67,5); vebang(12,196);printf("%c",197);//do rong cot so luong=11, ky tu chia cot
	gotoxy(80,5); vebang(11,196);printf("%c",197);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(92,5); vebang(11,196);printf("%c",197);//do rong cot hang =11 , ky tu chia cot
	gotoxy(104,5); vebang(11,196);printf("%c",180);//do rong cot hang =11 , ky tu chia cot
	fnv = fopen("Nhanvien.txt", "a");
	fflush(stdin);
	for(int i = 1; i <= n; i++)
	{
		//Phan chan cua bang
		gotoxy(1,6+i); vebang(1,192);//Ve goc trai tren cua bang
		gotoxy(2,6+i); vebang(4,196); printf("%c",193);//Do rong cot Thu tu = 4, ky tu chia cot
		gotoxy(7,6+i); vebang(15,196);printf("%c",193);//Do rong cot maNV = 30, ky tu chia cot
		gotoxy(23,6+i); vebang(30,196);printf("%c",193);//
		gotoxy(54,6+i); vebang(12,196);printf("%c",193);
		gotoxy(67,6+i); vebang(12,196);printf("%c",193);
		gotoxy(80,6+i); vebang(11,196);printf("%c",193);
		gotoxy(92,6+i); vebang(11,196);printf("%c",193);
		gotoxy(104,6+i); vebang(11,196);printf("%c",217);
		
			//Phan than bang
		gotoxy(1,6+i-1);printf("%c%5c%16c%31c%4c%3c%6c%13c%12c%12c%12c",179,179,179,179,47,47,179,179,179,179,179);//Ve cac vach thang dung cho bang
		gotoxy(2,6+i-1); printf("%2d",i);//Dien so thu tu tu dong
		fflush(stdin);//Chi thi bien dich de xu ly cho nhap xau ky tu
		gotoxy(8,6+i-1); gets(nv.mnv); //Nhap masp
		gotoxy(24,6+i-1); gets(nv.tennv); //nhap ten sp
		gotoxy(55,6+i-1); scanf("%d",&nv.datenv.ngay);//Nhap ngay nhap
		gotoxy(58,6+i-1); scanf("%d",&nv.datenv.thang);//Nhap thang nhap
		gotoxy(61,6+i-1); scanf("%d",&nv.datenv.nam);//Nhap nam nhap
		fflush(stdin);//Chi thi bien dich de xu ly cho nhap xau ky tu
		gotoxy(69,6+i-1); gets(nv.diachi);//nhap diachi
		gotoxy(81,6+i-1); scanf("%d",&nv.sdt);//nhap sdt
		fflush(stdin);//Chi thi bien dich de xu ly cho nhap xau ky tu
		gotoxy(93,6+i-1); gets(nv.gioitinh);//gioi tinh
		gotoxy(106,6+i-1);scanf("%d",&nv.cccd);//nhap cccd
		fwrite(&nv, sizeof(nv), 1, fnv); 
		fflush(stdin); 
	} 
	fclose(fnv); 
} 
system("cls");
menu();
if(m==2){
	system("cls");
	inranv();
	pressAnyKey();
}
if(m==3)
{
	system("cls");
	inranv();
	xoanv();
	pressAnyKey();
}
if(m==4){
	system("cls");
	timnv();
	pressAnyKey();
	
}
if(m==5){
	system("cls");
	suanv();
	pressAnyKey();	
}

}while(m=0);
}


//
////==========================================================================================================================================
void inrakh()
{
	FILE *f = NULL;
	f =fopen("Khachhang.txt", "r"); 
	char doc[200];
	printf("\nThong tin hoa don cua khach mua hang : \n");
	while(fgets(doc, 200, f) != NULL)
	{
		printf("%s",doc); 
	} 
	printf("\n");
}

void nhapttkh()
{
	int m;
	char kh[40], masp[40], diachi[50]; 
	int i, j, kiemtra, chon, sdt;
	long int tonggia = 0;int slsp ; 
	FILE *fkh = NULL, *fsp = NULL, *fnv = NULL;
	fkh = fopen("Khachhang.txt", "a");	
	SP pf; 
	NV nv; 
	char maspct[40];
	char manvct[40]; 
	do
	{
	gotoxy(30,5); vebang(1,218);
	gotoxy(31,5); vebang(50,196); printf("%c",191);
	gotoxy(30,6); printf("%c",179);
	gotoxy(81,6); printf("%c",179);
	gotoxy(30,7); printf("%c",195);
	gotoxy(31,7); vebang(50,196);printf("%c",180);
	gotoxy(81,8); printf("%c",179);
	gotoxy(30,9); printf("%c",179);
	gotoxy(81,9); printf("%c",179);
	gotoxy(30,10); printf("%c",179);
	gotoxy(31,11); vebang(50,196); printf("%c",180);
	gotoxy(30,11); printf("%c",195);
	gotoxy(81,10);  printf("%c",179);
	gotoxy(30,8);printf("%c",179);
	gotoxy(30,13);printf("%c",192);
	gotoxy(81,12);printf("%c",179);
	gotoxy(30,12);printf("%c",179);
	gotoxy(31,13);vebang(50,196); printf("%c",217);
	gotoxy(48,6);  printf("QUAN LY KHACH HANG");
	gotoxy(44,8);  printf(" 1. NHAP KHACH HANG MOI");
	gotoxy(44,10);  printf(" 2. HIEN THI KHACH HANG");
	gotoxy(45,12);  printf("HAY CHON CHUC NANG:");
		scanf("%d", &chon);
		system("cls");
		if(chon == 1)
		{
	gotoxy(55,2); printf("THONG TIN KHACH HANG");
	//Header - Phan dau cua bang
	gotoxy(1,3); vebang(1,218);//Ve goc trai tren cua bang
	gotoxy(2,3); vebang(25,196); printf("%c",194);//Do rong cot ten =15
	gotoxy(28,3); vebang(15,196);printf("%c",194);//Do rong dia chi
	gotoxy(44,3); vebang(12,196);printf("%c",194);//do rong cot sdt
	gotoxy(57,3); vebang(8,196);printf("%c",194);//do rong cot masp
	gotoxy(66,3); vebang(10,196);printf("%c",194);//do rong so luong
	gotoxy(77,3); vebang(15,196);printf("%c",194);//do rong gia
	gotoxy(93,3); vebang(8,196);printf("%c",194);//do rong manv
	gotoxy(102,3); vebang(12,196);printf("%c",191);//do rong ngay mua
	gotoxy(1,4); printf("%c",179);
	gotoxy(27,4); printf("%c",179);
	gotoxy(43,4); printf("%c",179);
	gotoxy(56,4); printf("%c",179);
	gotoxy(65,4); printf("%c",179);
	gotoxy(76,4); printf("%c",179);
	gotoxy(92,4); printf("%c",179);
	gotoxy(65,4); printf("%c",179);
	gotoxy(101,4); printf("%c",179);
	gotoxy(114,4); printf("%c",179);
	gotoxy(1,5); vebang(1,195);
	gotoxy(2,5); vebang(25,196); printf("%c",197);//Do rong cot Thu tu = 4, ky tu chia cot
	gotoxy(28,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(44,5); vebang(12,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(57,5); vebang(8,196);printf("%c",197);//do rong cot ngay nhap hang,ky tu chia cot
	gotoxy(66,5); vebang(10,196);printf("%c",197);//do rong cot so luong=11, ky tu chia cot
	gotoxy(77,5); vebang(15,196);printf("%c",197);//do rong cot giasp =11 , ky tu chia cot
	gotoxy(93,5); vebang(8,196);printf("%c",197);//do rong cot hang =11 , ky tu chia cot
	gotoxy(102,5); vebang(12,196);printf("%c",180);//do rong cot hang =11 , ky tu chia cot
		gotoxy(1,6); printf("%c",179);
		gotoxy(1,7); printf("%c",192);
		gotoxy(2,7);vebang(112,196); printf("%c",217);		
		gotoxy(27,6); printf("%c",179);		
		gotoxy(43,6); printf("%c",179);		
		gotoxy(56,6); printf("%c",179);		
		gotoxy(65,6); printf("%c",179);		
		gotoxy(76,6); printf("%c",179);		
		gotoxy(92,6); printf("%c",179);
		gotoxy(101,6); printf("%c",179);	
		gotoxy(114,6); printf("%c",179);

		gotoxy(27,7); printf("%c",193);
		gotoxy(43,7); printf("%c",193);
		gotoxy(56,7); printf("%c",193);
		gotoxy(65,7); printf("%c",193);
		gotoxy(76,7); printf("%c",193);
		gotoxy(92,7); printf("%c",193);
		gotoxy(101,7); printf("%c",193);
			gotoxy(7,4); printf("TEN KHACH HANG");
			gotoxy(33,4); printf("DIA CHI");
				gotoxy(48,4); printf("SDT");
					gotoxy(59,4); printf("MA SP");
				
				gotoxy(67,4); printf("SO LUONG");
				gotoxy(80,4); printf("TONG GIA");
				
				gotoxy(95,4); printf("MA NV");
				gotoxy(104,4); printf("NGAY MUA");
				
			fflush(stdin); 
			gotoxy(3,6);gets(kh); 
			fprintf(fkh,"\nTEN KHACH HANG:%s",kh);
			
			fflush(stdin);
	gotoxy(30,6);gets(diachi); 
			fprintf(fkh,"\nDIA CHI:%s", diachi);
		
		gotoxy(45,6);	scanf("%d",&sdt);
			fprintf(fkh,"\nSO DIEN THOAI:%d",sdt); 
				int found = 0;
				fflush(stdin);
			
				gotoxy(59,6);gets(maspct);
			
				gotoxy(67,6);scanf("%d",&slsp);				
				fsp = fopen("Sanpham.txt","r");
			
				while(!feof(fsp) && found == 0)
				{
					fread(&pf, sizeof(pf), 1, fsp);
					if(strcmp(pf.masp, maspct) == 0)
					{
						
						found=1;
				
					}  
				}
				fclose(fsp);			
			
		
			fflush(stdin);
			if(found==1){
			
			fprintf(fkh,"\nMA SP:%s", maspct);
			fprintf(fkh,"\nSO LUONG:%d",slsp) ;	
			tonggia += (giasp(pf.masp)*slsp); 
			gotoxy(80,6); printf("%li",tonggia);
			gotoxy(94,6);gets(manvct); 
		}
			fnv =fopen("Nhanvien.txt","r"); 
			int ngay,thang,nam;
			
		gotoxy(103,6);scanf("%d",&ngay);
		gotoxy(105,6);	scanf("%d",&thang);
		gotoxy(107,6);	scanf("%d",&nam);
			int found1 = 0; 
			while(!feof(fnv) && found1 == 0)
			{
				fread(&nv, sizeof(nv), 1, fnv);
				if(strcmp(nv.mnv, manvct) == 0)
				{
			found1=1;
					
				} 
			}
			if(found1==1)
			{
			fprintf(fkh,"\nNhan vien thanh toan: %s",nv.mnv);
			fprintf(fkh,"\nNgay mua: %d/%d/%d",ngay,thang,nam); 
			}
			fclose(fnv);
				
			fprintf(fkh,"\nTONG THANH TOAN:%li", tonggia);	
			tonggia = 0;		
		}
		system("cls");
		if(chon==2){
			inrakh();
			pressAnyKey();}

		
	else
	menu();
	break;


	}while(m=0);
	fclose(fkh); 	
}

void baocao()
{
	SP pf;
	FILE *f;
	int n=NULL;
	int *p=&n;
	do{		
	gotoxy(30,5); vebang(1,218);
	gotoxy(31,5); vebang(50,196); printf("%c",191);
	gotoxy(30,6); printf("%c",179);
	gotoxy(81,6); printf("%c",179);
	gotoxy(30,7); printf("%c",195);
	gotoxy(31,7); vebang(50,196);printf("%c",180);
	gotoxy(81,8); printf("%c",179);
	gotoxy(30,9); printf("%c",179);
	gotoxy(81,9); printf("%c",179);
	gotoxy(30,10); printf("%c",179);
	gotoxy(31,11); vebang(50,196); printf("%c",180);
	gotoxy(30,11); printf("%c",195);
	gotoxy(81,10);  printf("%c",179);
	gotoxy(30,8);printf("%c",179);
	gotoxy(30,13);printf("%c",192);
	gotoxy(81,12);printf("%c",179);
	gotoxy(30,12);printf("%c",179);
	gotoxy(31,13);vebang(50,196); printf("%c",217);
	gotoxy(45,6);  printf(" THONG KE BAO CAO ");
	gotoxy(40,8);  printf(" 1. BAO CAO SAN PHAM TON KHO");
	gotoxy(40,10);  printf(" 2. BAO CAO SAN PHAM HET HANG");
	gotoxy(40,12);  printf("HAY CHON CHUC NANG:");
	scanf("%d",&n);
	system("cls");	
	if(n==1){
	int b=6;
	f = fopen("Sanpham.txt","r");
	gotoxy(25,2); printf("THONG TIN SAN PHAM TON KHO");	
gotoxy(10,3); vebang(1,218);//Ve goc trai tren cua bang
gotoxy(11,3); vebang(15,196);printf("%c",194);//Do rong cot masp = 8, ky tu chia cot
gotoxy(27,3); vebang(30,196);printf("%c",194);//do rong cot tensp = 30, ky tu chia cot
gotoxy(58,3); vebang(12,196);printf("%c",191);//do rong cot so luong=11, ky tu chia cot
gotoxy(13,4); printf("MA SAN PHAM");//do rong cot so luong=11, ky tu chia cot
gotoxy(35,4); printf("TEN SAN PHAM");//do rong cot so luong=11, ky tu chia cot
gotoxy(60,4); printf("SO LUONG");//do rong cot so luong=11, ky tu chia cot
gotoxy(26,4); printf("%c",179);gotoxy(57,4); printf("%c",179);gotoxy(70,4); printf("%c",179);
gotoxy(11,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
gotoxy(27,5); vebang(30,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
gotoxy(58,5); vebang(12,196);printf("%c",180);//do rong cot so luong=11, ky tu chia cot
gotoxy(10,4); printf("%c",179);
gotoxy(10,5); printf("%c",195);
fread(&pf, sizeof(pf), 1, f); 
	while(!feof(f))
	{
		if(pf.soluong>0)
		{
		gotoxy(13,b);printf("%s",pf.masp);
		gotoxy(35,b);printf("%s",pf.tensp);
		gotoxy(60,b);printf("%d",pf.soluong);
		gotoxy(10,b); printf("%c",179);
		gotoxy(26,b); printf("%c",179);
		gotoxy(57,b); printf("%c",179);
		gotoxy(70,b); printf("%c",179);
		b++;
		}	
		fread(&pf, sizeof(pf), 1, f); 
}
	fclose(f); 
	gotoxy(10,b); printf("%c",192);
	gotoxy(11,b); vebang(15,196);printf("%c",193);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(27,b); vebang(30,196);printf("%c",193);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(58,b); vebang(12,196);printf("%c",217);//do rong cot so luong=11, ky tu chia cot
}
 

if(n==2){
	
	int J=6;
	f = fopen("Sanpham.txt","r");
	gotoxy(25,2); printf("THONG TIN SAN PHAM HET HANG");	
gotoxy(10,3); vebang(1,218);//Ve goc trai tren cua bang
gotoxy(11,3); vebang(15,196);printf("%c",194);//Do rong cot masp = 8, ky tu chia cot
gotoxy(27,3); vebang(30,196);printf("%c",194);//do rong cot tensp = 30, ky tu chia cot
gotoxy(58,3); vebang(12,196);printf("%c",191);//do rong cot so luong=11, ky tu chia cot
gotoxy(13,4); printf("MA SAN PHAM");//do rong cot so luong=11, ky tu chia cot
gotoxy(35,4); printf("TEN SAN PHAM");//do rong cot so luong=11, ky tu chia cot
gotoxy(60,4); printf("SO LUONG");//do rong cot so luong=11, ky tu chia cot
gotoxy(26,4); printf("%c",179);gotoxy(57,4); printf("%c",179);gotoxy(70,4); printf("%c",179);
gotoxy(11,5); vebang(15,196);printf("%c",197);//Do rong cot masp = 8, ky tu chia cot
gotoxy(27,5); vebang(30,196);printf("%c",197);//do rong cot tensp = 30, ky tu chia cot
gotoxy(58,5); vebang(12,196);printf("%c",180);//do rong cot so luong=11, ky tu chia cot
gotoxy(10,4); printf("%c",179);
gotoxy(10,5); printf("%c",195);
fread(&pf, sizeof(pf), 1, f); 
	while(!feof(f))
	{
		if(pf.soluong<1)
		{
		gotoxy(13,J);printf("%s",pf.masp);
		gotoxy(35,J);printf("%s",pf.tensp);
		gotoxy(60,J);printf("%d",pf.soluong);
		gotoxy(10,J); printf("%c",179);
		gotoxy(26,J); printf("%c",179);
		gotoxy(57,J); printf("%c",179);
		gotoxy(70,J); printf("%c",179);
		J++;
		}	
		fread(&pf, sizeof(pf), 1, f); 
}
	fclose(f); 
	gotoxy(10,J); printf("%c",192);
	gotoxy(11,J); vebang(15,196);printf("%c",193);//Do rong cot masp = 8, ky tu chia cot
	gotoxy(27,J); vebang(30,196);printf("%c",193);//do rong cot tensp = 30, ky tu chia cot
	gotoxy(58,J); vebang(12,196);printf("%c",217);//do rong cot so luong=11, ky tu chia cot
}
}while(n=0);
 
}
	










//=========================================================================================================================================
int main(){
	FILE *f ;
	int n=NULL;
	int *p=&n;
	do{		
	gotoxy(30,5); vebang(1,218);
	gotoxy(31,5); vebang(50,196); printf("%c",191);
	gotoxy(30,6); printf("%c",179);
	gotoxy(81,6); printf("%c",179);
	gotoxy(30,7); printf("%c",195);
	gotoxy(31,7); vebang(50,196);printf("%c",180);
	gotoxy(81,8); printf("%c",179);
	gotoxy(30,9); printf("%c",179);
	gotoxy(81,9); printf("%c",179);
	gotoxy(30,10); printf("%c",179);
	gotoxy(31,11); vebang(50,196); printf("%c",180);
	gotoxy(30,11); printf("%c",195);
	gotoxy(81,10);  printf("%c",179);
	gotoxy(30,8);printf("%c",179);
	gotoxy(30,13);printf("%c",192);
	gotoxy(81,12);printf("%c",179);
	gotoxy(30,12);printf("%c",179);
	gotoxy(31,13);vebang(50,196); printf("%c",217);
	gotoxy(51,6);  printf(" HE THONG ");
	gotoxy(44,8);  printf(" 1. DANG NHAP VAO HE THONG");
	gotoxy(44,10);  printf(" 6. THOAT KHOI HE THONG");
	gotoxy(44,12);  printf("HAY CHON CHUC NANG:");
	scanf("%d",&n);
	system("cls");	
	if(n==1){
	char acc[20],account[20]="levanthanhduy";
	char pass[10],password[10]="thanhduy";
    int s, i=0;
	dangnhap:
	gotoxy(30,5); vebang(1,218);
	gotoxy(31,5); vebang(50,196); printf("%c",191);
	gotoxy(30,6); printf("%c",179);
	gotoxy(81,6); printf("%c",179);
	gotoxy(30,7); printf("%c",195);
	gotoxy(31,7); vebang(50,196);printf("%c",180);
	gotoxy(81,8); printf("%c",179);
	gotoxy(30,9); printf("%c",179);
	gotoxy(81,9); printf("%c",179);
	gotoxy(30,10); printf("%c",179);
	gotoxy(31,11); vebang(50,196); printf("%c",180);
	gotoxy(30,11); printf("%c",195);
	gotoxy(81,10);  printf("%c",179);
	gotoxy(30,8);printf("%c",179);
	gotoxy(30,13);printf("%c",192);
	gotoxy(81,12);printf("%c",179);
	gotoxy(30,12);printf("%c",179);
	gotoxy(31,13);vebang(50,196); printf("%c",217);
	gotoxy(51,6);  printf(" DANG NHAP ");
	gotoxy(44,8);  printf(" TAI KHOAN: ");
	gotoxy(44,10);  printf(" MAT KHAU: ");
	gotoxy(55,8);	scanf("%s",acc);
	gotoxy(54,10);scanf("%s",pass);
    if( (strcmp(acc,account)==0) and strcmp(pass,password)==0)
	{
        system("cls");
        menu();
    }
    else{   
		fflush(stdin);
		gotoxy(35,12);	printf("SAI THONG TIN DANG NHAP.");
      	gotoxy(59,12);  printf("CHON 1 DE THU LAI:");
        scanf("%d",&s);
        if (s==1) {
            system("cls");
            goto dangnhap;
        }
        if (s!=1) 
		{
			foo();
	
		}
    }
	system("cls");
	menu();
			int m=NULL;
			int *q=&m;
			do{
				gotoxy(44,16);printf("HAY CHON CHUC NANG:");
				scanf("%d",&m);
				system("cls");
				if(m==1){			
					nhapttsp();
				}
				if(m==2) {
					nhapttnv();	
				}
				if(m==3){
				nhapttkh();
				}
				if(m==4){
				system("cls");
				baocao();
				pressAnyKey();	
				}
				if(m==6){
					*q=5;
					*p=6;
				}
					if (m==7){
						gotoxy(44,2);printf("KHONG CO CHUC NANG");
						menu();
					}	
				
			}while(m!=5);
		}	

	}

	while(n!=6);
}





	
