class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string result(m + n, '0');
        int indexCounter = 0;
        int index, carry, currentNumber, sum;
        for(int i = m - 1; i >= 0; i--){
            carry = 0;
            index = m + n - 1 - indexCounter;
            currentNumber = num1[i] - '0';
            for(int j = n - 1; j >= 0; j--){
                sum = (num2[j] - '0')*currentNumber + carry + result[index] - '0';
                carry = sum / 10;
                result[index] = (char)(sum % 10 + '0');
                index--;
            }
            while(carry > 0){
                sum = result[index] - '0' + carry;
                carry = sum / 10;
                result[index] = (char)(sum % 10 + '0');
                index--;
            }
            indexCounter++;
        }
        int lastZeroIndex = 0;
        while(lastZeroIndex < m + n && result[lastZeroIndex] == '0'){
            lastZeroIndex++;
        }
        if(lastZeroIndex == m + n){
            return "0";
        }
        return string(result.begin() + lastZeroIndex, result.end());
    }
};

