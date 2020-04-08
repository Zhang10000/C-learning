class stac {
public:
	void pop() {
		if (a.size() == 0) {
			return;
		}
		while (a.size() != 1) {
			tmp.push(a.front());
			a.pop();
		}
		a.pop();
		while (tmp.size() != 0) {
			a.push(tmp.front());
			tmp.pop();
		}
	}
	void push(int val) {
		a.push(val);
	}
	int top() {
		if (a.size() == 0) {
			return INT16_MIN;
		}
		while (a.size() != 1) {
			tmp.push(a.front());
			a.pop();
		}
		int b = a.front();
		tmp.push(b);
		a.pop();
		while (tmp.size() != 0) {
			a.push(tmp.front());
			tmp.pop();
		}
	}
private:
	queue<int> a;
	queue<int> tmp;
};


struct ListNode {
	int val;
	ListNode* next;
};

ListNode* List_in(ListNode* Proot) {
	assert(Proot);
	ListNode* fast = Proot;
	ListNode* slow = Proot;
	while (fast && slow && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}
