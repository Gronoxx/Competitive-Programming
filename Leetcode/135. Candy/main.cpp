class Solution {
public:
int fun(vector<int> &ratings,vector<int> &v, vector<int>& values, int min,int i){
    if(i>=ratings.size()){
        return -1;
    }
    if(ratings[i]==min || v[i]==0){
    values[i]=1;
    }
    else if(v[i]==1){
        values[i] = values[i-1] + 1;
        fun(ratings,v,values,min,i+1);
    }
    else if(v[i]==2){
        values[i] = 1 + fun(ratings,v,values,min,i+1);
    }
    else{
        values[i] = max(values[i-1],fun(ratings,v,values,min,i+1)) +1;
    }
    return values[i];
}

int candy(vector<int>& ratings) {
    if(ratings.size()==1)
    return 1;
    vector<int> v (ratings.size()); //0 = nada, 1= esquerda, 2 =direita, 3 = esquerda e direita
    vector<int> parada;
    parada.push_back(0);
    if(ratings[0]>ratings[1])
    v[0]=2;
    else{
    v[0]=0;
    parada.push_back(1);
    }
    
    if(ratings[ratings.size()-1]>ratings[ratings.size()-2])
    v[v.size()-1] = 1;
    else
    v[v.size()-1]= 0;

    int min=ratings[0];
    for(int i=1;i<ratings.size()-1;i++){
        if(ratings[i]>ratings[i-1] && ratings[i]>ratings[i+1])
        v[i]=3;
        else if(ratings[i]>ratings[i-1])
        v[i]=1;
        else if(ratings[i]>ratings[i+1])
        v[i]=2;
        else{
        v[i]=0;
        parada.push_back(i+1);
        }
        if(ratings[i]<min)
        min=v[i];
    }
    if(ratings[ratings.size()-1]<min)
    min = ratings[ratings.size()-1];
    int i=0;
    vector<int> values(ratings.size());
    for(int j=0;j<parada.size();j++){
        i=parada[j];
        fun(ratings,v,values,min,i);
    }
    fun(ratings,v,values,min,i+1);
    int result=0;
    for(int k=0;k<values.size();k++){
        result+=values[k];
    }
    return result;
}

};
