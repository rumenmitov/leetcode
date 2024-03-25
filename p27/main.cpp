#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();

    vector<int> ridx;
    for (int i = 0; i < n; i++) {
        if (nums[i] == val) ridx.push_back(i);
    }

    int mark = 0;
    for (int idx : ridx) {
        auto it = nums.begin() + idx - mark;
        nums.erase(it);
        mark++;
    }

    return nums.size();
}

int main(void) {
    vector<int>v {1, 2, 2, 3};
    cout << removeElement(v, 2) << endl;
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
