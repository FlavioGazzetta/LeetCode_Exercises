class Solution {
public:
    bool isPalindrome(int x) {

        std::string str = std::to_string(x);

        for(int i = 0; i <= str.length()/2; i ++){

            if(str[i] != str[str.length() - 1 - i]){

                return false;

            }

        }

        return true;

    }
};

//Follow up: Could you solve it without converting the integer to a string?

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers that end with 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Keep reversing the last digits until we've processed half the number
        while (x > reversedHalf) {
            // Take the last digit of x and add it to the reversed half
            reversedHalf = reversedHalf * 10 + x % 10;
            // Remove the last digit from x
            x /= 10;
        }

        // Now check if the original half matches the reversed half
        // For odd-length numbers, we ignore the middle digit by dividing reversedHalf by 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
