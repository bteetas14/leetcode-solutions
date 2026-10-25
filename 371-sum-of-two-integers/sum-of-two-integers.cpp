class Solution {
public:
    int getSum(int a, int b) {
        unsigned int x = a;
        unsigned int y = b;

        while (y != 0) {
            unsigned int sum = x ^ y;
            unsigned int carry = (x & y) << 1;

            x = sum;
            y = carry;
        }

        return static_cast<int>(x);
    }
};