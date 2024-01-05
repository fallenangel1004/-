
#include <stdio.h>

int minimumSteps(int array[], int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] != i + 1) {
            int j = i + 1;
            while (array[j] != i + 1) {
                j++;
            }
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int array[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }
    
    int steps = minimumSteps(array, N);
    printf("最少变换步数：%d\n", steps);
    
    return 0;
}

