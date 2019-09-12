#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
typedef struct node {
	char ch;
	struct node * l, *r;
}node_t, *node_l;

void create_tree(node_l * root, char  lastlist[], char  midlist[]);
int findIndex(char last, char* midlist);
void print(node_l root);
int main() {

	node_l root;
	char lastlist[100];
	char midlist[100];
	bzero(lastlist, sizeof(lastlist));
	bzero(midlist, sizeof(midlist));
	cin >> midlist;
	cin >> lastlist;
	create_tree(&root, lastlist, midlist);
	print(root);
}
void print(node_l root) {

	if (root) {
		cout << root->ch << "";
		print(root->l);
		print(root->r);
	}
}
void create_tree(node_l* root, char lastlist[], char midlist[]) {
	static int index = strlen(lastlist) - 1;
	int mid_index;

	mid_index = findIndex(lastlist[index], midlist);
	*root = (node_l)malloc(sizeof(node_t));
	(*root)->ch = lastlist[index];

	lastlist[index--] = '\0';
	if (index == -1)return;
	midlist[mid_index] = '\0';
	if (midlist[mid_index + 1] != '\0') {
		create_tree(&((*root)->r), lastlist, &midlist[mid_index + 1]);
	}
	else {
		(*root)->r = NULL;
	}
	if (midlist[mid_index - 1] != '\0') {
		create_tree(&((*root)->l), lastlist, midlist);
	}
	else {
		(*root)->l = NULL;
	}
}

int findIndex(char  last, char * mid) {

	int i;
	for (i = 0; *(mid + i) != '\0'; i++) {
		if (last == *(mid + i)) {
			return i;
		}
	}
	return 0;
}
