//#include <graphics.h>
//
//void drawButton(int x, int y, int width, int height, const char* text) {
//    setcolor(LIGHTGRAY);
//    rectangle(x, y, x + width, y + height);  
//    setfillcolor(LIGHTGRAY);
//    fillrectangle(x, y, x + width, y + height);  
//    settextstyle(20, 0, _T(""));//����δѡ
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
//    drawButton(buttonX, buttonY, buttonWidth, buttonHeight, "Click Me");
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
//                MessageBox(GetHWnd(), _T("Button Clicked!"), _T("Message"), MB_OK);
//            }
//        }
//
//        delay_ms(100);  
//    }
//
//    closegraph();
//    return 0;
//}
