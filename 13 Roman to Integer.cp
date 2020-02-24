class Solution {
public:
    int romanToInt(string s) {
        int answer=0;
        
        for (int k=0; k<s.length(); k++) {
        char rom1 = s[k];
        char rom2 = s[k+1];


        switch (rom1) {
            case 'I':
            answer += 1;
                break;

            case 'V':
            answer += 5;
                break;

            case 'X':
            answer += 10;
                break;

            case 'L':
            answer += 50;
                break;

            case 'C':
            answer += 100;
                break;

            case 'D':
            answer += 500;
                break;

            case 'M':
            answer += 1000;
                break;
        }
        
        if (rom1=='I' && rom2=='V')
            answer -=2;
        if (rom1=='I' && rom2=='X')
            answer -=2;
        if (rom1=='X' && rom2=='L')
            answer -=20;
        if (rom1=='X' && rom2=='C')
            answer -=20;
        if (rom1=='C' && rom2=='D')
            answer -=200;
        if (rom1=='C' && rom2=='M')
            answer -=200;
        
        }
return answer;
    }
    
};
