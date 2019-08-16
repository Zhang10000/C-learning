#include<iostream>
#include<vector>
using namespace std;
int Sum_black(int chang, int x, int y) {
	int black;
	if (x % 2 == 1 && y % 2 == 1) {
		if (chang == 0)
			black = x * y / 2;
		else 
			black = x * y / 2 + 1;
	}
	else 
		black = x * y / 2;
	return black;
}
int Chang(int x, int y) {
	if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1))
		return 1;
	else
		return 0;
}
int main() {
	int T;
	while (cin >> T) { 
		vector<int>white;
		vector<int>black;
		for (int i = 0; i < T; ++i) {
			int bl = 0, wh = 0;
			int x, y, x1, y1, x2, y2, x3, y3;
			cin >> x >> y;
			int s = Sum_black(Chang(x, y), x, y);
			bl += s;
			wh += x * y - s;
			cin >> x >> y >> x1 >> y1;          // Í¿°×
			s = Sum_black(Chang(x, y), x1 - x + 1, y1 - y + 1);
			bl -= s;
			wh += s;
			cin >> x2 >> y2 >> x3 >> y3;          //Í¿ºÚ
			s = Sum_black(Chang(x2, y2), x3 - x2 + 1, y3 - y2 + 1);
			bl += ((x3 - x2 + 1)*(y3 - y2 + 1) - s);
			wh -= ((x3 - x2 + 1)*(y3 - y2 + 1) - s);
			if (x1 - x2 + 1 > 0 && y1 - y2 + 1 > 0) s = Sum_black(Chang(x2, y2), x1 - x2 + 1, y1 - y2 + 1);
			else if(x3 - x + 1 > 0 && y3 - y + 1 > 0) s = Sum_black(Chang(x, y), x3 - x + 1, y3 - y + 1);
			else if (x1 - x2 + 1 > 0 && y3 - y + 1 > 0) s = Sum_black(Chang(x2, y), x1 - x2 + 1, y3 - y + 1);
			else if (x3 - x1 + 1 > 0 && y1 - y2 + 1 > 0) s = Sum_black(Chang(x1, y2), x3 - x1 + 1, y1 - y2 + 1);
			else if (x2 >= x && y2 >= y && x1 >= x3 && y1 >= y3) s = Sum_black(Chang(x2, y2), x3 - x2 + 1, y3 - y2 + 1);
			else if (x >= x2 && y >= y2 && x3 >= x1 && y3 >= y1) s = Sum_black(Chang(x, y), x1 - x + 1, y1 - y + 1);
			else s = 0;
			bl += s;
			wh -= s;
			white.push_back(wh);
			black.push_back(bl);
		}
		for (int i = 0; i < T; ++i) {
			cout << white[i];
			cout << ' ' << black[i] << endl;
		}
	}
	return 0;
}