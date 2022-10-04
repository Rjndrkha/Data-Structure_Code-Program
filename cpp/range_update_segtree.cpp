// find of a point and update of a range
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
vector<int> tree;

// primitive update function (recursive)
void update(int node, int node_low, int node_high, int range_low, int range_high, int value)
{
    if (node_low >= range_low && node_high <= range_high)
    {
        tree[node] += value;
        return;
    }
    if (node_high < range_low || node_low > range_high)
    {
        return;
    }
    int left_child_right = (node_low + node_high) / 2;
    update(2 * node, node_low, left_child_right, range_low, range_high, value);
    update(2 * node + 1, left_child_right + 1, node_high, range_low, range_high, value);
}

// primitive find which do find function iteratively
int find_iterative(int index, int n)
{
    int ans = tree[n + index];
    int parent = (n + index) / 2;
    for (int i = parent; i >= 1; i /= 2)
    {
        ans += tree[i];
    }
    return ans;
}

// find function which is recursive
int find_recursive(int node, int node_low, int node_high, int range_low, int range_high)
{
    if (node_low >= range_low && node_high <= range_high)
    {
        return tree[node];
    }
    if (node_high < range_low || node_low > range_high)
    {
        return 0;
    }
    int left_child_right = (node_low + node_high) / 2;
    int sum = find_recursive(2 * node, node_low, left_child_right, range_low, range_high) +
              find_recursive(2 * node + 1, left_child_right + 1, node_high, range_low, range_high);
    return sum + tree[node];
}

// function which do finding and updating in just one function
// if value == -1 that means we ave to find value [l, r] otherwise we have to update range [l, r] with value "value"
int find_update(int node, int node_low, int node_high, int range_low, int range_high, int value)
{
    if (node_low >= range_low && node_high <= range_high)
    {
        // if value != -1 that means we have to update node
        if (value != -1)
        {
            // update value of tree
            tree[node] += value;
        }
        return tree[node];
    }
    if (node_high < range_low || node_low > range_high)
    {
        return 0;
    }
    int left_child_right = (node_low + node_high) / 2;
    int sum = find_update(2 * node, node_low, left_child_right, range_low, range_high, value) +
              find_update(2 * node + 1, left_child_right + 1, node_high, range_low, range_high, value);

    return sum + tree[node];
}

void check_tree()
{
    cout << "check tree: " << endl;
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec{2, 5, 8, 9, 10, 3, 4};
    int n = vec.size();
    while (__builtin_popcount(n) != 1)
    {
        n++;
    }
    tree.resize(2 * n);
    for (int i = 0; i < (int)vec.size(); i++)
    {
        tree[n + i] = vec[i];
    }
    // check_tree();

    // update(1, 0, n - 1, 0, 2, 3);

    // cout << "value at index(find_iterative): " << find_iterative(1, n) << endl;

    // cout << "value at index(find_recursive): " << find_recursive(1, 0, n-1, 1, 1) << endl;

    cout << "value at index(find_update): " << find_update(1, 0, n-1, 0, 2, 3) << endl;
    check_tree();
    return 0;
}
