
#include <stdio.h>

#define max 1000

typedef struct {
    int row; 
    int col; 
    int value; 
} tt;

void sparse(tt mata[], tt matb[], int rows, int cols) {
    int a = 0, b = 0, c = 0;
    tt matc[max];

    while (a < mata[0].value && b < matb[0].value) {
        int indexa = mata[a].row * cols + mata[a].col;
        int indexb = matb[b].row * cols + matb[b].col;

        if (indexa < indexb) {
            matc[c++] = mata[a++];
        } else if (indexa > indexb) {
            matc[c++] = matb[b++];
        } else {
            matc[c].row = mata[a].row;
            matc[c].col = mata[a].col;
            matc[c++].value = mata[a++].value + matb[b++].value;
        }
    }

    for (; a < mata[0].value; a++) {
        matc[c++] = mata[a];
    }

    for (; b < matb[0].value; b++) {
        matc[c++] = matb[b];
    }

    matc[0].row = rows;
    matc[0].col = cols;
    matc[0].value = c - 1;

    printf("相加结果：\n");
    for (int i = 0; i <= matc[0].value; i++) {
        printf("%d %d %d\n", matc[i].row, matc[i].col, matc[i].value);
    }
}

void spa(tt mata[], tt matb[], int numRowsa, int numcolsa, int numcolsb) {
    tt matc[max];

    if (numcolsa != matb[0].row) {
        printf("无法相乘\n");
        return;
    }

    // 元素初始化为0
    for (int i = 0; i < numRowsa; i++) {
        for (int j = 0; j < numcolsb; j++) {
            matc[i * numcolsb + j].row = i;
            matc[i * numcolsb + j].col = j;
            matc[i * numcolsb + j].value = 0;
        }
    }

    for (int i = 0; i < numRowsa; i++) {
        int startPosa = mata[i].value;
        int endPosa = (i == numRowsa - 1) ? mata[0].value : mata[i + 1].value;

        for (int j = 0; j < numcolsb; j++) {
            int sum = 0;

            for (int k = startPosa; k < endPosa; k++) {
                int colIdxa = mata[k].col;

                for (int l = 0; l < matb[0].value; l++) {
                    int rowIdxb = matb[l].row;
                    int colIdxb = matb[l].col;
                    int valueb = matb[l].value;

                    if (colIdxa == rowIdxb && j == colIdxb) {
                        sum += mata[k].value * valueb;
                        break;
                    }
                }
            }

            if (sum != 0) {
                matc[i * numcolsb + j].row = i;
                matc[i * numcolsb + j].col = j;
                matc[i * numcolsb + j].value = sum;
            }
        }
    }

    matc[0].row = numRowsa;
    matc[0].col = numcolsb;
    matc[0].value = numRowsa * numcolsb;

    printf("相乘结果：\n");
    for (int i = 0; i <= matc[0].value; i++) {
        printf("%d %d %d\n", matc[i].row, matc[i].col, matc[i].value);
    }
}

int main() {
    // 矩阵a
    tt mata[max];
    mata[0].row = 3;
    mata[0].col = 3;
    mata[0].value = 4;
    mata[1].row = 0;
    mata[1].col = 0;
    mata[1].value = 1;
    mata[2].row = 1;
    mata[2].col = 1;
    mata[2].value = 2;
    mata[3].row = 1;
    mata[3].col = 2;
    mata[3].value = 3;
    mata[4].row = 2;
    mata[4].col = 0;
    mata[4].value = 4;

    // 矩阵b
    tt matb[max];
    matb[0].row = 3;
    matb[0].col = 3;
    matb[0].value = 4;
    matb[1].row = 0;
    matb[1].col = 1;
    matb[1].value = -1;
    matb[2].row = 1;
    matb[2].col = 0;
    matb[2].value = 2;
    matb[3].row = 1;
    matb[3].col = 2;
    matb[3].value = 3;
    matb[4].row = 2;
    matb[4].col = 1;
    matb[4].value = 4;

    sparse(mata, matb, 3, 3);
    spa(mata, matb, 3, 3, 3);

    return 0;
}

