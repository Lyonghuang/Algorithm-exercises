#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

struct node {
	int value;
	node* next;
};

void printList(node *head);

/*
三种方法比较：第一种使用了临时的栈保存链表数据，第二种使用递归，
第三种只使用了两个临时指针变量，不管从时间上还是空间上都是第三种方法最佳
*/
node* inversionList_1(node *head);
node* inversionList_2(node *head);
node* inversionList_3(node *head);

int main() {
	int n, a;
	node *head = new node;
	node *p;

	scanf("%d", &n);
	scanf("%d", &a);
	head->value = a;
	head->next = NULL;
	p = head;

	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		p->next = new node;
		p = p->next;
		p->value = a;
		p->next = NULL;
	}

	printList(head);
	printf("\n反转链表方法一：\n");
	head = inversionList_1(head);
	printList(head);

	printf("\n反转链表方法二：\n");
	head = inversionList_1(head);
	printList(head);

	printf("\n反转链表方法三：\n");
	head = inversionList_1(head);
	printList(head);
	return 0;
}

void printList(node *head) {
	while (head != NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

node* inversionList_1(node *head) {
	node *p = head;
	stack<int> mstack;
	node *re;
	while (p != NULL) {
		mstack.push(p->value);
		p = p->next;
	}
	p = head;
	while (p != NULL) {
		p = p->next;
		delete head;
		head = p;
	}
	if (!mstack.empty()) {
		re = new node;
		re->value = mstack.top();
		re->next = NULL;
		mstack.pop();
	}
	p = re;
	while (!mstack.empty()) {
		p->next = new node;
		p = p->next;
		p->value = mstack.top();
		p->next = NULL;
		mstack.pop();
	}

	return re;
}

node* inversionList_2(node *head) {
	node *re;
	if (head == NULL) {
		return NULL;
	}
	if (head->next != NULL) {
		re = inversionList_2(head->next);
		re->next = head;
	}
	else {
		return head;
	}
	return re;
}

node* inversionList_3(node *head) {
	node *re;
	node *p;
	re = head;
	if (head == NULL) {
		return NULL;
	}
	while (re->next != NULL) {
		p = re;
		re = re->next;
		re->next = p;
	}
	return re;
}

