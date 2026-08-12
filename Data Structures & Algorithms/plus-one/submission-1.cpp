class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int idx = digits.size() - 1;
        while(idx > -1 && carry > 0){
            digits[idx] += carry;

            carry = digits[idx] / 10;
            digits[idx] %= 10;
            idx--;
        }
        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
