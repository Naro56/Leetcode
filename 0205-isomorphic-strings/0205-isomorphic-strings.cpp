// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {

//         unordered_map<char, int> sMap ;
//         unordered_map<char , int> tMap ;

//         for( int i = 0; i <s.size(); i++ ){
//             sMap[t]++;
//         }
//          for( int i = 0; i <t.size(); i++ ){
//             tMap[it]++;
//         }
        
        
//     }
// };

#include <string>
#include <vector>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        // Stores the last seen position (index + 1) of characters
        int mapS[256] = {0};
        int mapT[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            // Get ASCII values
            unsigned char charS = s[i];
            unsigned char charT = t[i];

            // If their last recorded positions don't match, mapping is broken
            if (mapS[charS] != mapT[charT]) {
                return false;
            }

            // Record current position (using i + 1 to distinguish from initial 0)
            mapS[charS] = i + 1;
            mapT[charT] = i + 1;
        }

        return true;
    }
};
