#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    private:
        unordered_map<char, int> seen;
        size_t first_index;

    public:
        Solution() {
            seen = {};
        }

        int firstUniqChar(string s) {
            for (size_t i = 0; i < s.length(); i++) {
                if (seen.count(s[i]) != 0) seen.insert_or_assign(s[i], -1);
                else seen.insert({ s[i], i });
            }

            first_index = static_cast<int>(s.length());

            for ( unordered_map<char, int>::iterator iter = seen.begin(); iter != seen.end(); iter++) {
                if (iter->second == -1) continue;

                if (iter->second < static_cast<int>(first_index)) 
                    first_index = iter->second;
            }

            // NOTE: Since there is no char at s[s.length()], we will know that all elements in hashmap were -1
            return ( first_index == s.length() ) ? -1 : first_index;
        }
};

int main(void) {
    return 0;
}
