class Solution {
public:
    bool isUpperCase(char ch){
        if(ch >='A' && ch <= 'Z') return true;
        return false;
    }
    bool detectCapitalUse(string word) {
        bool AllCapital = true;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(!isUpperCase(word[i])) AllCapital = false;
        }
        
        bool NoneCapital = true;
        for(int i=0;i<n;i++){
            if(isUpperCase(word[i])) NoneCapital = false;
        }
        bool OnlyCapital = false;
        if(isUpperCase(word[0])) OnlyCapital = true;
        if(OnlyCapital){
            for(int i=1;i<n;i++){
                if(isUpperCase(word[i])) OnlyCapital = false;
            }
        }
        cout<<"AC: "<<AllCapital<<"NC: "<<NoneCapital<<"OC: "<<OnlyCapital<<endl;
        if(OnlyCapital || AllCapital || NoneCapital) return true;
        return false;
    }
};
