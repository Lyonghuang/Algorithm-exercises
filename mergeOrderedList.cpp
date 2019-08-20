#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

struct node {
	int value;
	node* next;
};

/*
两种合并链表方法比较：第一种方法使用了额外空间创建新链表，空间复杂度为O(n),
第二种方法空间复杂度为O(1),时间复杂度和算法复杂度都差不多，因此第二种方法更佳
*/
node* mergeList(node *head_1, node *head_2);
node* mergeList_2(node *head_1, node *head_2);

int main() {
	int n, a;
	node *head = new node;
	node *head_2 = new node;
	node *new_head;
	node *p;
	/*输入第一组数据生成第一个链表，这里应保证输入的数据从小到大排列*/
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
	/*输入第二组数据生成第二个链表，这里应保证输入的数据从小到大排列*/
	scanf("%d", &n);
	scanf("%d", &a);
	head_2->value = a;
	head_2->next = NULL;
	p = head_2;

	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		p->next = new node;
		p = p->next;
		p->value = a;
		p->next = NULL;
	}

	new_head = mergeList_2(head, head_2);
	p = new_head;
	while (p != NULL) {
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
	return 0;
}

node* mergeList(node *head_1, node *head_2) {
	node *re;
	re = new node;
	re->next = NULL;
	node *p = re;
	while (head_1 != NULL && head_2 != NULL) {
		p->next = new node;
		p = p->next;
		if (head_1->value < head_2->value) {
			p->value = head_1->value;
			p->next = NULL;
			head_1 = head_1->next;
		}
		else {
			p->value = head_2->value;
			p->next = NULL;
			head_2 = head_2->next;
		}
	}

	while (head_1 != NULL) {
		p->next = new node;
		p = p->next;
		p->value = head_1->value;
		p->next = NULL;
		head_1 = head_1->next;
	}

	while (head_2 != NULL) {
		p->next = new node;
		p = p->next;
		p->value = head_2->value;
		p->next = NULL;
		head_2 = head_2->next;
	}

	return re->next;
}

node* mergeList_2(node *head_1, node *head_2) {
	if (head_1 == NULL) return head_2;
	if (head_2 == NULL) return head_1;

	node *p;
	node *q;
	node *cur;
	node *re;

	p = head_1;
	q = head_2;

	if (p->value < q->value) {
		re = p;
		p = p->next;
	}
	else {
		re = q;
		q = q->next;
	}
	cur = re;

	while (p != NULL && q != NULL) {
		if (p->value < q->value) {
			cur->next = p;
			cur = cur->next;
			p = p->next;
		}
		else {
			cur->next = q;
			cur = cur->next;
			q = q->next;
		}
	}

	if (p != NULL) {
		cur->next = p;
	}
	else {
		cur->next = q;
	}

	return re;
}
