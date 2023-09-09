#include <stdio.h>
#include <conio.h>
#include <windows.h>

//Ham di chuyen con tro den vi tri cot x hang y
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
//Ham ve ky tu dang bang voi ky tu can ve va so lan ve
void vebang(unsigned char solan, unsigned char kytu)
{
	for(int i=1;i<=solan;i++)
		printf("%c",kytu);
}
