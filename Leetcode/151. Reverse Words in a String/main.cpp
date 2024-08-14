class Solution {
public:
    string reverseWords(string s) {
    string result="",aux="";
    bool first=true;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            if(aux!=""){
            if(first){
            result = aux + result;
            first=false;
            }
            else
            result = aux + " " + result ;
            aux ="";
            }
        }
        else{
            aux+=s[i];
        }
    }
     if(aux!=""){
            if(first){
            result = aux + result;
            }
            else
            result = aux + " " + result ;
     }
    return result;
}
};
