#include<iostream>
#include<list>
#include<unordered_map>
#include<utility>
using namespace std;
unordered_map<int, list<pair<int, int>>::iterator> map;
list<pair<int, int>> Lis;
int capcity;
int get(int k) {
	auto i = map.find(k);
	if (i == map.end())
		return -1;
	int res = i->second->second;
	Lis.erase(i->second);
	Lis.push_front(make_pair(k, res));
	map[k] = Lis.begin();
	return res;
}

void put(int k, int v) {
	auto i = map.find(k);
	if (i != map.end()) {
		i->second->second = v;
	} else {
		if (Lis.size() == capcity) {
			int key = Lis.back().first;
			Lis.pop_back();
			map.erase(key);
		}
		Lis.push_front(make_pair(k, v));
		map[k] = Lis.begin();
	}		
}

int main() {
	cin >> capcity;
	int k, v;
	char c;
	while (cin >> c) {
		if (c == 'p') {
			cin >> k >> v;
			if (capcity <= 0)continue;
			put(k, v);
		}
		if (c == 'g') {
			cin >> k;
			cout << get(k) << endl;
		}
	}
	return 0;
}
