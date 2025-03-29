// Create a matrix like an int**

#include <iostream>
using namespace std;

int* getRow(int len);
int** getM(int r, int c);
void fillM(int** pMatr, int r, int c);
void printM(int** pMatr, int r, int c, char name);
int** sumMatr(int** pM1, int** pM2, int rows, int cols);


int main()
{
    int row = 4, col = row;
    int** pMatr1 = getM(row, col);
    int** pMatr2 = getM(row, col);

    fillM(pMatr1, row, col);
    printM(pMatr1, row, col, '1');
    fillM(pMatr2, row, col);
    printM(pMatr2, row, col, '2');
    
    cout << "Matrix sum = " << endl;
    int** pSumMatr = sumMatr(pMatr1, pMatr2, row, col);
    printM(pSumMatr, row, col, '3');
    

    return 0;
}


int* getRow(int len)
{
    int* pRow = new int[len];
    return pRow;
}

int** getM(int r, int c)
{
    int** ppM = new int* [r];
    for (int i = 0; i < c; i++)
        ppM[i] = getRow(r);
    return ppM;
}

void fillM(int** pMatr, int r, int c)
{
    static int counter = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            pMatr[i][j] = counter++;
        }
    }
}

void printM(int** pMatr, int r, int c, char name)
{
    cout << "Matrix " << name << " :" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << pMatr[i][j] << " ";
        }
        cout << endl;
    }
}

int** sumMatr(int** pM1, int** pM2, int rows, int cols)
{
    int** pMatrSum = getM(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            pMatrSum[i][j] = pM1[i][j] + pM2[i][j];
        }
    }
    return pMatrSum;
}
