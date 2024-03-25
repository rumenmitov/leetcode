#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'sortProductCodes' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING order
 *  2. STRING_ARRAY productCodes
 */

vector<string> sortProductCodes(string order, vector<string> productCodes) {
    unordered_map<char, int> order_table;
    for (unsigned long int i = 0; i < order.length(); ++i) {
        order_table[order[i]] = i + 1;
    }
    
    sort(productCodes.begin(), productCodes.end(),
        [&order_table] (string code1, string code2)->bool {
        
        size_t len = code1.length();
        if (code1.length() > code2.length()) {
            len = code2.length();
        }
        
        for (size_t i = 0; i < len; i++) {
            if (code1[i] != code2[i]) {
              return order_table[code1[i]] > order_table[code2[i]];   
            }
        }
        
        if (code1.length() <= code2.length()) return true;
        else return false;
    }
    );
    
    return productCodes;
    
}
