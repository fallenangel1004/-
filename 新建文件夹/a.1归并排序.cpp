
#include <stdio.h>

// �鲢������������
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ������ʱ����
    int L[n1], R[n2];

    // �������ݵ���ʱ���� L[] �� R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // �鲢��ʱ���鵽 arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ���� L[] ��ʣ��Ԫ��
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ���� R[] ��ʣ��Ԫ��
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �鲢����
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // �ҵ��м��
        int mid = left + (right - left) / 2;

        // ����벿�ֵݹ�����
        mergeSort(arr, left, mid);
        // ���Ұ벿�ֵݹ�����
        mergeSort(arr, mid + 1, right);

        // �ϲ�����������벿��
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("ԭʼ���У�");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // ���ù鲢�����㷨
    mergeSort(arr, 0, n - 1);

    printf("\n��������");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

