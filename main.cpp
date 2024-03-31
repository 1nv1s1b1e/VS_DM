#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
#include<mmsystem.h>//包含多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")


#define width_ 53
#define height_ 60
using namespace std;
typedef struct
{
	int x; // 按钮左上角x坐标
	int y; // 按钮左上角y坐标
	int width; // 按钮宽度
	int height; // 按钮高度
	float scale; // 缩放比例，用于实现鼠标悬停效果
	bool isMouseOver; // 表示鼠标是否在按钮上方
	char text[20]; // 按钮文本
	bool isclick;

}Button;

//对局信息存储 AI play函数 红方为人类

int cnt = 0;
int basic_value[] = {0, 500,300,50,50,10000,300,100 };//当前局面分计算 计算两层黑方走了之后红方再走 //车和马
//1-7

//得分
int  hong_juposition[11][10] ={
		{0,0,0,0,0,0,0,0,0,0},
		{0,-6, 6, 4, 12, 0, 12, 4, 6, -6},
		{0,5, 8, 6, 12, 0, 12, 6, 8, 5},
		{0,-2, 8, 4, 12, 12, 12, 4, 8, -2},
		{0,4, 9, 4, 12, 14, 12, 4, 9, 4},
		{0,8, 12, 12, 14, 15, 14, 12, 12, 8},
		{0,8, 11, 11, 14, 15, 14, 11, 11, 8},
		{0,6, 13, 13, 16, 16, 16, 13, 13, 6},
		{0,6, 8, 7, 14, 16, 14, 7, 8, 6},
		{0,6, 12, 9, 16, 33, 16, 9, 12, 6},
		{0,6, 8, 7, 13, 14, 13, 7, 8, 6}
};
//吃子得到分数

//枚举走法，遍历棋盘，得分最高的走法与我方的走法
int hei_juposition[11][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,6, 8, 7, 13, 14, 13, 7, 8, 6},
		{0,6, 12, 9, 16, 33, 16, 9, 12, 6},
		{0,6, 8, 7, 14, 16, 14, 7, 8, 6},
		{0,6, 13, 13, 16, 16, 16, 13, 13, 6},
		{0,8, 11, 11, 14, 15, 14, 11, 11, 8},
		{0,8, 12, 12, 14, 15, 14, 12, 12, 8},
		{0,4, 9, 4, 12, 14, 12, 4, 9, 4},
		{0,-2, 8, 4, 12, 12, 12, 4, 8, -2},
		{0,5, 8, 6, 12, 0, 12, 6, 8, 5},
		{0,-6, 6, 4, 12, 0, 12, 4, 6, -6}
};

int hong_shuaiposition[11][10] ={
		{0,0,0,0,0,0,0,0,0,0},
		{0,0, 0, 0, 1, 5, 1, 0, 0, 0},
		{0,0, 0, 0, -8, -8, -8, 0, 0, 0},
		{0,0, 0, 0, -9, -9, -9, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int hei_shuaiposition[11][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, -9, -9, -9, 0, 0, 0},
		{0,0, 0, 0, -8, -8, -8, 0, 0, 0},
		{0,0, 0, 0, 1, 5, 1, 0, 0, 0},
};

int hong_shiposition[11][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 3, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int hei_shiposition[11][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 3, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int   hong_xiangposition[11][10] = {
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,-2, 0, 0, 0, 3, 0, 0, 0, -2},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int hei_xiangposition[11][10] = {
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,-2, 0, 0, 0, 3, 0, 0, 0, -2},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0}


};
int  hong_maposition[11][10] = {
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, -3, 2, 0, 2, 0, 2, -3, 0},
		{0,-3, 2, 4, 5, -10, 5, 4, 2, -3},
		{0,5, 4, 6, 7, 4, 7, 6, 4, 5},
		{0,4, 6, 10, 7, 10, 7, 10, 6, 4},
		{0,2, 10, 13, 14, 15, 14, 13, 10, 2},
		{0,2, 10, 13, 14, 15, 14, 13, 10, 2},
		{0,2, 12, 11, 15, 16, 15, 11, 12, 2},
		{0,5, 20, 12, 19, 12, 19, 12, 20, 5},
		{0,4, 10, 11, 15, 11, 15, 11, 10, 4},
		{0,2, 8, 15, 9, 6, 9, 15, 8, 2},
		
};

int hei_maposition[11][10] = {
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,2, 8, 15, 9, 6, 9, 15, 8, 2},
		{0,4, 10, 11, 15, 11, 15, 11, 10, 4},
		{0,5, 20, 12, 19, 12, 19, 12, 20, 5},
		{0,2, 12, 11, 15, 16, 15, 11, 12, 2},
		{0,2, 10, 13, 14, 15, 14, 13, 10, 2},
		{0,2, 10, 13, 14, 15, 14, 13, 10, 2},
		{0,4, 6, 10, 7, 10, 7, 10, 6, 4},
		{0,5, 4, 6, 7, 4, 7, 6, 4, 5},
		{0,-3, 2, 4, 5, -10, 5, 4, 2, -3},
		{0,0, -3, 2, 0, 2, 0, 2, -3, 0},
};
int	 hong_paoposition[11][10] = {
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 1, 3, 3, 3, 1, 0, 0},
		{0,0, 1, 2, 2, 2, 2, 2, 1, 0},
		{0,1, 0, 4, 3, 5, 3, 4, 0, 1},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,-2, 0, -2, 0, 6, 0, -2, 0, -2},
		{0,3, 0, 4, 0, 7, 0, 4, 0, 3},
		{0,10, 18, 22, 35, 40, 35, 22, 18, 10},
		{0,20, 27, 30, 40, 42, 40, 30, 27, 20},
		{0,20, 30, 45, 55, 55, 55, 45, 30, 20},
		{0,20, 15, 50, 65, 70, 65, 50, 15, 20},
		
};
int hei_paoposition[11][10] = {
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,20, 30, 50, 65, 70, 65, 50, 30, 20},
		{0,20, 30, 45, 55, 55, 55, 45, 30, 20},
		{0,20, 27, 30, 40, 42, 40, 30, 27, 20},
		{0,10, 18, 22, 35, 40, 35, 22, 18, 10},
		{0,3, 0, 4, 0, 7, 0, 4, 0, 3},
		{0,-2, 0, -2, 0, 6, 0, -2, 0, -2},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,1, 0, 4, 3, 5, 3, 4, 0, 1},
		{0,0, 1, 2, 2, 2, 2, 2, 1, 0},
		{0,0, 0, 1, 3, 3, 3, 1, 0, 0}
};

int   hong_bingposition[11][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,-2, 0, -2, 0, 6, 0, -2, 0, -2},
		{0,3, 0, 4, 0, 7, 0, 4, 0, 3},
		{0,10, 18, 22, 35, 40, 35, 22, 18, 10},
		{0,20, 27, 30, 40, 42, 40, 30, 27, 20},
		{0,20, 30, 50, 65, 70, 65, 50, 30, 20},
		{0,0, 0, 0, 2, 4, 2, 0, 0, 0}


		
	
};

int hei_bingposition[11][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0, 0, 0, 2, 4, 2, 0, 0, 0},
		{0,20, 30, 50, 65, 70, 65, 50, 30, 20},
		{0,20, 27, 30, 40, 42, 40, 30, 27, 20},
		{0,10, 18, 22, 35, 40, 35, 22, 18, 10},
		{0,3, 0, 4, 0, 7, 0, 4, 0, 3},
		{0,-2, 0, -2, 0, 6, 0, -2, 0, -2},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0,0, 0, 0, 0, 0, 0, 0, 0, 0},


};





void show_author();

void updatewithoutin(int stx, int sty, int tarx, int tary);

void redraw(int t, int i, int j);

void qipu_generate(bool who, int stx, int sty, int tarx, int tary);

void output(string t, bool who);

void sound_play(bool who, int tarx, int tary,int x);

void drawButton(Button t);

bool checkMouseOver(int x, int y, Button t);

bool check(int x, int y, Button t);

void huiqi();

bool judge_jiangjun(bool st);

bool AI_play();
int caculate_point(int starx, int stary, int tarx, int tary);
int caculate_hong(int strx,int stry,int tarx,int tary);



int x_val[] = { 0,10,64,114,169,225,277,328,382,436 };//绘图数组 //10行9列  这里x是列 y是行
int y_val[] = { 0,14,74,134,194,254,314,374,434,494,555 };


int pre_hei[11][10], pre_hong[11][10];





//车马相士将炮兵 1-7
//黑方的为11-17
//先直接放在d盘下



Button button1, button2, button3, button4;//初始界面三个按钮
Button menu[] = { button1,button2,button3,button4 };


Button back1, lastmove, chonglai;
Button button_control[] = { back1,lastmove,chonglai };//game界面三个按钮

Button sound1_control, sound2_control,back2;//设置三个按钮
Button volume_control[] = { sound1_control,sound2_control,back2};


bool sound2 = true;

bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;



void updatewithoutin(int stx, int sty, int tarx, int tary);

void redraw(int t, int i, int j);

void qipu_generate(bool who, int stx, int sty, int tarx, int tary);

void output(string t, bool who);

void sound_play(bool who, int tarx, int tary);

void drawButton(Button t);

bool checkMouseOver(int x,int y,Button t);


void bgm_close();

void bgm_play();

int huihe_count = 1;
int bushu;



struct DOT//存储每个棋子的像素点位
{
	int x;
	int y;
}dot[11][10];

//我方为红方
//该点为0则没有子

//棋盘
int board1[11][10] = {//让横纵下标从1开始
	{0,0,0,0,0,0,0,0,0},
	{0,1,2,3,4,5,4,3,2,1},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,6,0,0,0,0,0,6,0},
	{0,7,0,7,0,7,0,7,0,7},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,-7,0,-7,0,-7,0,-7,0,-7},
	{0,0,-6,0,0,0,0,0,-6,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,-1,-2,-3,-4,-5,-4,-3,-2,-1}
};

//我方为黑方
int board2[10][9] = {//暂时未改

	{1,2,3,4,5,4,3,2,1},
	{0,0,0,0,0,0,0,0,0},
	{0,6,0,0,0,0,0,6,0},
	{7,0,7,0,7,0,7,0,7},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{-7,0,-7,0,-7,0,-7,0,-7},
	{0,-6,0,0,0,0,0,-6,0},
	{0,0,0,0,0,0,0,0,0},
	{-1,-2,-3,-4,-5,-4,-3,-2,-1}


};

//备份数组(用来重置棋盘)
int backup[11][10] = {//让横纵下标从1开始
	{0,0,0,0,0,0,0,0,0},
	{0,1,2,3,4,5,4,3,2,1},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,6,0,0,0,0,0,6,0},
	{0,7,0,7,0,7,0,7,0,7},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,-7,0,-7,0,-7,0,-7,0,-7},
	{0,0,-6,0,0,0,0,0,-6,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,-1,-2,-3,-4,-5,-4,-3,-2,-1}
};

//悔棋棋盘
int hq[11][10] = {//让横纵下标从1开始
	{0,0,0,0,0,0,0,0,0},
	{0,1,2,3,4,5,4,3,2,1},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,6,0,0,0,0,0,6,0},
	{0,7,0,7,0,7,0,7,0,7},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,-7,0,-7,0,-7,0,-7,0,-7},
	{0,0,-6,0,0,0,0,0,-6,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,-1,-2,-3,-4,-5,-4,-3,-2,-1}
};

int now[11][10] = {
	{0,0,0,0,0,0,0,0,0},
	{0,1,2,3,4,5,4,3,2,1},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,6,0,0,0,0,0,6,0},
	{0,7,0,7,0,7,0,7,0,7},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,-7,0,-7,0,-7,0,-7,0,-7},
	{0,0,-6,0,0,0,0,0,-6,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,-1,-2,-3,-4,-5,-4,-3,-2,-1}
};//人机对战棋盘

//人机对战中直接在上面的board棋盘上模拟

void drawAlpha(IMAGE* picture, int  picture_x, int picture_y)
{


	DWORD* dst = GetImageBuffer();
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture);
	int picture_width = picture->getwidth();
	int picture_height = picture->getheight();
	int graphWidth = getwidth();
	int graphHeight = getheight();
	int dstX = 0;


	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width;
			int sa = ((src[srcX] & 0xff000000) >> 24);
			int sr = ((src[srcX] & 0xff0000) >> 16);
			int sg = ((src[srcX] & 0xff00) >> 8);
			int sb = src[srcX] & 0xff;
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth;
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)
					| (sb * sa / 255 + db * (255 - sa) / 255);
			}
		}
	}
}

class chess_self
{
public:
	IMAGE img11, img12;//车
	IMAGE img21, img22;//马
	IMAGE img31, img32;//炮
	IMAGE img41, img42;//相
	IMAGE img51, img52;//士
	IMAGE img6;//帅
	IMAGE img71, img72, img73, img74, img75;//兵


};
chess_self red, black;



//游戏画面
void startup(chess_self& A, chess_self& B) {

	//红
	loadimage(&A.img11, "D://1.png", 50, 50);//车
	drawAlpha(&A.img11, 10, 14);
	loadimage(&A.img12, "D://1.png", 50, 50);
	drawAlpha(&A.img12, 436, 14);

	loadimage(&A.img21, "D://2.png", 50, 50);//马
	drawAlpha(&A.img21, 64, 14);
	loadimage(&A.img22, "D://2.png", 50, 50);
	drawAlpha(&A.img22, 382, 14);

	loadimage(&A.img31, "D://6.png", 50, 50);//炮
	drawAlpha(&A.img31, 64, 134);
	loadimage(&A.img32, "D://6.png", 50, 50);
	drawAlpha(&A.img32, 382, 134);

	loadimage(&A.img41, "D://3.png", 50, 50);//相
	drawAlpha(&A.img41, 114, 14);
	loadimage(&A.img42, "D://3.png", 50, 50);
	drawAlpha(&A.img42, 328, 14);

	loadimage(&A.img51, "D://4.png", 50, 50);//士
	drawAlpha(&A.img51, 169, 14);
	loadimage(&A.img52, "D://4.png", 50, 50);
	drawAlpha(&A.img52, 277, 14);

	loadimage(&A.img6, "D://5.png", 50, 50);//帅
	drawAlpha(&A.img6, 225, 14);


	loadimage(&A.img71, "D://7.png", 50, 50);//兵
	drawAlpha(&A.img71, 10, 194);
	loadimage(&A.img72, "D://7.png", 50, 50);
	drawAlpha(&A.img72, 114, 194);
	loadimage(&A.img73, "D://7.png", 50, 50);
	drawAlpha(&A.img73, 225, 194);
	loadimage(&A.img74, "D://7.png", 50, 50);
	drawAlpha(&A.img74, 328, 194);
	loadimage(&A.img75, "D://7.png", 50, 50);
	drawAlpha(&A.img75, 436, 194);


	//黑
	loadimage(&B.img11, "D://11.png", 50, 50);//车
	drawAlpha(&B.img11, 10, 555);
	loadimage(&B.img12, "D://11.png", 50, 50);
	drawAlpha(&B.img12, 436, 555);

	loadimage(&B.img21, "D://12.png", 50, 50);//马
	drawAlpha(&B.img21, 64, 555);
	loadimage(&B.img22, "D://12.png", 50, 50);
	drawAlpha(&B.img22, 382, 555);

	loadimage(&B.img31, "D://16.png", 50, 50);//炮
	drawAlpha(&B.img31, 64, 434);
	loadimage(&B.img32, "D://16.png", 50, 50);
	drawAlpha(&B.img32, 382, 434);

	loadimage(&B.img41, "D://13.png", 50, 50);//相
	drawAlpha(&B.img41, 114, 555);
	loadimage(&B.img42, "D://13.png", 50, 50);
	drawAlpha(&B.img42, 328, 555);

	loadimage(&B.img51, "D://14.png", 50, 50);//士
	drawAlpha(&B.img51, 169, 555);
	loadimage(&B.img52, "D://14.png", 50, 50);
	drawAlpha(&B.img52, 277, 555);

	loadimage(&B.img6, "D://15.png", 50, 50);//帅
	drawAlpha(&B.img6, 225, 555);

	loadimage(&B.img71, "D://17.png", 50, 50);//兵
	drawAlpha(&B.img71, 10, 374);
	loadimage(&B.img72, "D://17.png", 50, 50);
	drawAlpha(&B.img72, 114, 374);
	loadimage(&B.img73, "D://17.png", 50, 50);
	drawAlpha(&B.img73, 225, 374);
	loadimage(&B.img74, "D://17.png", 50, 50);
	drawAlpha(&B.img74, 328, 374);
	loadimage(&B.img75, "D://17.png", 50, 50);
	drawAlpha(&B.img75, 436, 374);

}
//鼠标按键判定区域

//判断走子是否合法
bool judge_ju(bool who, int stx, int sty, int tarx, int tary)//应从stx/sty向两边搜
{

	if (who == 1)
	{
		if (board1[tarx][tary] > 0)
		{
			return false;
		}

	}
	else
	{
		if (board1[tarx][tary] < 0)
		{
			return false;
		}
	}

	//在同一行
	if ((tarx != stx && tary != sty) || (tarx == stx && tary == sty))//原地走不行，不同行不同列也不行
	{
		return false;

	}
	else if (tarx == stx)//同一行
	{
		if (tary > sty)
		{
			for (int i = sty + 1; i < tary; i++)
			{
				if (board1[stx][i] != 0)
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			for (int i = tary + 1; i < sty; i++)
			{
				if (board1[stx][i] != 0)
				{
					return false;
				}
			}
			return true;
		}

	}
	else//同一列
	{

		if (tarx > stx)
		{
			for (int i = stx + 1; i < tarx; i++)
			{
				if (board1[i][sty] != 0)
				{

					return false;
				}
			}
			return true;
		}
		else
		{
			for (int i = tarx + 1; i < stx; i++)
			{
				if (board1[i][sty] != 0)
				{
					return false;
				}
			}

			return true;
		}

	}


}

bool judge_ma(bool who, int stx, int sty, int tarx, int tary)
{
	/*int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
	int dy[] = { 2,1,-1,-2,-2,-1,1,2 };*/
	//不能一起判(恶心

	if (who == 1)
	{
		if (board1[tarx][tary] > 0)return false;
	}
	else
	{
		if (board1[tarx][tary] < 0)return false;
	}

	if (tary - sty == 1 && tarx - stx == -2)//顺时针转
	{

		if (board1[stx - 1][sty] != 0)return false;//塞住
		else return true;
	}
	else if (tary - sty == 2 && tarx - stx == -1)
	{
		if (board1[stx][sty + 1] != 0)return false;
		else return true;
	}
	else if (tary - sty == 2 && tarx - stx == 1)
	{
		if (board1[stx][sty + 1] != 0)return false;
		else return true;
	}
	else if (tary - sty == 1 && tarx - stx == 2)
	{
		if (board1[stx + 1][sty] != 0)return false;
		else return true;
	}
	else if (tary - sty == -1 && tarx - stx == 2)
	{
		if (board1[stx + 1][sty] != 0)return false;
		else return true;
	}
	else if (tary - sty == -2 && tarx - stx == 1)
	{
		if (board1[stx][sty - 1] != 0)return false;
		else return true;
	}
	else if (tary - sty == -2 && tarx - stx == -1)
	{
		if (board1[stx][sty - 1] != 0)return false;
		else return true;
	}
	else if (tary - sty == -1 && tarx - stx == -2)
	{
		if (board1[stx - 1][sty] != 0)return false;
		else return true;
	}
	else return false;




}

bool judge_xiang(bool who, int stx, int sty, int tarx, int tary)//下面红方的情况 起点位置一定是合法的
{
	//在自己一方
	if (who == 1)//这里还要判断是否到对面的区域了
	{
		if (board1[tarx][tary] > 0)return false;//自己的子不能吃
		if (tarx > 5)return false;//不能飞到对面区域
	}
	else
	{
		if (board1[tarx][tary] < 0)return false;
		if (tarx < 6)return false;
	}
	//需要判断塞相眼 （未完成）
	if (who == 1) {
		if (sty == 1)
		{
			if (abs(tary - sty) == 2)
			{
				if (tarx == 1 && board1[2][2] == 0 || tarx == 5 && board1[4][2] == 0)//合法位置且不塞相眼
				{
					return true;
				}
				else return false;
			}
			else return false;
		}
		else if (sty == 3)//以下未完成
		{
			if (tary == 1)
			{
				if (stx == 1)
				{
					if (board1[2][2] == 0 && tarx == 3)
					{
						return true;
					}
					else return false;
				}
				else if (stx == 5)
				{
					if (board1[4][2] == 0 && tarx == 3)
					{
						return true;
					}
					else return false;
				}
				else return false;

			}
			else if (tary == 5)
			{
				if (stx == 1)
				{
					if (board1[2][4] == 0 && tarx == 3)
					{
						return true;
					}
					else return false;
				}
				else if (stx == 5)
				{
					if (board1[4][4] == 0 && tarx == 3)
					{
						return true;
					}
					else return false;
				}
				else return false;
			}
			else return false;



		}
		else if (sty == 5)
		{
			if (tary == 3) {
				if (tarx == 1 && board1[2][4] == 0 || tarx == 5 && board1[4][4] == 0)
				{
					return true;
				}
				else return false;
			}
			else if (tary == 7)
			{
				if (tarx == 1 && board1[2][6] == 0 || tarx == 5 && board1[4][6] == 0)
				{
					return true;
				}
				else return false;
			}
			else return false;

		}
		else if (sty == 7)
		{
			if (tary == 5)
			{
				if (stx == 1)
				{
					if (board1[2][6] == 0 && tarx == 3)
					{
						return true;
					}
					else return false;
				}
				else if (stx == 5)
				{
					if (board1[4][6] == 0 && tarx == 3)
					{
						return true;
					}
					else return false;
				}
				else return false;

			}
			else if (tary == 9)
			{
				if (stx == 1)
				{
					if (board1[2][8] == 0 && tarx == 3)
					{
						return true;
					}
					else return false;
				}
				else if (stx == 5)
				{
					if (board1[4][8] == 0 && tarx == 3)
					{
						return true;
					}
					else return false;
				}
				else return false;
			}

		}
		else if (sty == 9)
		{
			if (abs(tary - sty) == 2)
			{
				if (tarx == 1 && board1[2][8] == 0 || tarx == 5 && board1[4][8] == 0)//合法位置且不塞相眼
				{
					return true;
				}
				else return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (sty == 1)
		{
			if (abs(tary - sty) == 2)
			{
				if (tarx == 6 && board1[7][2] == 0 || tarx == 10 && board1[9][2] == 0)//合法位置且不塞相眼
				{
					return true;
				}
				else return false;
			}
		}
		else if (sty == 3)//以下未完成
		{
			if (tary == 1)
			{
				if (stx == 10)
				{
					if (board1[9][2] == 0 && tarx == 8)
					{
						return true;
					}
					else return false;
				}
				else if (stx == 6)
				{
					if (board1[7][2] == 0 && tarx == 8)
					{
						return true;
					}
					else return false;
				}
				else return false;

			}
			else if (tary == 5)
			{
				if (stx == 10)
				{
					if (board1[9][4] == 0 && tarx == 8)
					{
						return true;
					}
					else return false;
				}
				else if (stx == 6)
				{
					if (board1[7][4] == 0 && tarx == 8)
					{
						return true;
					}
					else return false;
				}
				else return false;
			}






		}
		else if (sty == 5)
		{
			if (tary == 3) {
				if (tarx == 10 && board1[9][4] == 0 || tarx == 6 && board1[7][4] == 0)
				{
					return true;
				}
				else return false;
			}
			else if (tary == 7)
			{
				if (tarx == 10 && board1[9][6] == 0 || tarx == 6 && board1[7][6] == 0)
				{
					return true;
				}
				else return false;
			}
			else return false;

		}
		else if (sty == 7)
		{
			if (tary == 5)
			{
				if (stx == 10)
				{
					if (board1[9][6] == 0 && tarx == 8)
					{
						return true;
					}
					else return false;
				}
				else if (stx == 6)
				{
					if (board1[7][6] == 0 && tarx == 8)
					{
						return true;
					}
					else return false;
				}
				else return false;

			}
			else if (tary == 9)
			{
				if (stx == 10)
				{
					if (board1[9][8] == 0 && tarx == 8)
					{
						return true;
					}
					else return false;
				}
				else if (stx == 6)
				{
					if (board1[7][8] == 0 && tarx == 8)
					{
						return true;
					}
					else return false;
				}
				else return false;
			}

		}
		else if (sty == 9)
		{
			if (abs(tary - sty) == 2)
			{
				if (tarx == 10 && board1[9][8] == 0 || tarx == 6 && board1[7][8] == 0)//合法位置且不塞相眼
				{
					return true;
				}
				else return false;
			}
		}
		else
		{
			return false;
		}



	}




}

bool judge_shi(bool who, int stx, int sty, int tarx, int tary)
{
	if (who == 1)
	{
		if (board1[tarx][tary] > 0)return false;
	}
	else
	{
		if (board1[tarx][tary] < 0)return false;
	}

	if (abs(tarx - stx) == 1 && abs(tary - sty) == 1 && tary >= 4 && tary <= 6)//只能在九宫格中走
	{
		return true;
	}
	return false;








}

bool judge_shuai(bool who, int stx, int sty, int tarx, int tary)//这里将帅不能对面
{
	if (who == 1)
	{
		if (board1[tarx][tary] > 0)return false;
	}
	else
	{
		if (board1[tarx][tary] < 0)return false;
	}
	if ((abs(tarx - stx) == 1 && abs(tary - sty) == 0 || (abs(tarx - stx) == 0 && abs(tary - sty) == 1)) && tary >= 4 && tary <= 6)//只能在九宫格中走
	{
		return true;
	}
	return false;






}

bool judge_pao(bool who, int stx, int sty, int tarx, int tary)//最烦的一个(然而并不是）
{
	if (who == 1)
	{
		if (board1[tarx][tary] > 0 || (stx == tarx && sty == tary) || (stx != tarx && sty != tary))return false;
	}
	else
	{
		if (board1[tarx][tary] < 0 || (stx == tarx && sty == tary) || (stx != tarx && sty != tary))return false;
	}

	if (tarx == stx)//在同一行
	{
		//遍历该行，若该处有子，若两者之间没子或者大于等于两个子，则无法移动
		//若该处没有子，两者之间没有子，可以移动，若有子则不可移动
		int cnt = 0;
		int a = min(tary, sty);
		int b = max(tary, sty);
		for (int i = a + 1; i < b; i++)
		{
			if (board1[stx][i] != 0)
			{
				cnt++;
				if (cnt >= 2)
				{
					return false;
				}
			}
		}
		if (board1[tarx][tary] != 0)
		{
			if (cnt == 1)return true;
			else return false;
		}
		else
		{
			if (cnt == 0)return true;
			else return false;
		}


	}
	else if (tary == sty)
	{
		int cnt = 0;
		int a = min(tarx, stx);
		int b = max(tarx, stx);
		for (int i = a + 1; i < b; i++)
		{
			if (board1[i][sty] != 0)
			{
				cnt++;
				if (cnt >= 2)
				{
					return false;
				}
			}
		}
		if (board1[tarx][tary] != 0)
		{
			if (cnt == 1)return true;
			else return false;
		}
		else
		{
			if (cnt == 0)return true;
			else return false;
		}
	}



}

bool judge_bing(bool who, int stx, int sty, int tarx, int tary)
{
	//判断
	if (who == 1)
	{
		if (board1[tarx][tary] > 0)return false;
	}
	else
	{
		if (board1[tarx][tary] < 0)return false;
	}

	//判断是否在对方区域



	//分红方和黑方
	if (who == 1)
	{
		//分过河和未过河
		if (stx > 5)//过河了
		{
			if ((tarx - stx == 1 && sty == tary) || (stx == tarx && abs(tary - sty) == 1))
			{
				return true;
			}
			else return false;

		}
		else
		{
			if (tarx - stx == 1 && sty == tary)//未过河只能向前走
			{
				return true;
			}
			else return false;


		}
	}
	else
	{
		if (stx < 6)//过河了
		{
			if ((stx - tarx == 1 && sty == tary) || (stx == tarx && abs(tary - sty) == 1))
			{
				return true;
			}
			else return false;

		}
		else
		{
			if (stx - tarx == 1 && sty == tary)
			{
				return true;
			}
			else return false;


		}


	}

}

bool judge_move(int t, bool who, int stx, int sty, int tarx, int tary)//四个参数  两个坐标信息 两个坐标
{
	if (who == true)// 判断红走
	{
		if (t == 1)//走车
		{
			if (judge_ju(who, stx, sty, tarx, tary))//传入起始坐标和终点坐标
			{
				return true;
			}
			else
			{
				return false;
			}



		}
		if (t == 2)//走马
		{
			if (judge_ma(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}


		}
		if (t == 3)//走相
		{
			if (judge_xiang(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (t == 4)//走仕
		{
			if (judge_shi(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (t == 5)
		{
			if (judge_shuai(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (t == 6)
		{
			if (judge_pao(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (t == 7)//兵的判断要分阶段(在对方区域可以左右走）
		{
			if (judge_bing(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
	}
	else//判断黑走
	{
		if (abs(t) == 1)//走车
		{
			if (judge_ju(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}


		}
		if (abs(t) == 2)
		{
			if (judge_ma(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}


		}
		if (abs(t) == 3)
		{
			if (judge_xiang(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (abs(t) == 4)
		{
			if (judge_shi(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (abs(t) == 5)
		{
			if (judge_shuai(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (abs(t) == 6)
		{
			if (judge_pao(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (abs(t) == 7)//卒
		{
			if (judge_bing(who, stx, sty, tarx, tary))
			{
				return true;
			}
			else
			{
				return false;
			}

		}

	}


}

bool game()//走过之后才悔棋
{
	//在底下画几个按钮 //同时实现功能
	
	button_control[0] = { 30,660,120,25,1,false,"返回",false };
	button_control[1] = { 180,660,120,25,1,false,"悔棋",false };
	button_control[2] = { 330,660,120,25,1,false,"重来",false };
	for (auto t : button_control)
	{
		drawButton(t);

	}
	MOUSEMSG m;
	//红方先走
	bool hong = 0, hei = 0;
	int start_x1, start_y1, start_x2, start_y2;
	int target_x1, target_y1, target_x2, target_y2;

	bool back_flag = 0;

	if (huihe_count == 24)
	{
		huihe_count = 1;
		bushu = 0;
		clearrectangle(500, 0, 700, 700);
	}
	//判断红方选择棋子并下棋
	while (1)
	{
		
		m = GetMouseMsg();

		int wzx = m.x, wzy = m.y;
		BeginBatchDraw();
		for (auto t : button_control)
		{
			checkMouseOver(wzx, wzy, t);
			drawButton(t);
			FlushBatchDraw();
		}
		EndBatchDraw();
	

		if (m.uMsg == WM_LBUTTONDOWN)//先选中(判定是否选择自己的棋子）
		{
			
			int x_ = m.x;
			int y_ = m.y;
			//判断三个按钮是否按下
			if (check(x_, y_, button_control[0]))//返回
			{
				cleardevice();
				back_flag = 1;
				memcpy(board1, backup, sizeof(backup));
				huihe_count = 1;
				bushu = 0;
				break;

			}
			if (check(x_, y_, button_control[1])&&bushu!=0)//减掉步数
			{
				bushu--;
				
				memcpy(board1, pre_hei, sizeof(pre_hei));
				clearrectangle(0, 0, 500, 640);
				
				clearrectangle(610,(huihe_count-2)*30 , 700, (huihe_count-1)*30);
				huihe_count--;
				IMAGE img;
				loadimage(&img, "D://qp.png", 500, 640);
				putimage(0, 0, &img);
				BeginBatchDraw();
				for (int i = 1; i <= 10; i++)
				{
					for (int j = 1; j <= 9; j++)
					{
						if (board1[i][j] == 0)
						{
							continue;
						}
						else
						{
							redraw(board1[i][j], i, j);
							
						}

					}

				}
				FlushBatchDraw();
				hei = 0, hong = 0;
				break;
			}


			if (check(x_, y_, button_control[2]))//重来
			{
				huihe_count = 1;
				bushu = 0;
				clearrectangle(500, 0, 700, 700);
				memcpy(board1, backup, sizeof(backup));
				clearrectangle(0, 0, 500, 640);
				IMAGE img;
				loadimage(&img, "D://qp.png", 500, 640);
				putimage(0, 0, &img);
				BeginBatchDraw();
				for (int i = 1; i <= 10; i++)
				{
					for (int j = 1; j <= 9; j++)
					{
						if (board1[i][j] == 0)
						{
							continue;
						}
						else
						{
							redraw(board1[i][j], i, j);

						}FlushBatchDraw();

					}

				}
				EndBatchDraw();
				hong = 0, hei = 0;
				continue;
				
			}
		
			
			if (hong == 0)//未被选中，开始选择红
			{
				for (int i = 1; i <= 10; i++)//先遍历act数组
				{
					for (int j = 1; j <= 9; j++)
					{

						if (abs(dot[i][j].x - y_) <= 20 && abs(dot[i][j].y - x_) <= 20 && board1[i][j] > 0)
						{

							start_x1 = i, start_y1 = j;
							hong = 1;

							break;
						}
					}
					if (hong == 1)break;
				}
			}
			else if (hong == 1)
			{

				int t = board1[start_x1][start_y1];//先这么写，后面棋盘翻转时直接对board赋值即可


				bool flag = 0;
				for (int i = 1; i <= 10; i++)//先遍历act数组
				{
					for (int j = 1; j <= 9; j++)
					{
						if (abs(dot[i][j].x - y_) <= 20 && abs(dot[i][j].y - x_) <= 20)
						{

							target_x1 = i, target_y1 = j;
							flag = 1;
							break;
						}

					}
					if (flag)break;
				}


				if (flag == 0)
				{
					hong = 0;
					continue;
				}

				if (judge_move(t, true, start_x1, start_y1, target_x1, target_y1))
				{
					int x = board1[target_x1][target_y1];
					qipu_generate(true, start_x1, start_y1, target_x1, target_y1);
					updatewithoutin(start_x1, start_y1, target_x1, target_y1);
					sound_play(true, target_x1, target_y1,x);//参数未传，重新绘图的函数
					memcpy(pre_hei, board1, sizeof(board1));
					
					for (int i = 1; i <= 10; i++){
						for (int j = 1; j <= 9; j++)
						{
							cout << pre_hei[i][j] << ' ';
						}
					cout << endl;
					}
					break;

					
				}
				else
				{
					hong = 0;//重新选子，因为无法移动到目标位置
					
				}

			}

		}
	} 
	

	if (back_flag == 1)return true;// 返回按钮判定
	//判断黑方选择棋子并下棋  在judge中判定是哪种走子
	while (1)
	{
		m = GetMouseMsg();

		int wzx = m.x, wzy = m.y;
		BeginBatchDraw();
		for (auto t : button_control)
		{
			checkMouseOver(wzx, wzy, t);
			drawButton(t);
			FlushBatchDraw();
		}
		EndBatchDraw();

		if (m.uMsg == WM_LBUTTONDOWN)//先选中(判定是否选择自己的棋子）
		{
			int x_ = m.x;

			int y_ = m.y;

			
			if (check(x_, y_, button_control[0]))//返回
			{
				cleardevice();
				back_flag = 1;
				memcpy(board1, backup, sizeof(backup));
				huihe_count = 1;
				bushu = 0;
				break;

			}
			//判红悔棋
			if (check(x_, y_, button_control[1]))
			{
				bushu--;
				
					memcpy(board1, pre_hong, sizeof(pre_hong));
					clearrectangle(0, 0, 500, 640);
					clearrectangle(500, (huihe_count - 1) * 30, 600, (huihe_count) * 30);
					IMAGE img;
					loadimage(&img, "D://qp.png", 500, 640);
					putimage(0, 0, &img);
					BeginBatchDraw();
					for (int i = 1; i <= 10; i++)
					{
						for (int j = 1; j <= 9; j++)
						{
							if (board1[i][j] == 0)
							{
								continue;
							}
							else
							{
								redraw(board1[i][j], i, j);
							}
						}

					}
					FlushBatchDraw();
					hong = 0, hei = 0;
					break;
			}
			

			
			if (check(x_, y_, button_control[2]))//重来
			{
				huihe_count = 1;
				bushu = 0;
				clearrectangle(500, 0, 700, 700);
				memcpy(board1, backup, sizeof(backup));
				clearrectangle(0, 0, 500, 640);
				IMAGE img;
				loadimage(&img, "D://qp.png", 500, 640);
				putimage(0, 0, &img);
				BeginBatchDraw();
				for (int i = 1; i <= 10; i++)
				{
					for (int j = 1; j <= 9; j++)
					{
						if (board1[i][j] == 0)
						{
							continue;
						}
						else
						{
							redraw(board1[i][j], i, j);

						}FlushBatchDraw();

					}

				}
				EndBatchDraw();
				hong = 0, hei = 0;
				break;

			}
		
			
			if (hei == 0)//未被选中，开始选择黑
			{
				for (int i = 1; i <= 10; i++)//先遍历act数组
				{
					for (int j = 1; j <= 9; j++)
					{
						if (abs(dot[i][j].x - y_) <= 20 && abs(dot[i][j].y - x_) <= 20 && board1[i][j] < 0)
						{
							start_x2 = i, start_y2 = j;
							hei = 1;
							break;
						}
					}
					if (hei == 1)break;
				}
			}
			else if (hei == 1)
			{

				int t = board1[start_x2][start_y2];//先这么写，后面棋盘翻转时直接对board赋值即可

				bool flag = 0;
				for (int i = 1; i <= 10; i++)//先遍历act数组
				{
					for (int j = 1; j <= 9; j++)
					{
						if (abs(dot[i][j].x - y_) <= 20 && abs(dot[i][j].y - x_) <= 20)
						{
							target_x2 = i, target_y2 = j;
							flag = 1;
							break;
						}

					}
					if (flag)break;
				}
				if (flag == 0)
				{
					hei = 0;
					continue;
				}

				if (judge_move(t, false, start_x2, start_y2, target_x2, target_y2))
				{
					int x = board1[target_x2][target_y2];
					qipu_generate(false, start_x2, start_y2, target_x2, target_y2);
					updatewithoutin(start_x2, start_y2, target_x2, target_y2);//参数未传，重新绘图的函数
					sound_play(false, target_x2, target_y2,x);
					memcpy(pre_hong, board1, sizeof(board1));
					break;
				}
				else
				{
					hei = 0;//重新选子，因为无法移动到目标位置
				}
			}

		}
	}
	if (back_flag == 1)return true;

	return false;
}


void updatewithoutin(int stx, int sty, int tarx, int tary)//move后开始redraw
{
	//说明可以走，在之前的基础上绘图
	//先将board变化，遍历棋盘，对应的位置进行loadimage,可以先cleardevice，然后重新画

	int t = board1[stx][sty];

	board1[stx][sty] = 0;//置零

	board1[tarx][tary] = t;
	//先重画棋盘，再画棋子

	clearrectangle(0, 0, 500, 640);
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "D://qp.png", 500, 640);


	putimage(0, 0, &img);

	
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (board1[i][j] == 0)
			{
				continue;
			}
			else
			{
				redraw(board1[i][j], i, j);
				
			}
			
		}
	}
	FlushBatchDraw();


}
void redraw(int t, int i, int j)
{
	//判断画哪种棋子  从1到7(包括负数)
	IMAGE img;
	
	if (t > 0)
	{
		if (t == 1)
		{
			loadimage(&img, "D://1.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (t == 2)
		{
			loadimage(&img, "D://2.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (t == 3)
		{
			loadimage(&img, "D://3.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (t == 4)
		{
			loadimage(&img, "D://4.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (t == 5)
		{
			loadimage(&img, "D://5.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (t == 6)
		{
			loadimage(&img, "D://6.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else
		{
			loadimage(&img, "D://7.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}


	}
	else
	{
		if (abs(t) == 1)
		{
			loadimage(&img, "D://11.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (abs(t) == 2)
		{
			loadimage(&img, "D://12.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (abs(t) == 3)
		{
			loadimage(&img, "D://13.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (abs(t) == 4)
		{
			loadimage(&img, "D://14.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (abs(t) == 5)
		{
			loadimage(&img, "D://15.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else if (abs(t) == 6)
		{
			loadimage(&img, "D://16.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}
		else
		{
			loadimage(&img, "D://17.png", 50, 50);
			drawAlpha(&img, x_val[j], y_val[i]);
			return;
		}

	}

}

void qipu_generate(bool who, int stx, int sty, int tarx, int tary)//放在updatewithin中//合法走位之后再写
{
	//字符串加减操作

	string s_1[] = { "","车","马","相","仕","帅","炮","兵" };
	string s_2[] = { "","车","马","象","士","将","炮","卒" };

	string qh[] = { "","进","平","退" };
	string sz_1[] = { "","一","二","三","四","五","六","七","八","九" };
	string sz_2[] = { "","1","2","3","4","5","6","7","8","9" };

	//面对自己的一方从左到右是1-9
	int len = 10;
	if (who == 1)
	{
		bushu++;
		int lc;
		if (stx < tarx)
		{
			lc = 1;
		}
		else if (stx == tarx)
		{
			lc = 2;
		}
		else lc = 3;

		int t = board1[stx][sty];
		if (lc == 1)
		{
			if (tary != sty)
			{
				string s = s_1[t] + sz_1[10 - sty] + qh[lc] + sz_1[10 - tary];
				output(s, who);
			}
			else
			{
				string s = s_1[t] + sz_1[10 - sty] + qh[lc] + sz_1[abs(tarx - stx)];
				output(s, who);
			}
		}
		else if (lc == 2)
		{
			string s = s_1[t] + sz_1[10 - sty] + qh[lc] + sz_1[10 - tary];
			output(s, who);
		}
		else
		{
			if (tary != sty)
			{
				string s = s_1[t] + sz_1[10 - sty] + qh[lc] + sz_1[10 - tary];
				output(s, who);
			}
			else
			{
				string s = s_1[t] + sz_1[10 - sty] + qh[lc] + sz_1[abs(tarx - stx)];
				output(s, who);
			}
		}
	}
	else
	{
		bushu++;

		int lc;
		if (stx > tarx)
		{
			lc = 1;
		}
		else if (stx == tarx)
		{
			lc = 2;
		}
		else lc = 3;
		int t = abs(board1[stx][sty]);

		if (lc == 1)
		{
			if (sty != tary)
			{
				string s = s_2[t] + sz_2[sty] + qh[lc] + sz_2[tary];
				output(s, who);
			}
			else
			{
				string s = s_2[t] + sz_2[sty] + qh[lc] + sz_2[abs(stx - tarx)];
				output(s, who);
			}
		}
		else if (lc == 2)
		{
			string s = s_2[t] + sz_2[sty] + qh[lc] + sz_2[tary];
			output(s, who);
		}
		else
		{
			if (sty != tary)
			{
				string s = s_2[t] + sz_2[sty] + qh[lc] + sz_2[tary];
				output(s, who);
			}
			else
			{
				string s = s_2[t] + sz_2[sty] + qh[lc] + sz_2[abs(stx - tarx)];
				output(s, who);
			}
		}
		huihe_count++;
	}




}

void huiqi()//点击悔棋按钮生效
{
	//复制吃子前的二维数组(保存状态） 重新画棋子即可
	//恢复状态 绘图片
	memcpy(board1, hq, sizeof(hq));
	clearrectangle(0, 0, 500, 640);
	IMAGE img;
	loadimage(&img, "D://qp.png", 500, 640);
	putimage(0, 0, &img);
	BeginBatchDraw();
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (board1[i][j] == 0)
			{
				continue;
			}
			else
			{
				redraw(board1[i][j], i, j);
				
			}FlushBatchDraw();
		}
	}
	EndBatchDraw();



}


void sound_play(bool who,int tarx,int tary,int t)
{

	if (who==1&&sound2)
	{
		if (judge_jiangjun(true))
		{
			mciSendString("close jjmusic", NULL, 0, NULL);
			mciSendString("open D://jiangjun.MP3 alias jjmusic", NULL, 0, NULL);
			mciSendString("play jjmusic ", NULL, 0, NULL);
			return;
			
		}



		 if (t < 0)
		{
			mciSendString("close  cz2music ", NULL, 0, NULL);//先关闭之前播放的本音乐
			mciSendString("open D://cz2.MP3 alias cz2music", NULL, 0, NULL);
			mciSendString("play cz2music ", NULL, 0, NULL);
		}
		else
		{ 
			if (sound2)
			{
				mciSendString("close lz2music", NULL, 0, NULL);
				mciSendString("open D://lz2.MP3 alias lz2music", NULL, 0, NULL);
				mciSendString("play lz2music", NULL, 0, NULL);
			}
		}
	}
	if (who == 0 )
	{
		if (judge_jiangjun(false))
		{
			mciSendString("close jjmusic", NULL, 0, NULL);
			mciSendString("open D://jiangjun.MP3 alias jjmusic", NULL, 0, NULL);
			mciSendString("play jjmusic ", NULL, 0, NULL);
			return;

		}
		if (t > 0)//未写完，若吃子和将军同时，应先将军
		{
			mciSendString("close  cz2music ", NULL, 0, NULL);//先关闭之前播放的本音乐
			mciSendString("open D://cz2.MP3 alias cz2music", NULL, 0, NULL);
			mciSendString("play cz2music ", NULL, 0, NULL);
		}
		else
		{
			if (sound2)
			{
				mciSendString("close lz2music", NULL, 0, NULL);
				mciSendString("open D://lz2.MP3 alias lz2music", NULL, 0, NULL);
				mciSendString("play lz2music", NULL, 0, NULL);
			}
			
		}
	}
}


bool judge_jiangjun(bool st)//先写个逻辑 后面优化代码
{
	//判断红方将黑方
	bool find_flag = 0;
	int lc_x = 0, lc_y = 0;
	
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << board1[i][j];
		}
		cout << endl;
	}
		


	if (st == true) {

		
		for (int i = 8; i <= 10; i++)
		{
			for (int j = 4; j <= 6; j++)
			{
				if (board1[i][j] == -5) {
					lc_x = i;
					lc_y = j;
					find_flag = true;
					break;
					
				}
			}
			if (find_flag)break;
		}
		cout << lc_x << ' ' << lc_y << endl;
		for (int i = 1; i <= 10; i++)//搜索该列
		{
			if (board1[i][lc_y] == 1)
			{
				if (judge_ju(true, i, lc_y, lc_x, lc_y))
				{
					return true;
				}

			}
		}
		
		for (int i = 1; i <= 9; i++)//搜索该行
		{
			if (board1[lc_x][i] == 1)
			{
				if (judge_ju(true, lc_x, i, lc_x, lc_y))
				{
					return true;
				}

			}
		}

		
		for (int i = 6; i <= 10; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				if (board1[i][j] == 2)
				{
					if (judge_ma(true, i, j, lc_x, lc_y))
					{
						return true;
					}
				}
			}
		}
		
		for (int i = 1; i <= 10; i++)//搜索该列
		{
			if (board1[i][lc_y] == 6)
			{
				
				if (judge_pao(true, i, lc_y, lc_x, lc_y))
				{
					
					return true;
				}

			}
		}

		
		for (int i = 1; i <= 9; i++)
		{
			
			if (board1[lc_x][i] == 6)
			{
				
				if (judge_pao(true, i, lc_y, lc_x, lc_y))
				{
					
					return true;
				}
			}
		}

		
		for (int i = 7; i <= 10; i++)
		{
			for (int j = 3; j <= 7; j++)
			{
				if (board1[i][j] == 7)
				{
					if (judge_bing(true, i, j, lc_x, lc_y))
					{
						return true;
					}
				}
			}
		}

		return false;
	}
	else//判断黑将红
	{
		
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 4; j <= 6; j++)
			{
				if (board1[i][j] == 5) {
					lc_x = i;
					lc_y = j;
					find_flag = true;
					break;

				}
			}
			if (find_flag)break;
		}
		for (int i = 1; i <= 10; i++)//搜索该列
		{
			if (board1[i][lc_y] == -1)
			{
				if (judge_ju(false, i, lc_y, lc_x, lc_y))
				{
					return true;
				}

			}
		}

		for (int i = 1; i <= 9; i++)//搜索该列
		{
			if (board1[lc_x][i] == -1)
			{
				if (judge_ju(false, lc_x, i, lc_x, lc_y))
				{
					return true;
				}

			}
		}


		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				if (board1[i][j] == -2)
				{
					if (judge_ma(false, i, j, lc_x, lc_y))
					{
						return true;
					}
				}
			}
		}

		for (int i = 1; i <= 10; i++)//搜索该列
		{
			if (board1[i][lc_y] == -6)
			{
				if (judge_pao(false, i, lc_y, lc_x, lc_y))
				{
					return true;
				}

			}
		}

		for (int i = 1; i <=4 ; i++)
		{
			for (int j = 3; j <= 7; j++)
			{
				if (board1[i][j] == -7)
				{
					if (judge_bing(false, i, j, lc_x, lc_y))
					{
						return true;
					}
				}
			}
		}
		return false;


	}
	return false;
}

void output(string t, bool who)
{
	
	int row, line;
	if (who == 1)
	{
		row = ((bushu - 1) % 2) * 100;
		line = (huihe_count - 1) * 30;
	}
	else
	{
		row = (bushu - 1) % 2 * 120;
		line = (huihe_count - 1) * 30;
	}
	int len = t.size() + 1;
	char* text = new char[len];
	strcpy_s(text, len, t.c_str());
	cout << text << endl;
	int width = 200, height = 60;
	settextstyle(25, 0, "楷体");//字体未选
	setbkmode(TRANSPARENT);

	settextcolor(BLUE);
	outtextxy(500 + row, line, text);

}

// 检查鼠标是否在按钮上方
bool checkMouseOver(int x,int y,Button t)
{
	
	bool isMouseOver = (x >= t.x && x <= t.x + t.width && y >= t.y && y <= t.y + t.height);

	if (isMouseOver) {
		t.scale = 0.8; // 鼠标悬停时缩放按钮
		setlinecolor(RGB(0, 120, 215)); // 鼠标悬停时按钮边框颜色
		setfillcolor(RGB(229, 241, 251)); // 鼠标悬停时按钮填充颜色
		return true;
	}
	else {
		t.scale = 1.0; // 恢复按钮原始大小
		setlinecolor(RGB(173, 173, 173)); // 按钮边框颜色
		setfillcolor(RGB(225, 225, 225)); // 按钮填充颜色
		return false;
	}
}

void drawButton(Button t) {

	settextcolor(BLACK);
	
	fillrectangle(t.x+t.width*(1-t.scale), t.y+t.width*(1-t.scale), t.x + t.width*t.scale, t.y + t.height*t.scale);
	settextstyle(25, 0, _T("楷体"));//字体未选
	setbkmode(TRANSPARENT);
	outtextxy(t.x + t.width / 2 - textwidth(_T(t.text)) / 2, t.y + t.height / 2 - textheight(_T(t.text)) / 2, _T(t.text));
}
void drawtext(string t, Button b)//输出文本(未完成）
{
	settextcolor(BLACK);
	settextstyle(25, 0, _T("楷体"));//字体未选
	setbkmode(TRANSPARENT);
	//矩形的位置自己定，且不画出来 //与按钮一个高度
	int len = t.size() + 1;
	char* text = new char[len];
	strcpy_s(text, len, t.c_str());
	outtextxy(200, b.y + b.height / 2 - textheight(text) / 2, text);
}

bool check(int x, int y,Button t)//检测按钮是否在区域内
{
	if (x <=t.x+t.width && x >=t.x&& y >=t.y && y <=t.y+t.height)return true;
	return false;
}
void showmenu()
{
	IMAGE img;
	loadimage(&img, "D://bg.png", 700, 700);
	putimage(0, 0, &img);
	
	
	menu[0] = {275,275,150,50,1,false,"双人游戏",false};
	menu[1] = {275,375,150,50,1,false,"人机对战",false};
	menu[2] = {275,475,150,50,1,false,"设置",false};
	menu[3] = {275,575,150,50,1,false,"制作人员名单",false};

	for (auto t : menu)
	{
		drawButton(t);
	}
	
}

void bgm_play()//背景音乐播放
{
	mciSendString("open D://bgm.MP3 alias bgmusic", NULL, 0, NULL);//bkmusic是自己定义的别名
	mciSendString("play bgmusic repeat", NULL, 0, NULL);
}

void bgm_close()//关闭背景音乐
{
	mciSendString("close  bgmusic ", NULL, 0, NULL);//先关闭之前播放的本音乐

}
//设置页面
void show_setting()
{
	cleardevice();
	IMAGE img;
	loadimage(&img, "D://880.jpg", 700, 700);
	putimage(0, 0, &img);


	volume_control[0] = { 350,275,150,50,1,false,"开",false };
	volume_control[1] = { 350,375,150,50,1,false,"开",false };
	volume_control[2] = { 50,50,150,50,1,false,"返回",false };


	drawtext("背景音乐:", volume_control[0]);
	drawtext("走子音效:", volume_control[1]);

	for (auto t : volume_control)
	{
		drawButton(t);
	}
	

	MOUSEMSG m;

	while (1)//点击事件判断
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		int wzx = m.x, wzy = m.y;
		BeginBatchDraw();
		for (auto t : volume_control)
		{
			checkMouseOver(wzx, wzy, t);
			drawButton(t);
			FlushBatchDraw();
		}
		EndBatchDraw();
		
		if (m.uMsg == WM_LBUTTONDOWN)//点击事件 在game中也可以用，点击返回直接break;
		{
			int x_ = m.x;
			int y_ = m.y;
			if (check(x_, y_, volume_control[0]))
			{
				volume_control[0].isclick = (!volume_control[0].isclick);
				if (volume_control[0].isclick == false)
				{
					char p[] = "开";
					strcpy(volume_control[0].text, p);
					drawButton(volume_control[0]);
					bgm_play();
				}
				else
				{
					char p[] = "关";
					strcpy(volume_control[0].text, p);
					drawButton(volume_control[0]);
					bgm_close();
				}

			}
			if (check(x_, y_, volume_control[1]))
			{
				volume_control[1].isclick = (!volume_control[1].isclick);
				if (volume_control[1].isclick == false)
				{
					char p[] = "开";
					strcpy(volume_control[1].text, p);
					drawButton(volume_control[1]);
					sound2 = true;
				}
				else
				{
					char p[] = "关";
					strcpy(volume_control[1].text, p);
					drawButton(volume_control[1]);
					sound2 = false;
				
				}
			}
			if (check(x_, y_, volume_control[2]))
			{


				cleardevice();
				break;
			}
		}




	}
	showmenu();


}

void show_list()
{
	cleardevice();
	IMAGE img;
	loadimage(&img, "D://880.jpg", 700, 700);
	putimage(0, 0, &img);

	Button t = { 50,50,150,50,1,false,"返回",false };

	

	
	settextstyle(35, 0, "楷体");//字体未选
	setbkmode(TRANSPARENT);

	settextcolor(BLACK);
	outtextxy(150,350,"袁明宇");
	outtextxy(300,350,"赵靖齐");
	outtextxy(450,350,"张静怡");




	MOUSEMSG m;

	while (1)//点击事件判断
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		int wzx = m.x, wzy = m.y;
		

			checkMouseOver(wzx, wzy, t);
			drawButton(t);
			FlushBatchDraw();
		EndBatchDraw();

		if (m.uMsg == WM_LBUTTONDOWN)//点击事件 在game中也可以用，点击返回直接break;
		{
			int x_ = m.x;
			int y_ = m.y;
		
			if (check(x_, y_, t))
			{

				cleardevice();
				break;
			}
		}




	}
	showmenu();



}
//游戏主体
void real_game()
{
	MOUSEMSG m;
	m = GetMouseMsg();
	int wzx = m.x, wzy = m.y;
	BeginBatchDraw();
	for (auto t : menu)
	{
		checkMouseOver(wzx, wzy, t);
		drawButton(t);
		FlushBatchDraw();
	
	}
	EndBatchDraw();//等会改成showmenu()


	if (m.uMsg == WM_LBUTTONDOWN)//点击事件 在game中也可以用，点击返回直接break;
	{
		int x_ = m.x;
		int y_ = m.y;
		if (check(x_, y_, menu[0]))
		{
			setbkcolor(RGB(231, 201, 150));
			cleardevice();
			IMAGE img;
			loadimage(&img, "D://qp.png", 500, 640);
			setlinecolor(RGB(231, 201, 150));
			

			putimage(0, 0, &img);

			startup(red, black);
			while (1)
			{
				int r = game();
				if (r)
				{
					cleardevice();
					break;
				}

			}
			showmenu();


			//game页面再写几个按钮
		}
		if (check(x_, y_, menu[1]))//人机对战界面
		{
			setbkcolor(RGB(231, 201, 150));
			cleardevice();
			IMAGE img;	
			loadimage(&img, "D://qp.png", 500, 640);
			putimage(0, 0, &img);

			startup(red, black);
			while (1)
			{
				int r = AI_play();
				if (r)
				{
					cleardevice();
					break;
				}

			}
			showmenu();
		}
		if (check(x_, y_, menu[2]))//设置界面
		{
			
			show_setting();

		}
		if (check(x_, y_, menu[3]))//制作人员名单
		{
			show_list();
		}
	}
}

int caculate_point(int startx, int starty, int tarx, int tary)//算得到的分数和对方得到的分数差，红方
{
	int hei_point = 0;
	
	if (board1[tarx][tary] > 0)
	{
		int t = board1[tarx][tary];
		for (int i = 1; i <= 7; i++)
		{
			if (t == i)hei_point += basic_value[i];//加上对应的子的分数
		}
	}
	
	memcpy(now, board1, sizeof(board1));
	int t = now[startx][starty];

	now[startx][starty] = 0;
	now[tarx][tary] = t;
	
	if (t == -1)
	{
		hei_point += hei_juposition[tarx][tary] - hei_juposition[startx][starty];

	}
	else if(t==-2)
	{
		hei_point += hei_maposition[tarx][tary] - hei_maposition[startx][starty];
	}
	else if (t == -3)
	{
		hei_point += hei_xiangposition[tarx][tary] - hei_xiangposition[startx][starty];
	}
	else if (t == -4)
	{
		hei_point += hei_shiposition[tarx][tary] - hei_shiposition[startx][starty];
	}
	else if(t==-5)
	{
		hei_point += hei_shiposition[tarx][tary] - hei_shiposition[startx][starty];
	}
	else if (t == -6)
	{
		hei_point += hei_juposition[tarx][tary] - hei_juposition[startx][starty];
	}
	else if (t == -7)
	{
		hei_point += hei_bingposition[tarx][tary] - hei_bingposition[startx][starty];
	}
	
	int max_hong = -0x3f3f3f3f;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 9; j++)
		{
			//找到红棋判断合法走位
			if (now[i][j] > 0)
			{
				int t = now[i][j];
				//枚举所有走法
				for (int l = 1; l <= 10; l++)//枚举该列所有//找到红的最佳走位
				{
					for (int r = 1; r <= 9; r++)
					{
						if (t == 1 && judge_ju(1, i, j, l, r))
						{
							int p = caculate_hong(i, j, l, r);
							if (p > max_hong)
							{
								max_hong = p;
							}
						}
						else if (t == 2 && judge_ma(1, i, j, l, r))
						{
							int p = caculate_hong(i, j, l, r);
							if (p > max_hong)
							{
								max_hong = p;
							}
						}
						else if (t == 3 && judge_xiang(1, i, j, l, r))
						{
							int p = caculate_hong(i, j, l, r);
							if (p > max_hong)
							{
								max_hong = p;
							}

						}
						else if (t == 4 && judge_shi(1, i, j, l, r))
						{
							int p = caculate_hong(i, j, l, r);
							if (p > max_hong)
							{
								max_hong = p;
							}
						}
						else if (t == 5 && judge_shuai(1, i, j, l, r))
						{
							int p = caculate_hong(i, j, l, r);
							if (p > max_hong)
							{
								max_hong = p;
							}
						}
						else if (t == 6 && judge_pao(1, i, j, l, r))
						{
							int p = caculate_hong(i, j, l, r);
							if (p > max_hong)
							{
								max_hong = p;
							}
						}
						else if (t == 7 && judge_bing(1, i, j, l, r))
						{
							int p = caculate_hong(i, j, l, r);
							if (p > max_hong)
							{
								max_hong = p;
							}
						}




					}
				}


			}

		}
	return (hei_point - max_hong);



}

int caculate_hong(int startx, int starty, int tarx, int tary)
{
	
	int hong_point = 0;
	if (now[tarx][tary] <0)
	{
		int t = now[tarx][tary];
		for (int i = 1; i <= 7; i++)
		{
			if (abs(t) == i)hong_point += basic_value[i];//加上对应的子的分数
		}
	}
	

	int t = now[startx][starty];
	if (t == 1)
	{
		hong_point += hong_juposition[tarx][tary] - hong_juposition[startx][starty];

	}
	else if (t == 2)
	{
		hong_point += hong_maposition[tarx][tary] - hong_maposition[startx][starty];
	}
	else if (t == 3)
	{
		hong_point += hong_xiangposition[tarx][tary] - hong_xiangposition[startx][starty];
	}
	else if (t == 4)
	{
		hong_point += hong_shiposition[tarx][tary] - hong_shiposition[startx][starty];
	}
	else if (t == 5)
	{
		hong_point += hong_shiposition[tarx][tary] - hong_shiposition[startx][starty];
	}
	else if (t == 6)
	{
		hong_point += hong_juposition[tarx][tary] - hong_juposition[startx][starty];
	}
	else if (t == 7)
	{
		hong_point += hong_bingposition[tarx][tary] - hong_bingposition[startx][starty];
	}
	return hong_point;
}



bool AI_play()
{
	button_control[0] = { 30,660,120,25,1,false,"返回",false };
	button_control[1] = { 180,660,120,25,1,false,"悔棋",false };
	button_control[2] = { 330,660,120,25,1,false,"重来",false };
	for (auto t : button_control)
	{
		drawButton(t);

	}

	MOUSEMSG m;
	//红方先走
	bool hong = 0, hei = 0;
	int start_x1, start_y1, start_x2, start_y2;
	int target_x1, target_y1, target_x2, target_y2;

	bool back_flag = 0;

	//判断红方选择棋子并下棋
	while (1)
	{
		m = GetMouseMsg();

		int wzx = m.x, wzy = m.y;
		BeginBatchDraw();
		for (auto t : button_control)
		{
			checkMouseOver(wzx, wzy, t);
			drawButton(t);
			FlushBatchDraw();
		}
		EndBatchDraw();


		if (m.uMsg == WM_LBUTTONDOWN)//先选中(判定是否选择自己的棋子）
		{

			int x_ = m.x;
			int y_ = m.y;
			//判断三个按钮是否按下
			if (check(x_, y_, button_control[0]))//返回
			{
				cleardevice();
				back_flag = 1;
				memcpy(board1, backup, sizeof(backup));
				huihe_count = 1;
				bushu = 0;
				break;

			}
			if (check(x_, y_, button_control[1]) && bushu != 0)//减掉步数
			{
				bushu--;
				memcpy(board1, pre_hei, sizeof(pre_hei));
				clearrectangle(0, 0, 500, 640);
				IMAGE img;
				loadimage(&img, "D://qp.png", 500, 640);
				putimage(0, 0, &img);
				BeginBatchDraw();
				for (int i = 1; i <= 10; i++)
				{
					for (int j = 1; j <= 9; j++)
					{
						if (board1[i][j] == 0)
						{
							continue;
						}
						else
						{
							redraw(board1[i][j], i, j);

						}FlushBatchDraw();

					}

				}
				EndBatchDraw();
				hei = 0, hong = 0;
				break;
			}


			if (check(x_, y_, button_control[2]))//重来
			{
				huihe_count = 1;
				bushu = 0;
				memcpy(board1, backup, sizeof(backup));
				clearrectangle(0, 0, 500, 640);
				IMAGE img;
				loadimage(&img, "D://qp.png", 500, 640);
				putimage(0, 0, &img);
				BeginBatchDraw();
				for (int i = 1; i <= 10; i++)
				{
					for (int j = 1; j <= 9; j++)
					{
						if (board1[i][j] == 0)
						{
							continue;
						}
						else
						{
							redraw(board1[i][j], i, j);

						}FlushBatchDraw();

					}

				}
				EndBatchDraw();
				hong = 0, hei = 0;
				continue;

			}


			if (hong == 0)//未被选中，开始选择红
			{
				for (int i = 1; i <= 10; i++)//先遍历act数组
				{
					for (int j = 1; j <= 9; j++)
					{

						if (abs(dot[i][j].x - y_) <= 20 && abs(dot[i][j].y - x_) <= 20 && board1[i][j] > 0)
						{

							start_x1 = i, start_y1 = j;
							hong = 1;

							break;
						}
					}
					if (hong == 1)break;
				}
			}
			else if (hong == 1)
			{

				int t = board1[start_x1][start_y1];//先这么写，后面棋盘翻转时直接对board赋值即可


				bool flag = 0;
				for (int i = 1; i <= 10; i++)//先遍历act数组
				{
					for (int j = 1; j <= 9; j++)
					{
						if (abs(dot[i][j].x - y_) <= 20 && abs(dot[i][j].y - x_) <= 20)
						{

							target_x1 = i, target_y1 = j;
							flag = 1;
							break;
						}

					}
					if (flag)break;
				}


				if (flag == 0)
				{
					hong = 0;
					continue;
				}

				if (judge_move(t, true, start_x1, start_y1, target_x1, target_y1))
				{
					int x = board1[target_x1][target_y1];

					
					qipu_generate(true, start_x1, start_y1, target_x1, target_y1);
					updatewithoutin(start_x1, start_y1, target_x1, target_y1);
					sound_play(true, target_x1, target_y1,x);//参数未传，重新绘图的函数
					memcpy(pre_hei, board1, sizeof(board1));
					for (int i = 1; i <= 10; i++) {
						for (int j = 1; j <= 9; j++)
						{
							cout << pre_hei[i][j] << ' ';
						}
						cout << endl;
					}
					break;


				}
				else
				{
					hong = 0;//重新选子，因为无法移动到目标位置

				}

			}

		}
	}
	if (back_flag == 1)return true;// 返回按钮判定
	//判断黑方选择棋子并下棋  在judge中判定是哪种走子
	//AI走棋(黑方）
	//枚举黑方合法的走位
	
	int max_score = -0x3f3f3f3f;
	for(int i=1;i<=10;i++)
		for (int j = 1; j <= 9; j++)
		{
			//找到黑棋判断合法走位
			if (board1[i][j] < 0)
			{
				int t = board1[i][j];
					//枚举所有走法
					for (int l = 1; l <= 10;l++)//枚举该列所有
					{
						for (int r = 1; r <= 9; r++)
						{
							if (t == -1 && judge_ju(0, i, j, l, r))
							{
								auto p = caculate_point(i, j, l, r);
								if (p > max_score)
								{
									max_score = p;
									start_x2 = i, start_y2 = j, target_x2 = l, target_y2 = r;
								}
							}
							else if (t == -2 && judge_ma(0, i, j, l, r))
							{
								auto p = caculate_point(i, j, l, r);
								if (p > max_score)
								{
									max_score = p;
									start_x2 = i, start_y2 = j, target_x2 = l, target_y2 = r;
								}
							}
							else if(t==-3&&judge_xiang(0,i,j,l,r))
							{
								auto p = caculate_point(i, j, l, r);
								if (p > max_score)
								{
									max_score = p;
									start_x2 = i, start_y2 = j, target_x2 = l, target_y2 = r;
								}

							}
							else if (t == -4 && judge_shi(0, i, j, l, r))
							{
								auto p = caculate_point(i, j, l, r);
								if (p > max_score)
								{
									max_score = p;
									start_x2 = i, start_y2 = j, target_x2 = l, target_y2 = r;
								}
							}
							else if (t == -5 && judge_shuai(0, i, j, l, r))
							{
								auto p = caculate_point(i, j, l, r);
								if (p > max_score)
								{
									max_score = p;
									start_x2 = i, start_y2 = j, target_x2 = l, target_y2 = r;
								}
							}
							else if (t == -6 && judge_pao(0,i, j, l, r))
							{	
								auto p = caculate_point(i, j, l, r);
								if (p > max_score)
								{
									max_score = p;
									start_x2 = i, start_y2 = j, target_x2 = l, target_y2 = r;
								}
							}
							else if (t == -7 && judge_bing(0, i, j, l, r))
							{
								auto p = caculate_point(i, j, l, r);
								if (p > max_score)
								{
									max_score = p;
									start_x2 = i, start_y2 = j, target_x2 = l, target_y2 = r;
								}
							}
						}
					}
			
				
			}
		}
	int x = board1[target_x2][target_y2];
	cout << x << "q" << endl;
	qipu_generate(false, start_x2, start_y2, target_x2, target_y2);
	updatewithoutin(start_x2, start_y2, target_x2, target_y2);//参数未传，重新绘图的函数
	sound_play(false, target_x2, target_y2,x);

	return false;


}




int main()
{
	//点位生成

	dot[1][1] = { 34,40 };//x,y x是行 y是列
	int w1 = dot[1][1].x;
	int h1 = dot[1][1].y;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 9; j++)
		{
			dot[i][j] = { w1 + (i - 1) * height_ ,h1 + (j - 1) * width_ };//实际点位

		}
	memcpy(pre_hei, board1, sizeof(board1));
	memcpy(pre_hong, board1, sizeof(board1));
	//mciSendString("close  bkmusic ", NULL, 0, NULL);//先关闭之前播放的本音乐	
	initgraph(700, 700);
	bgm_play();
	showmenu();
	while (1)
	{
		real_game();
	}
	_getch();

	return 0;
}

/*setbkcolor(RGB(231, 201, 150));
	cleardevice();*/
