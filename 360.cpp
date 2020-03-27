int main0() {
	int N;
	while (cin >> N) {
		if (N == 0) {
			cout << 0 << endl;
			break;
		}
		int n;
		vector<int>sum(1, 0);
		vector<char>tmp(1, '0');
		while(N--){
			cin >> n;
			if (n == 0) {
				for (auto e : tmp)
					e = '0';
			}
			if (n == 1) {
				for (size_t i = 0; i < tmp.size(); i++) {
					tmp[i] += 1;
				}
				for (size_t i = 0; i < sum.size(); i++) {
					sum[i] += tmp[i] - '0';
				}
			}
			if (n == 2) {
				int size = sum.size();
				for (int i = 0; i < size; i++) {
					sum.push_back(sum[i]);
					tmp[i] += 1;
					tmp.push_back('0');
				}
				for (size_t i = 0; i < sum.size(); i++) {
					sum[i] += tmp[i] - '0';
				}
			}
		}
		int count = 0;
		for (size_t i = 0; i < sum.size(); i++) {
			count += sum[i];
		}
		cout << count / sum.size() << endl;
	}
	return 0;
}
