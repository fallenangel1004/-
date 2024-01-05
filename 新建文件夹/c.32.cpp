
#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ��ʼ���������ڵ�
struct TreeNode* createNode(char val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ���ҴӸ��ڵ㵽Ŀ��Ҷ�ӽڵ��·��
int findPath(struct TreeNode* root, char target, char* path, int index) {
    if (root == NULL) {
        return 0;
    }
    path[index] = root->val;
    index++;
    if (root->val == target && root->left == NULL && root->right == NULL) {
        return 1;
    }
    if (findPath(root->left, target, path, index) || findPath(root->right, target, path, index)) {
        return 1;
    }
    return 0;
}

int main() {
    // �������Զ�����
    struct TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');
    
    char target = 'F';
    char path[100];
    if (findPath(root, target, path, 0)) {
        printf("�Ӹ��ڵ㵽Ҷ�ӽڵ� %c ��·����: ", target);
        for (int i = 0; i < sizeof(path); i++) {
            if (path[i] == target) {
                printf("%c", target);
                break;
            }
            printf("%c -> ", path[i]);
        }
        printf("\n");
    } else {
        printf("%c ����Ҷ�ӽڵ�\n", target);
    }
    
    return 0;
}

