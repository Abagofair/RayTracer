#pragma once

class RGB {
private:
	char _r;
	char _g;
	char _b;

public:
	RGB(char r, char g, char b);

	char GetRed();
	char GetGreen();
	char GetBlue();

	void SetRed(char r);
	void SetGreen(char g);
	void SetBlue(char b);
};