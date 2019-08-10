#include<iostream>
#include<vector>
using namespace std;

#if 0
void Statistics(string s) {
	int len = s.size();
	int Integral = 0;
	//      ´óÐ´           Ð¡Ð´            Êý×Ö          ·ûºÅ
	int Upp_letter = 0, Low_letters = 0, Digital = 0, Symbol = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A'&&s[i] <= 'Z')
			Upp_letter++;
		else if (s[i] >= 'a'&&s[i] <= 'z')
			Low_letters++;
		else if (s[i] >= '0'&&s[i] <= '9')
			Digital++;
		else
			Symbol++;
	}
	if (len <= 4)
		Integral += 5;
	else if (len > 4 && len < 8)
		Integral += 10;
	else
		Integral += 25;
	if ((Upp_letter && (!Low_letters)) || ((!Upp_letter) && Low_letters))
		Integral += 10;
	else if(Upp_letter && Low_letters)
		Integral += 25;
	else;
	if(Digital==1)
		Integral += 10;
	else if(Digital>1)
		Integral += 20;
	else;
	if (Symbol == 1)
		Integral += 10;
	else if (Symbol > 1)
		Integral += 25;
	else;
	if(Upp_letter&&Low_letters&& Digital&&Symbol)
		Integral += 5;
	else if((Upp_letter||Low_letters)&& Digital&&Symbol)
		Integral += 3;
	else if((Upp_letter || Low_letters) && Digital)
		Integral += 2;
	else;
	if (Integral >= 90)
		cout << "VERY_WEAK" << endl;
	else if(Integral>=80)
		cout << "WEAK" << endl;
	else if(Integral>=70)
		cout << "AVERAGE" << endl;
	else if (Integral >= 60)
		cout << "STRONG" << endl; 
	else if (Integral >= 50)
		cout << "VERY_STRONG" << endl; 
	else if (Integral >= 25)
		cout << "SECURE" << endl; 
	else
		cout << "VERY_SECURE" << endl;
}

int main() {
	string s;
	while (getline(cin, s)) {
		Statistics(s);
	}
	return 0;
}

#endif


int getONE(int s) {
	int sum = 0, count = 0;
	while (s != 0) {
		if (s % 2 == 1)
			sum++;
		else {
			count = count > sum ? count : sum;
			sum = 0;
		}
			
		s /= 2;
	}
	count = count > sum ? count : sum;
	return count;
}

int main() {
	int s;
	cin >> s;
	int sum = 0, count = 0;
	while (s != 0) {
		if (s % 2 == 1)
			sum++;
		else {
			count = count > sum ? count : sum;
			sum = 0;
		}

		s /= 2;
	}
	count = count > sum ? count : sum;
	return count;
}