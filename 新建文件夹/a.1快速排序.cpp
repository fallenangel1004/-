
#include <stdio.h>

// ��������Ԫ�ص�ֵ
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �ҵ���׼Ԫ�ص�λ��
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // �����һ��Ԫ����Ϊ��׼
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// ����������
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);    // �����黮�ֲ���ȡ��׼Ԫ�ص�λ��

        quickSort(arr, low, pi - 1);   // ������������
        quickSort(arr, pi + 1, high);  // ���Ҳ��������
    }
}

int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("ԭʼ���У�");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    quickSort(arr, 0, n-1);
    
    printf("\n��������У�");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
