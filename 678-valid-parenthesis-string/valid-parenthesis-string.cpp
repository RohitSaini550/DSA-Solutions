// class Solution {
// public:
//     bool fn(string &s , int idx , int cnt , int n){
//         if(cnt < 0) return false;
//         if(idx == n){
//             return (cnt == 0);
//         }
//         if(s[idx] == '(') return fn(s , idx + 1, cnt + 1, n);
//         if(s[idx] == ')') return fn(s , idx + 1, cnt - 1, n);
//         if(s[idx] == '*'){
//             return (fn(s, idx + 1, cnt + 1 , n) || fn(s , idx + 1, cnt - 1,n) || fn(s, idx + 1, cnt , n));
//         }
//         return false;
//     }
//     bool checkValidString(string s) {
//         int cnt = 0;
//         int n = s.length();
//         bool check = fn(s, 0, cnt , n);
//         return check;
//     }
// };



class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();

        int mini = 0;
        int maxi = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                mini++;
                maxi++;
            }
            else if(s[i] == ')'){
                // int minusMini = mini;
                // int minusMaxi = maxi;
                // minusMini--;
                // minusMaxi--;
                // if(minusMini >= 0) mini = 
                if(mini >= 1) mini--;
                // if(maxi >= 1) maxi--;
                maxi--;
                if(maxi < 0) return false;
            }
            else if(s[i] == '*'){
                int minNum = mini;
                int maxNum = maxi;
                for(int j = -1; j <= 1; j++){
                    minNum += j;
                    if(minNum >= 0) mini = min(minNum , mini);
                    // maxNum += j;
                    // if(maxNum >= 0) maxi = max(maxNum , maxi);
                }
                maxi++;
            }
        }
        if(mini == 0) return true;
        else return false;
    }
};