//class Button
//{
//private:
//	int x; // ��ť���Ͻ�x����
//	int y; // ��ť���Ͻ�y����
//	int width; // ��ť���
//	int height; // ��ť�߶�
//	float scale; // ���ű���������ʵ�������ͣЧ��
//	bool isMouseOver; // ��ʾ����Ƿ��ڰ�ť�Ϸ�
//	wstring text; // ��ť�ı�
//	function<void()> onClick; // �����ť�����ĺ���
//
//public:
//
//	Button(int x, int y, int width, int height, const wstring& text, const function<void()>& onClick)
//		: x(x), y(y), width(width), height(height), text(text), onClick(onClick), scale(1.0f), isMouseOver(false)
//	{
//	}
//
//	// �������Ƿ��ڰ�ť�Ϸ�
//	void checkMouseOver(int mouseX, int mouseY)
//	{
//		isMouseOver = (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
//
//		if (isMouseOver) {
//			scale = 0.9f; // �����ͣʱ���Ű�ť
//		}
//		else {
//			scale = 1.0f; // �ָ���ťԭʼ��С
//		}
//	}
//
//	// ���������Ƿ��ڰ�ť�ڣ���ִ�к���
//	bool checkClick(int mouseX, int mouseY)
//	{
//		if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
//		{
//			onClick(); // ִ�а�ť���ʱ�ĺ���
//			isMouseOver = false;
//			scale = 1.0f;
//			return true;
//		}
//		return false;
//	}
//
//	// ���ư�ť
//	void draw()
//	{
//		int scaledWidth = width * scale; // ���ź�İ�ť���
//		int scaledHeight = height * scale; // ���ź�İ�ť�߶�
//		int scaledX = x + (width - scaledWidth) / 2; // ���ź�İ�ťx����
//		int scaledY = y + (height - scaledHeight) / 2; // ���ź�İ�ťy����
//
//		if (isMouseOver)
//		{
//			setlinecolor(RGB(0, 120, 215)); // �����ͣʱ��ť�߿���ɫ
//			setfillcolor(RGB(229, 241, 251)); // �����ͣʱ��ť�����ɫ
//
//		}
//		else
//		{
//			setlinecolor(RGB(173, 173, 173)); // ��ť�߿���ɫ
//			setfillcolor(RGB(225, 225, 225)); // ��ť�����ɫ
//		}
//
//		fillrectangle(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight); // ���ư�ť
//		settextcolor(BLACK); // �����ı���ɫΪ��ɫ
//		setbkmode(TRANSPARENT); // �����ı�����͸��
//		settextstyle(20 * scale, 0, _T("΢���ź�")); // �����ı���С������
//		//������ʾ��ť�ı�
//		int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2; // �����ı��ڰ�ť�����x����
//		int textY = scaledY + (scaledHeight - textheight(_T("΢���ź�"))) / 2; // �����ı��ڰ�ť�����y����
//		outtextxy(textX, textY, text.c_str()); // �ڰ�ť�ϻ����ı�
//	}
//};




//��















// ���������Ƿ��ڰ�ť�ڣ���ִ�к���
//bool checkClick(int x, int y, int width, int height, int scale, bool isMouseOver, string text,int mouseX,int mouseY)
//{
//	if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
//	{
//		// ִ�а�ť���ʱ�ĺ���
//		isMouseOver = false;
//		scale = 1.0f;
//		return true;
//	}
//	return false;
//}



// ���ư�ť
//void draw(int x,int y,int width,int height,int scale,bool isMouseOver,string t)
//{
//	int scaledWidth = width * scale; // ���ź�İ�ť���
//	int scaledHeight = height * scale; // ���ź�İ�ť�߶�
//	int scaledX = x + (width - scaledWidth) / 2; // ���ź�İ�ťx����
//	int scaledY = y + (height - scaledHeight) / 2; // ���ź�İ�ťy����
//
//	if (isMouseOver)
//	{
//		setlinecolor(RGB(0, 120, 215)); // �����ͣʱ��ť�߿���ɫ
//		setfillcolor(RGB(229, 241, 251)); // �����ͣʱ��ť�����ɫ
//
//	}
//	else
//	{
//		setlinecolor(RGB(173, 173, 173)); // ��ť�߿���ɫ
//		setfillcolor(RGB(225, 225, 225)); // ��ť�����ɫ
//	}
//	int len = t.size() + 1;
//	char* text = new char[len];
//	strcpy_s(text, len, t.c_str());
//
//	fillrectangle(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight); // ���ư�ť
//	settextcolor(BLACK); // �����ı���ɫΪ��ɫ
//	setbkmode(TRANSPARENT); // �����ı�����͸��
//	settextstyle(20 * scale, 0, _T("΢���ź�")); // �����ı���С������
//	//������ʾ��ť�ı�
//	int textX = scaledX + (scaledWidth - textwidth(text) / 2); // �����ı��ڰ�ť�����x����
//	int textY = scaledY + (scaledHeight - textheight(text)) / 2; // �����ı��ڰ�ť�����y����
//	outtextxy(textX, textY, text); // �ڰ�ť�ϻ����ı�
//}
