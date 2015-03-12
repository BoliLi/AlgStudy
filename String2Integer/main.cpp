#include <iostream>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        int Negative = 1;
        int i = 0;
        int sum = 0;

        while(str[i] != '\0') {
            if(str[i] == '+') {
                Negative = 1;
                i++;
                continue;
            }
            if(str[i] == '-') {
                Negative = -1;
                i++;
                continue;
            }

            if(str[i] < '0' || str[i] > '9') {
                i++;
                continue;
            }

            sum *= 10;
            sum += str[i] - '0';
            if(sum < 0) {
                if(Negative == 1)
                    return 0x7fffffff;
                else
                    return -0x7fffffff;
            }
            i++;
        }
        return Negative * sum;
    }
};

int main()
{
    Solution a;
    char str[50] = "fegre-+32564gte32423";
    cout << a.atoi(str) << endl;
    return 0;
}
