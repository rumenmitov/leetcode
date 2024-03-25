#include <string>
#include <sys/types.h>
#include <unordered_map>

using namespace std;

class Solution {
    private:
        unordered_map<char, int> seen;
        uint curr_len;
        uint longest_len;

    public:
        Solution() {
            seen = {};
            curr_len = longest_len = 0;
        }

        int lengthOfLongestSubstring(string s) {
            for (size_t i = 0; i < s.length(); ++i) {
                if (seen.count(s[i]) == 0) {
                    seen.insert({ s[i], i });
                    curr_len++;

                } else {
                    i = seen[ s[i] ];
                    seen.clear();

                    if (curr_len > longest_len) longest_len = curr_len;

                    curr_len = 0;
                }
            }

            if (curr_len > longest_len) longest_len = curr_len;
            return longest_len;
        }
};

int main(int argc, char** argv) {

    Solution sol;

    printf("Lenght of string '%s' = %d\n", argv[1], sol.lengthOfLongestSubstring(argv[1]));
    return 0;
}
