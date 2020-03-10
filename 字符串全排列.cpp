class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.size() != 0) {
			int nSize = str.size();
			Permutation(str, nSize, 0);
		}
		for (set<string>::iterator iter = permutationSet.begin(); iter != permutationSet.end(); ++iter)
			permutation.push_back(*iter);
		return permutation;
	}
	void Permutation(string str, int nSize, int n) {
		if (n == str.size())
			permutationSet.insert(str);
		else {
			Permutation(str, nSize, n + 1);
			for (size_t i = n + 1; i < str.size(); ++i) {
				if (str[n] != str[i]){
					swap(str[n], str[i]);
					Permutation(str, nSize, n + 1);
					swap(str[n], str[i]);
				}
			}
		}
	}
public:
	vector<string> permutation;
	set<string> permutationSet;
};
