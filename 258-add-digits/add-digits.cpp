class Solution {
public:
    int addDigits(int num) {

        int x=num;
        int t=x;
        int sum=0,rem=0;
       while (x>0){
            rem = x%10;
            sum += rem;
            x /= 10;
        }
        if(sum <10)
        return sum;
        else
        return addDigits(sum);
    }
};