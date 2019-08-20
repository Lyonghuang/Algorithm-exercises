#include <cstdio>

using namespace std;

struct node {
	int value;
	node* next;
};

int midNodeInList(node *head);

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

	printf("%d \n", midNodeInList(head));
	return 0;
}

int midNodeInList(node *head) {
	node *slow;
	node *fast;

	slow = head;
	fast = head;

	while (fast != NULL) {
		fast = fast->next;
		if (fast == NULL) return slow->value;
		fast = fast->next;
		if (fast == NULL) return slow->value;
		slow = slow->next;
	}
	return slow->value;
}
