#include <stdio.h>
#include <stdlib.h>

void setZeros(int **matrix, int n, int m) {
    int firstRow=0, firstColumn=0;
    for (int i=0; i<n; ++i) {
        if (matrix[i][0]==0) firstColumn=1;
    }
    for (int j=0;j<m;++j) {
        if (matrix[0][j]==0) firstRow=1;
    }
    for (int i=1;i<n;++i) {
        for (int j=1;j<m;++j) {
            if (matrix[i][j]==0) {
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }
    for (int i=1;i<n;++i) {
        for (int j=1;j<m;++j) {
            if (matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
        }
    }
    if (firstColumn) {
        for (int i=0;i<n;++i) matrix[i][0]=0;
        }
    if (firstRow) {
        for (int j=0;j<m;++j) matrix[0][j]=0;
        }
}

int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    int **matrix=(int **)malloc(n*sizeof(int *));
    for (int i=0;i<n;++i) {
        *(matrix+i)=(int *)malloc(m*sizeof(int));
        for (int j=0;j<m;++j) {
            scanf("%d",*(matrix+i)+j);
        }
    }
    setZeros(matrix,n,m);
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            printf("%d ",*(*(matrix+i)+j));
        }
        printf("\n");
    }
    for (int i=0;i<n;++i) {
        free(matrix+i);
    }
    free(matrix);
    return 0;
}
