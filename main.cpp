//12. В массив А(N,М) после первого отрицательного элемента каждого
//столбца вставить число, равное минимальному элементу этого столбца.
//Если столбец не содержит отрицательных элементов, то вставить это
//число перед первым элементом столбца.

#include <iostream>
#include <stdlib.h>

using namespace std;

const int N=4;
void OutputArray (int A[][N], int n, int m)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout.width(6);
            cout<<A[i][j];
            cout.width(6);
        }
        cout<<endl;
    }
}

int Min (int A[][N], int n, int column)
{
    int min=A[0][0];
    for (int i=0; i<n; i++)
    {
        if (A[i][column]<min)
        {
            min=A[i][column];
        }
    }
    return min;
}

int main()
{
    const int n=4, m=4;
    int A[n][m]={{7,-6,-6,9},{-1,4,-3,3},{11,13,10,1},{-3,-12,-4,0}};
    cout<<"Array A: "<<endl;
    OutputArray (A, n, m);
    const int k=5;
    int B[k][m];
    for (int j=0; j<m; j++)
    {
        if (Min(A, n, j)<0)//Проверка на наличие отрицательных элементов в столбце
        {
            int indB=0;
            for (int i=0; i<n; i++)
            {
                if (A[i][j]>=0)
                {
                    B[indB][j]=A[i][j];
                    indB++;
                }
                else
                {
                    B[indB][j]=A[i][j];
                    indB++;
                    i++;
                    B[indB][j]=Min(A, n, j);//Элемент, стоящий после отрицательного, заменяется на Min
                    indB++;
                    while (indB<k)
                    {
                        B[indB][j]=A[i][j];
                        indB++;
                        i++;
                    }
                }
             }
        }
        else   //Если в столбце нет отрицательных элементов
        {
            B[0][j]=Min(A, n, j);
            int indB=1;
            for (int i=0; i<n; i++)
            {
                B[indB][j]=A[i][j];
                indB++;
            }
        }
    }
    cout<<endl<<"Array B:"<<endl;
    OutputArray (B, k, m);
    return 0;
}
