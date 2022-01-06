#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <random>

using namespace std;

void print_matrix(const vector<vector<int> >& m)
{
    for (const auto& x : m)
    {
        for (const auto& y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

vector<vector<int> > rotate_matrix(const vector<vector<int> >& input, int r, int c)
{
    vector<vector<int> > result;
    for (int i = 0; i < c; ++i)
    {
        result.push_back({});
        for (int j = 0; j < r; ++j)
        {
            result[i].push_back(-1);
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            result[j][r-i-1] = input[i][j];
        }
    }
    
    return result;
}

void rotate_matrix_in_place(vector<vector<int> >& input, int s)
{
    for (int i = 0; i < s; i = i + 2)
    {
        // int i = 0;
        for (int j = i/2; j < s - i/2 - 1; ++j)
        {
            int lu = input[i/2][j];
            int ru = input[j][s - i/2 - 1];
            int rd = input[s - i/2 - 1][s - j - 1];
            int ld = input[s - j - 1][i/2];

            input[j][s - i/2 - 1] = lu;
            input[s - i/2 - 1][s - j - 1] = ru;
            input[s - j - 1][i/2] = rd;
            input[i/2][j] = ld;

        }
    }
}

int main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(10,99);

    int r = 5;
    int c = 5;

    vector<vector<int> > matrix;
    for (int i = 0; i < r; ++i)
    {
        matrix.push_back({});
        for (int j = 0; j < c; ++j)
        {
            matrix[i].push_back(dist6(rng));
        }
    }

    cout << "Not in place method:" << endl;
    print_matrix(matrix);
    cout << "rot 90 deg: " << endl;
    print_matrix(rotate_matrix(matrix, r, c));

    cout << endl;

    cout << "in place method:" << endl;
    print_matrix(matrix);
    cout << endl;
    cout << "rot 90 deg: " << endl;
    rotate_matrix_in_place(matrix, r);
    print_matrix(matrix);

    return 0;
}

/* 
NOTES
 */