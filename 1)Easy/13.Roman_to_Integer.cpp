class Solution {
public:
    int romanToInt(string s) {

        int sum = 0;

        for(int i = s.size(); i >= 0; i--){
            
            if(s[i] == 'I'){

                if(i < s.size() - 1){

                    if(s[i + 1] == 'V' || s[i + 1] == 'X'){

                        sum -= 1;

                    }else {

                        sum += 1;

                    }

                }else{

                    sum += 1;

                }
                std::cout<<i;
            
            }
            if(s[i] == 'V'){

                sum += 5;

            }
            if(s[i] == 'X'){

                if(i < s.size() - 1){

                    if(s[i + 1] == 'L' || s[i + 1] == 'C'){

                        sum -= 10;

                    }else {

                        sum += 10;

                    }

                }else{

                    sum += 10;

                }

            }
            if(s[i] == 'L'){

                sum += 50;

            }
            if(s[i] == 'C'){

                if(i < s.size() - 1){

                    if(s[i + 1] == 'D' || s[i + 1] == 'M'){

                        sum -= 100;

                    }else {

                        sum += 100;

                    }

                }else{

                    sum += 100;

                }

            }
            if(s[i] == 'D'){

                sum += 500;

            }
            if(s[i] == 'M'){

                sum += 1000;

            }


        }
        
        return sum;

    }
};