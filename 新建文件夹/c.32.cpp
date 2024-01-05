
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 初始化二叉树节点
struct TreeNode* createNode(char val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 查找从根节点到目标叶子节点的路径
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
    // 构建测试二叉树
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
        printf("从根节点到叶子节点 %c 的路径是: ", target);
        for (int i = 0; i < sizeof(path); i++) {
            if (path[i] == target) {
                printf("%c", target);
                break;
            }
            printf("%c -> ", path[i]);
        }
        printf("\n");
    } else {
        printf("%c 不是叶子节点\n", target);
    }
    
    return 0;
}

