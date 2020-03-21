class Solution {
public:
	void push(int value) {
		k.push(value);
		if (m.empty())
			m.push(value);
		if (m.top() > value)
			m.push(value);
	}
	void pop() {
		if (m.top()==k.top())
            m.pop();
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
