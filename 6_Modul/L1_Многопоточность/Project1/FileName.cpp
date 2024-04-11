// numeric_accum.cpp
// compile with: /EHsc
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

int main()
{
    using namespace std;

    vector <int> v1, v2(20);
    vector <int>::iterator iter1, iter2;

    int i;
    for (i = 1; i < 21; i++)
    {
        v1.push_back(i);
    }

    cout << "The original vector v1 is:\n ( ";
    for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
        cout << *iter1 << " ";
    cout << ")." << endl;

    // The first member function for the accumulated sum
    int total;
    total = accumulate(v1.begin(), v1.end(), 0);

    cout << "The sum of the integers from 1 to 20 is: "
        << total << "." << endl;

    // Constructing a vector of partial sums
    int j = 0, partotal;
    for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
    {
        partotal = accumulate(v1.begin(), iter1 + 1, 0);
        v2[j] = partotal;
        j++;
    }

    cout << "The vector of partial sums is:\n ( ";
    for (iter2 = v2.begin(); iter2 != v2.end(); iter2++)
        cout << *iter2 << " ";
    cout << ")." << endl << endl;

    // The second member function for the accumulated product
    vector <int> v3, v4(10);
    vector <int>::iterator iter3, iter4;

    int s;
    for (s = 1; s < 11; s++)
    {
        v3.push_back(s);
    }

    cout << "The original vector v3 is:\n ( ";
    for (iter3 = v3.begin(); iter3 != v3.end(); iter3++)
        cout << *iter3 << " ";
    cout << ")." << endl;

    int ptotal;
    ptotal = accumulate(v3.begin(), v3.end(), 1, multiplies<int>());

    cout << "The product of the integers from 1 to 10 is: "
        << ptotal << "." << endl;

    // Constructing a vector of partial products
    int k = 0, ppartotal;
    for (iter3 = v3.begin(); iter3 != v3.end(); iter3++) {
        ppartotal = accumulate(v3.begin(), iter3 + 1, 1, multiplies<int>());
        v4[k] = ppartotal;
        k++;
    }

    cout << "The vector of partial products is:\n ( ";
    for (iter4 = v4.begin(); iter4 != v4.end(); iter4++)
        cout << *iter4 << " ";
    cout << ")." << endl;
}