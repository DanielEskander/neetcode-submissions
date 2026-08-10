class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int j = digits.size() - 1;
        while(j >= 0 && carry > 0){
            digits[j] += carry;
            carry = digits[j] / 10;
            digits[j] %= 10;
            j--;
        }

        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
