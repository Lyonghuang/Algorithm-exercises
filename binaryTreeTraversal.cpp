#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

struct node {
	int value;
	node* left;
	node* right;
};

void build(int *a, int n, node *head, int index);//将一个数组分层从左到右构建一个二叉树
void preTraversal(node *head);//前序遍历
void midTraversal(node *head);//中序遍历
void postTraversal(node *head);//后序遍历
void levelTraversal(node *head);//层次遍历
void snakeTraversal(node *node);//蛇形遍历

int main() {
	int n;
	int a[100];
	node *head = new node;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	head->value = a[0];
	head->left = NULL;
	head->right = NULL;

	build(a, n, head, 0);
	printf("\n前序遍历\n");
	preTraversal(head);
	printf("\n中序遍历\n");
	midTraversal(head);
	printf("\n后序遍历\n");
	postTraversal(head);
	printf("\n分层遍历\n");
	levelTraversal(head);
	printf("\n蛇形遍历\n");
	snakeTraversal(head);

	printf("\n");
	return 0;
}

/*
参数说明：
*a：用于构建二叉树的数组
n：数组的元素数量
*head：二叉树的根节点，构建的入口节点
index：当前节点对于数组的下标值
返回值：无
复杂度：O(n)
*/
void build(int *a, int n, node *head, int index) {
	node *p;
	if (index * 2 + 1 >= n) return;
	head->left = new node;
	p = head->left;
	p->value = a[index * 2 + 1];
	p->left = NULL;
	p->right = NULL;
	build(a, n, p, index * 2 + 1);

	if (index * 2 + 2 >= n) return;
	head->right = new node;
	p = head->right;
	p->value = a[index * 2 + 2];
	p->left = NULL;
	p->right = NULL;
	build(a, n, p, index * 2 + 2);
}

/*
参数说明：
*head：当前访问的节点
返回值：无
*/
void preTraversal(node *head) {
	//printf("Preorder traversal:\n");
	if (head == NULL) return;
	printf("%d ", head->value);
	preTraversal(head->left);
	preTraversal(head->right);
}

/*
参数说明：
*head：当前访问的节点
返回值：无
*/
void midTraversal(node *head) {
	if (head == NULL) return;
	midTraversal(head->left);
	printf("%d ", head->value);
	midTraversal(head->right);
}

/*
参数说明：
*head：当前访问的节点
返回值：无
*/
void postTraversal(node *head) {
	if (head == NULL) return;
	postTraversal(head->left);
	postTraversal(head->right);
	printf("%d ", head->value);
}

/*
参数说明：
*head：当前访问的节点
返回值：无
*/

void levelTraversal(node *head) {
	queue<node*> mqueue;
	
	if (head == NULL) return;
	mqueue.push(head);
	while (!mqueue.empty()) {
		node *p = mqueue.front();
		if (p->left != NULL) {
			mqueue.push(p->left);
		}
		if (p->right != NULL) {
			mqueue.push(p->right);
		}
		printf("%d ", p->value);
		mqueue.pop();
	}
}

/*
参数说明：
*head：当前访问的节点
返回值：无
*/

void snakeTraversal(node *head) {
	stack<node*> stack_1;
	stack<node*> stack_2;

	stack_1.push(head);
	
	while (!stack_1.empty() || !stack_2.empty()) {
		while (!stack_1.empty()) {
			node *p = stack_1.top();
			if (p->left != NULL) {
				stack_2.push(p->left);
			}
			if (p->right != NULL) {
				stack_2.push(p->right);
			}
			printf("%d ", p->value);
			stack_1.pop();
		}

		while (!stack_2.empty()) {
			node *p = stack_2.top();
			if (p->right != NULL) {//注意这里是先把右孩子节点入栈，因为stack_2是从左往右遍历的
				stack_1.push(p->right);
			}
			if (p->left != NULL) {
				stack_1.push(p->left);
			}
			printf("%d ", p->value);
			stack_2.pop();
		}
	}
}
