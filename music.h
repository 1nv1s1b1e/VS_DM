//#include <graphics.h>
//#include <mmsystem.h>
//#include<bits/stdc++.h>
//#include<conio.h>
//#pragma comment(lib, "winmm.lib") 
//
//void drawButton(int x, int y, int width, int height, const char* text) {
//    setcolor(LIGHTGRAY);
//    rectangle(x, y, x + width, y + height); 
//    setfillcolor(LIGHTGRAY);
//    fillrectangle(x, y, x + width, y + height); 
//    settextstyle(20, 0, _T(""));
//    outtextxy(x + width / 2 - textwidth(_T(text)) / 2, y + height / 2 - textheight(_T(text)) / 2, _T(text));  
//}
//
//int main() {
//    initgraph(400, 300); 
//
//    int buttonX = 150;
//    int buttonY = 100;
//    int buttonWidth = 100;
//    int buttonHeight = 40;
//
//    drawButton(buttonX, buttonY, buttonWidth, buttonHeight, "Play Music");
//
//    while (true) {
//        
//        if (ismouseclick(WM_LBUTTONDOWN)) {
//            int mouseX = getmousex();
//            int mouseY = getmousey();
//
//           
//            if (mouseX >= buttonX && mouseX <= buttonX + buttonWidth &&
//                mouseY >= buttonY && mouseY <= buttonY + buttonHeight) {
//                clearmouseclick(WM_LBUTTONDOWN);  
//
//               
//                PlaySound(_T(""), NULL, SND_FILENAME | SND_ASYNC);
//            }
//        }
//
//        delay_ms(100); 
//
//    closegraph();  
//    return 0;
//}
