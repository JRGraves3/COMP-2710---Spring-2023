#include <iostream>
using namespace std;
    int main(void)
    {
        int test;
        int num_elems;

        cout << "How many numbers? ";
        cin >> num_elems;
        int tests[num_elems]; // make the space for data as big as the amount of allowed inputs

        for (int i = 0; i < num_elems; i++)
            {
                cout << "Please type a number: ";
                cin >> test;
                tests[i]= test;
            }
        return 0;
    }
