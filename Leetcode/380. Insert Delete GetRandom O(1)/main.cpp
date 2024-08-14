class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v={0};
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp[val]==0){
        mp[val]=v.size();
        v.push_back(val);
        return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp[val]==0){
        mp.erase(val);
        return false;
        }
        v[mp[val]] = v[v.size()-1]; //onde está val atual receberá o último elemento
        mp[v[v.size()-1]] = mp[val]; //a chave do último elemento agora é o novo index dele
        v.pop_back();//retiro o último elemento
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int aux = rand()%(v.size()-1);
        return v[aux+1];
    }

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
