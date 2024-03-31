#pragma once
//
//#include<Windows.h>
//#include<Mmsystem.h>
//#include <graphics.h>
//#include <conio.h>
//#include<bits/stdc++.h>
//
//#pragma comment(lib,"winmm.lib")
//MCIERROR mciSendString(
//	LPCTSTR lpszCommand, 
//	LPTSTR lpszReturnString, 
//	UINT cchReturn,   
//	HANDLE hwndCallback 
//);
//
//typedef struct button
//{
//	int x;
//	int y;
//	int w;
//	int h;
//	COLORREF curcolor;
//	COLORREF oldcolor;
//	char* c;
//
//
//}button, * linkbutton;
//
//
//
//
//l/*inkbutton create(int x, int y, int w, int h, unsigned int curcolor,const char* str)
//{
//	linkbutton pbutton = new button;
//	if (pbutton == NULL)exit(-2);
//	pbutton->x = x;
//	pbutton->y = y;
//	pbutton->w = w;
//	pbutton->h = h;
//	pbutton->curcolor = curcolor;
//	pbutton->oldcolor = curcolor;
//
//	int length = strlen(str);
//	pbutton->c = new char[length + 1];
//	if (pbutton->c == NULL)return NULL;
//	
//	return pbutton;
//}*/
//
//
//
////
////
////
////int main()
////{
//	
//	initgraph(700, 700);
//	IMAGE img;
//	loadimage(&img, "D:\\res.jpg",700,700);
//	ExMessage msg;w
//
//	while (1)
//	{
//		mciSendString("open  a alias music", 0, 0, 0);
//		mciSendString("play music", 0, 0, 0);
//		BeginBatchDraw();
//		putimage(0, 0, &img);
//		linkbutton play = create(320, 320, 10, 15, RGB(255, 255, 148), "music_play");
//		show(play);
//		_getch();
//
//
//	}

//	EndBatchDraw();
//	closegraph();
//	return 0;
//
//	
//}
