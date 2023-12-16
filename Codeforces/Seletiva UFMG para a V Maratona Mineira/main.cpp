    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    int BinarySearch(vector<double>arr, int l, int r, double x,bool L)
    {
        if(r==0){
            if(L==0){
                if(arr[0]<x)
                return 0;
                else
                return 1;
                }
                else{
                if(arr[0]<=x)
                return 1;
                else
                return 0;
                }
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            // Check if x is present at mid
            if (arr[m] == x)
                return m;
    
            // If x greater, ignore left half
            if (arr[m] < x)
                l = m + 1;
    
            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
            
        // If we reach here, then element was not present
        return l;
    }


    int main(){
        int n;  
        cin>>n;
        vector<double> L_I;
        vector<double> L_S;
        int app=0;
        for(int i=0;i<n;i++){
            int a1,a2;
            cin>>a1;
            cin>>a2;
            if(a1<60 && a2<60){ //reprovado
                continue;
            }
            else if(a1>60 && a2>60){
                app++;
                continue;
            }
            else if(a1<60){
                L_S.push_back((6000-(a2*100))/(a1-a2)); //(p+1)
            }else{
                L_I.push_back((6000-(a2*100))/(a1-a2)); //(n-p)
            }
        }
        int total=0;
        std::sort(L_I.begin(), L_I.end(), std::greater<int>());
        std::sort(L_S.begin(), L_S.end(), std::greater<int>());

        if(L_S.size()>L_I.size()){
            for(int i=0;i<L_I.size();i++){
                int atual=0;
                atual = (n - i);
                atual += (BinarySearch(L_S,0,L_S.size()-1,L_I[i],0));
                total = max(total,atual);           
            }
        }else{
            for(int i=0;i<L_S.size();i++){
                int atual=0;
                atual = (i+1);
                atual += (BinarySearch(L_I,0,L_I.size()-1,L_S[i],1));
                total = max(total,atual);           
            }
        }

        cout<<total+app<<endl;



    return 0;
    }