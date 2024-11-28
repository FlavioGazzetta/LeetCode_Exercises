class Solution {
public:
    int reverse(int x) {

        std::string str = std::to_string(x);

        bool neg = false;

        char temp;

        if(str[0] == '-'){

            str = str.substr(1);

            neg = true;

        }

        for(int i = 0; i < str.length()/2; i++){

            temp = str[i];

            str[i] = str[str.length() - 1 - i];

            str[str.length() - 1 - i] = temp;

        }
        
        long reversedNum = std::stol(str);

        if(neg) {

            reversedNum = -reversedNum;

        }
            
        if(reversedNum < std::numeric_limits<int>::min() || reversedNum > std::numeric_limits<int>::max()) {

            return 0;

        }

        int out = reversedNum;

        return out;

    }
};