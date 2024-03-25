#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    while (nums1.size() > m) nums1.pop_back();

    auto it = nums1.begin();
    for (int x : nums2) {
        bool did_break = false;
        while (it != nums1.end()) {
            if (x < *it) {
                nums1.insert(it, x);
                did_break = true;
                break;

            } else {
                it++;

            }

        }

        if (!did_break) nums1.push_back(x);
    }

}
