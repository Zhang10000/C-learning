//  真的自己准备数据测试好
//  长宽搞反这种傻子问题看不出来太炸裂了
class Solution3 {
public:
	vector<int> printMatrix(vector<vector<int>> matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> arr;
		if (row == 0 || col == 0)
			return arr;
		int left = 0, right = col - 1, top = 0, btm = row - 1;
		while (left <= right && top <= btm) {
			for (int i = left; i <= right; i++)
				arr.push_back(matrix[top][i]);
			for (int i = top+1; i <= btm; i++)
				arr.push_back(matrix[i][right]);
			if(top != btm)
				for (int i = right-1; i >= left; i--)
					arr.push_back(matrix[btm][i]);
			if (left != right)
				for (int i = btm-1; i > top; i--)
					arr.push_back(matrix[i][left]);
			left++, top++, right--, btm--;
		}
		return arr;
	}
};
