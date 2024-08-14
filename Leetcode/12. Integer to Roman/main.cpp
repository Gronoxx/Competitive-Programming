class Solution {
public:
    int binarySearch(vector<int> &v,int l, int r, int x){
    int m;
    while(r>=l){
    m =l + (r-l)/2;
    if(v[m]==x)
    return m;
    else if(v[m]>x){
       r=m - 1;
    }
    else{
        l=m +1;
    }
    }
    return m;
    

}


string intToRoman(int num) {
        vector<int> v = {1,5,10,50,100,500,1000};
        vector<char> c = {'I','V','X','L','C','D','M'};
        string s;        
        int count=0;
        bool rpt =true;
        while(num>9 || rpt){
            if(num<10)
            rpt=false;
            if(num%10==4){
                if(count==0){
                    s.push_back('V');
                    s.push_back('I');
                }
                else if(count==1){
                    s.push_back('L');
                    s.push_back('X');
                }
                else if(count==2){
                    s.push_back('D');
                    s.push_back('C');
                }
            }
            else if(num%10==9){
                if(count==0){
                    s.push_back('X');
                    s.push_back('I');
                }
                else if(count==1){
                    s.push_back('C');
                    s.push_back('X');
                }
                else if(count==2){
                    s.push_back('M');
                    s.push_back('C');
                }
            }
            else{
                string s_aux= "";
                int total = pow(10,count)*(num%10);
                int aux = binarySearch(v,0,v.size()-1,total);
                while(total>0){
                if(total-v[aux]>=0){
                total -= v[aux];
                s_aux.push_back(c[aux]);
                }
                else{
                aux--;    
                }
                }
                reverse(s_aux.begin(),s_aux.end());
                s += s_aux;
            }
            count++;
            num=num/10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
