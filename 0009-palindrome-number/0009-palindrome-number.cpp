class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10; 
            x /= 10; // Remove last digit
        }

        // Compare reversed half with the remaining half of the number
        return x == reversedHalf || x == reversedHalf / 10;
    }
};