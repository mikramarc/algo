#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

int binary_search(const vector<int>& vec, int target, int start, int end)
{

    if (end >= start)
    {
        int middle = (end - start)/2 + start;
        
        if (vec[middle] == target)
        {
            return middle;
        }

        if (vec[middle] > target)
        {
            return binary_search(vec, target, start, middle - 1);
        }
        else if (vec[middle] < target)
        {
            return binary_search(vec, target, middle + 1, end);
        }
    }

    return -1;
}

int binary_search_2(const vector<int>& vec, int target)
{
    int middle;
    int start = 0;
    int end = vec.size() - 1;

    while (end >= start)
    {
        middle = (end - start)/2 + start;
        
        if (vec[middle] == target)
        {
            return middle;
        }

        if (vec[middle] > target)
        {
            end = middle - 1;
        }
        else if (vec[middle] < target)
        {
            start = middle + 1;
        }
    }

    return -1;
}


int main()
{
    vector<int> input = {-1,0,3,5,9,12};

    int start = 0;
    int end = input.size() - 1;

    cout << binary_search_2(input, 3) << endl;

    return 0;
}