
#include <stdio.h>
#include <stdlib.h> 
#define max 100

typedef struct {
    int data[max];
    int top;
} ss;

void initss(ss* ss) {
    ss->top = -1;
}

int Empty(ss* ss) {
    return ss->top == -1;
}

void push(ss* ss, int value) {
    if (ss->top < max - 1) {
        ss->data[++ss->top] = value;
    } else {
        printf("栈已满，无法入栈\n");
    }
}

int pop(ss* ss) {
    if (!Empty(ss)) {
        return ss->data[ss->top--];
    } else {
        printf("栈为空，无法出栈\n");
        return -1;
    }
}

void decimal(int num) {
    ss ss;
    initss(&ss);

    while (num != 0) {
        push(&ss, num % 2);
        num /= 2;
    }

    printf("二进制:");
    while (!Empty(&ss)) {
        printf("%d", pop(&ss));
    }
    printf("\n");
}

void decimalt(int num) {
    ss ss;
    initss(&ss);

    while (num != 0) {
        push(&ss, num % 8);
        num /= 8;
    }

    printf("八进制:");
    while (!Empty(&ss)) {
        printf("%d", pop(&ss));
    }
    printf("\n");
}

void decimalT(int num) {
    ss ss;
    initss(&ss);

    while (num != 0) {
        int remain = num % 16;
        if (remain < 10) {
            push(&ss, remain);
        } else {
            push(&ss, 'A' + remain - 10);
        }
        num /= 16;
    }

    printf("十六进制:");
    while (!Empty(&ss)) {
        int value = pop(&ss);
        if (value >= 0 && value <= 9) {
            printf("%d", value);
        } else {
            printf("%c", value);
        }
    }
    printf("\n");
}

int main() {
    int num;
    printf("输入: ");
    scanf("%d", &num);

    decimal(num);
    decimalt(num);
    decimalT(num);

    return 0;
}
