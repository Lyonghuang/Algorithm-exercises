#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

struct node {
	int value;
	node* next;
};

int ring(node *head);

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
	
	p->next = head->next;
	if (ring(head)) {
		printf("有环,环的入口节点值为%d\n", ring(head));
	} 
	else {
		printf("没有环\n");
	}

	return 0;
}

int ring(node *head) {
	node *slow = head;
	node *fast = head;
	while (slow != NULL) {
		fast = fast->next;
		if (fast == NULL) break;
		fast = fast->next;
		if (fast == NULL) break;
		slow = slow->next;

		if (fast == slow) {
			slow = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow->value;
		}
	}
	return -1;
}
