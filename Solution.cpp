
#include <array>
using namespace std;

class Solution {
    
    inline static const array<array<char, 2>, 5> strobogrammaticPairs { 
        array<char, 2>
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'8', '8'},
        {'9', '6'} };
        
public:
    vector<string> findStrobogrammatic(int targetNumberOfDigits) {
        return findStrobogrammaticNumber(targetNumberOfDigits, targetNumberOfDigits);
    }
    
private:
    vector<string> findStrobogrammaticNumber(int currentNumberOfDigits, int targetNumberOfDigits) {
        if (currentNumberOfDigits == 0) {
            return vector<string>{""};
        }
        if (currentNumberOfDigits == 1) {
            return vector < string>{"0", "1", "8"};
        }
        vector<string> priorStrobogrammatic = findStrobogrammaticNumber(currentNumberOfDigits - 2, targetNumberOfDigits);
        vector<string> currentStrobogrammatic;

        for (const auto& previous : priorStrobogrammatic) {
            for (const auto& pair : strobogrammaticPairs) {
                if (pair[0] != '0' || currentNumberOfDigits < targetNumberOfDigits) {
                    currentStrobogrammatic.push_back(pair[0] + previous + pair[1]);
                }
            }
        }
        return currentStrobogrammatic;
    }
};
