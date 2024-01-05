
#include <stdio.h>

void countSort(int arr[], int n) {
    // �ҳ������е����Ԫ��
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // �����������鲢��ʼ��Ϊ0
    int count[max + 1];
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // ����ÿ��Ԫ�س��ֵĴ���
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // ����������ת��Ϊ�ۼӺ�����
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // ������ʱ�������ڴ洢������
    int output[n];

    // ����ԭʼ����ͼ������飬��Ԫ�ط�����ʱ���鲢���¼�������
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // ����ʱ����Ľ��������ԭʼ����
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("ԭʼ���飺");
    printArray(arr, n);

    countSort(arr, n);

    printf("���������飺");
    printArray(arr, n);

    return 0;
}

