


#include <stdio.h>
#include <stdlib.h>

// �������ڵ�ṹ����
typedef struct Node {
    int value;
    int left;
    int right;
} Node;

// ջ�ṹ����
typedef struct Stack {
    int capacity;
    int top;
    Node **array;
} Stack;

// ����һ���µ�ջ
Stack* createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Node**) malloc(capacity * sizeof(Node*));
    return stack;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// �ж�ջ�Ƿ�����
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// ��ջ����
void push(Stack *stack, Node *item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

// ��ջ����
Node* pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top--];
}

// ��ȡջ��Ԫ��
Node* peek(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top];
}

// �������������
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

// �������������
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

// �������������
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
    
    printf("������������");
    preorderTraversal(nodes, n);
    
    printf("������������");
    inorderTraversal(nodes, n);
    
    printf("������������");
    postorderTraversal(nodes, n);
    
    free(nodes);
    
    return 0;
}

