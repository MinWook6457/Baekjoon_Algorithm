#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)
typedef struct TreeNode {
	char data;
	struct TreeNode* left, * right;
}TreeNode;

void inorder(TreeNode* root) {
	if (root->data == '.')
		return;
	if (root != NULL) {
		inorder(root);
		printf("%c", root->data);
		inorder(root);
	}
}

void preorder(TreeNode* root) {
	if (root->data == '.')
		return;
	if (root != NULL) {
		printf("%c", root->data);
		preorder(root);
		preorder(root);
	}
}

void postorder(TreeNode* root) {
	if (root->data == '.')
		return;
	if (root != NULL) {
		postorder(root);
		postorder(root);
		printf("%c", root->data);
	}
}
TreeNode* new_node(char n, char p) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	strcpy(temp->data, n);
	strcpy(temp->data, p);
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode * node, char root, char left,char right) {
		if (node == NULL)
			return new_node(root,left,right);
		if (strcmp(root, node->data) < 0)
			node->left = insert_node(node->left, root,left, right);
		else
			node->right = insert_node(node->right, root,left, right);
		return node;
}

void main() {
	int n;
	char data, left, right;
	TreeNode* root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c%c%c", &data, &left, &right);
		insert_node(root, data, left, right);
	}

}