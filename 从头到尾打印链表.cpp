#include<vector>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
		
	}
};
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>v;
		stack<int>s;
		while (head) {
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty()) {
			v.push_back(s.top());
			s.pop();
		}
		return v;
	}
};