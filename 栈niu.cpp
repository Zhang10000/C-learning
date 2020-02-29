class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0)
			return false;
		stack<int> st;
		for (int i = 0, j = 0; i < pushV.size();) {
			st.push(pushV[i++]);
			while (j < popV.size() && st.top() != popV[j]) {
				st.pop();
				j++;
			}
		}
		return st.empty();
	}
};
