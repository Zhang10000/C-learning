#include<stack>
#include<iostream>
using namespace std;
class Solution {
public:
	void classpush(int node) {
		stack1.push(node);
	}
	int pop() {
		int p = 0;
		if (stack1.size() == 0);
		else {
			while (!stack1.empty()) {
				int tmp = stack1.top();
				stack1.pop();
				stack2.push(tmp);
			}
			p = stack2.top();
			stack2.pop();
			while (!stack2.empty()) {
				int tmp = stack2.top();
				stack2.pop();
				stack1.push(tmp);
			}
		}
		return p;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};