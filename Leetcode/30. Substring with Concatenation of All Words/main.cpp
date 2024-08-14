class Solution {
public:
        vector<int> findSubstring(string s, vector<string>& words){
        //Setting up
        vector<int> ans;
        int size_word = words[0].size();
        int qnt_word = words.size();
        unordered_map<string,int> m;
        for(int i=0;i<qnt_word;i++){
            m[words[i]]++;
        }
        
        bool b=true;

        for(int l=0;l<size_word;l++){
            int i =0 +l; //separamos o começo de palavra
            int currWords=0;
            unordered_map m2 = m;
            while(i + ((currWords + 1) * size_word) <= s.size()){ //se for possível acrescentar uma palavra
                //formando a palavra atual
                string aux ="";
                for(int j=0;j<size_word;j++){
                    aux+= s[i+(currWords*size_word)+ j];
                }
                if(m2[aux]>0)
                m2[aux]--;
                else{
                    while(m2[aux]==0){
                        string aux2 ="";
                        for(int j=0;j<size_word;j++){
                            aux2+= s[i+j];
                        }
                        i+=size_word;
                        m2[aux2]++;
                        currWords--;
                    }
                    m2[aux]--;
                }
                currWords++;
                if(currWords==qnt_word){//completamos uma permutação
                    ans.push_back(i); //salva 
                    //atualiza
                        string aux2 ="";
                        for(int j=0;j<size_word;j++){
                            aux2+= s[i+j];
                        }
                        i+=size_word;
                        m2[aux2]++;
                        currWords--;
                } 
            }
        }
        return ans;
}
};
