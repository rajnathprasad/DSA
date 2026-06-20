class Solution {
public:
    bool isSub(string &a, string &b){
        return a.find(b) != string::npos;
    }
    int repeatedStringMatch(string a, string b) {
        int count=1;
        string bigString=a;
        while(bigString.size()<b.size()){
            if(isSub(bigString,b)) return count;
            else{
                bigString+=a;
                count++;
            }
        }
        if (isSub(bigString, b)) return count;
        bigString+=a;
        count++;
        if(isSub(bigString,b)) return count;
        return -1;
    }
};