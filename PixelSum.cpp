// PixelSum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int min(int a, int b);

class Pixel {
	int R;
	int G;
	int B;
	int W;
public:
	Pixel(int r, int g, int b) {
		if (0 <= r && r<= 255) { R = r; }else R = 255;
		if (0 <= g && g<= 255) { G = g; }else G = 255;
		if (0 <= b && b<= 255) { B = b; }else B = 255;
		W = 0;
	}
	Pixel() { R = 0; G = 0; B = 0; W = 0; }
	~Pixel() {}
	void show() {
		std::cout << "R=" << R << " G=" << G << " B=" << B << std::endl;
	}
	Pixel operator+ (Pixel x) { 
		Pixel Sum;
		Sum.R = min(this->R + x.R, 255); 
		Sum.G = min(this->G + x.G, 255);
		Sum.B = min(this->B + x.B, 255);
		return Sum;
	}
	void operator=(Pixel x) {
		this->R = x.R;
		this->G = x.G;
		this->B = x.B;
	}

};



int main()
{
	Pixel P1(11111,1,333);
	P1.show();
	Pixel P2(300, 11, 70);
	P2.show();
	Pixel P3;
	P3 = P1 + P2;
	P3.show();

}

int min(int a,int b) {
	int x = ((a-b) >> (sizeof(int) * 8 - 1) & 1);
	int y = 1^x;
	return x*a + y*b;
}