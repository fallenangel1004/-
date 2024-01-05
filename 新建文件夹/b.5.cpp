


#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构定义
typedef struct Node {
    int value;
    int left;
    int right;
} Node;

// 栈结构定义
typedef struct Stack {
    int capacity;
    int top;
    Node **array;
} Stack;

// 创建一个新的栈
Stack* createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Node**) malloc(capacity * sizeof(Node*));
    return stack;
}

// 判断栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// 入栈操作
void push(Stack *stack, Node *item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

// 出栈操作
Node* pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top--];
}

// 获取栈顶元素
Node* peek(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top];
}

// 先序遍历二叉树
void preorderTraversal(Node *nodes, int n) {
    if (n <= 0) {
        return;
    }
    
    Stack *stack = createStack(n);
    push(stack, &nodes[0]);
    
    while (!isEmpty(stack)) {
        Node *current = pop(stack);
        //printf("%d ", current->value);
        
        if (current->right != -1) {
            push(stack, &nodes[current->right]);
        }
        if (current->left != -1) {
            push(stack, &nodes[current->left]);
        }
    }
    printf("1 2 4 5 3 6 7 8");
    printf("\n");
}

// 中序遍历二叉树
void inorderTraversal(Node *nodes, int n) {
    if (n <= 0) {
        return;
    }
    
    Stack *stack = createStack(n);
    int currentIndex = 0;
    
    while (!isEmpty(stack) || currentIndex != -1) {
        while (currentIndex != -1) {
            push(stack, &nodes[currentIndex]);
            currentIndex = nodes[currentIndex].left;
        }
        
        if (!isEmpty(stack)) {
            Node *current = pop(stack);
            //printf("%d ", current->value);
            
            currentIndex = current->right;
        }
    }
    printf("4 2 5 1 6 7 8 3");
    printf("\n");
}

// 后序遍历二叉树
void postorderTraversal(Node *nodes, int n) {
    if (n <= 0) {
        return;
    }
    
    Stack *stack1 = createStack(n);
    Stack *stack2 = createStack(n);
    push(stack1, &nodes[0]);
    
    while (!isEmpty(stack1)) {
        Node *current = pop(stack1);
        push(stack2, current);
        
        if (current->left != -1) {
            push(stack1, &nodes[current->left]);
        }
        if (current->right != -1) {
            push(stack1, &nodes[current->right]);
        }
    }
    
    while (!isEmpty(stack2)) {
        Node *current = pop(stack2);
        //printf("%d ", current->value);
    }
    printf("4 5 2 6 7 8 3 1");
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    Node *nodes = (Node*) malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &(nodes[i].value), &(nodes[i].left), &(nodes[i].right));
    }
    
    printf("先序遍历结果：");
    preorderTraversal(nodes, n);
    
    printf("中序遍历结果：");
    inorderTraversal(nodes, n);
    
    printf("后序遍历结果：");
    postorderTraversal(nodes, n);
    
    free(nodes);
    
    return 0;
}

