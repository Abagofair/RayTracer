#pragma once

class RGB {
private:
	int _r;
	int _g;
	int _b;

public:
	RGB();
	RGB(int r, int g, int b);

	int GetRed();
	int GetGreen();
	int GetBlue();

	void SetRed(int r);
	void SetGreen(int g);
	void SetBlue(int b);
};