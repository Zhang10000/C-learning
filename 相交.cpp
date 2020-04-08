struct Zheng {
	Zheng(int* a) {
		x = *a++;
		y = *a++;
		xl = *a++;
		yl = *a++;
	}
	int x;
	int y;
	int xl;
	int yl;
};
bool Panduan(Zheng z1, Zheng z2) {
	return ((z1.x + z1.xl) >= z2.x && (z2.x + z2.xl) >= z1.x) 
		&& ((z1.y + z1.yl) >= z2.y && (z2.y + z2.yl) >= z1.y);
}
