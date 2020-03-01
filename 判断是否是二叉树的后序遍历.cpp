class Solution5 {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 1)
			return true;
		return  ofbst(sequence, 0, sequence.size() - 1);
	}
	bool ofbst(vector<int> seq, int begin, int end) {
		if (seq.empty() || begin > end)
			return false;
		int root = seq[end];
		int i = begin;
		for (; i < end; i++)
			if (seq[i] > root)
				break;
		for (int j = i; j < end; j++)
			if (seq[j] < root)
				return false;
		bool left = true;
		if (i > begin)
			left = ofbst(seq, begin, i - 1);
		bool right = true;
		if (i < end - 1)
			right = ofbst(seq, i, end - 1);
		return left && right;
	}
};
