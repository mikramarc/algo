#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> merge(const vector<int>& list_1, const vector<int>& list_2)
{
    vector<int> result;

    int i = 0;
    int j = 0;

    while (i < list_1.size() && j < list_2.size())
    {
        if (list_1[i] <= list_2[j])
        {
            result.push_back(list_1[i]);
            i++;
        }
        else
        {
            result.push_back(list_2[j]);
            j++;
        }
    }

    for (i; i < list_1.size(); ++i)
    {
        result.push_back(list_1[i]);
    }

    for (j; j < list_2.size(); ++j)
    {
        result.push_back(list_2[j]);
    }

    return result;
}

int main()
{
    vector<int> list_1 = {1, 3, 6, 8};
    vector<int> list_2 = {2, 4, 5, 9, 10};

    auto result = merge(list_1, list_2);
    for (const auto& x : result)
    {
        cout << x << endl;
    }

    return 0;
}