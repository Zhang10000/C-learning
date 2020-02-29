class Solution {
public:
	void push(int value) {
		k.push(value);
		if (m.empty()) {
			m.push(value);
			return;
		}	
		if (m.top() >= value)
			m.push(value);
	}
	void pop() {
		if (k.top() == m.top()) {
			k.pop();
			m.pop();
		} else
			k.pop();
	}
	int top() {
		return k.top();
	}
	int min() {
		return m.top();
	}
private:
	stack<int> k;
	stack<int> m;
};
