#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;
int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int s[n - 1][n - 1]; // Stores the value of k
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            m[i][j] = 0;
        }
    }
    for (i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i > j)
            {
                s[i][j] = 0;
            }
            else
            {
                s[i][j] = 1;
            }
        }
    }

    // L = chain length
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "RESULTANT MATRIX , M  =  " << endl
         << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << setw(5) << m[i][j] << setw(4);
        }
        cout << endl;
    }
    cout << endl
         << endl;
    cout << "MATRIX S =  " << endl
         << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << setw(4) << s[i][j] << setw(4);
        }
        cout << endl;
    }
    return m[1][n - 1];
}

int main()
{
    // int A[] = {5, 4, 6, 2, 7};
    int num;
    cout << "Enter the no : of matrices : "
         << " ";
    cin >> num;
    int A[num + 1];
    for (int i = 0; i < num + 1; i++)
    {
        cout << "Enter the order of the matrices one by one : "
             << " ";
        cin >> A[i];
    }
    int size = sizeof(A) / sizeof(A[0]);
    cout << "Minimum number of multiplications is  : " << MatrixChainOrder(A, size);
    return 0;
}