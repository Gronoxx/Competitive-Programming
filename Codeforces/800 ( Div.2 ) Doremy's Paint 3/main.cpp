#include <iostream>
#include <vector>
#include <limits> 

using namespace std;

int main(){
    int t ,n;
    cin >> t;
    for(int test=0;test<t;test++){
        cin >> n;
        vector<int> a;
        vector<int> qntd(2,0);
        bool alr_no=false;
        bool buf=false;
        for(int numbers=0;numbers<n;numbers++){
           int aux;
           cin>>aux;    
           if(!buf){
           bool p=true;
           for(int s=0;s<a.size();s++){
                if(a[s]==aux){
                    p=false;
                    qntd[s]++;
                    break;
                }   
            }
            if(p)
            a.push_back(aux);
            if(a.size()>2){
                cout<<"No"<<endl;
                alr_no =true;
                buf=true;                
            }
           }
        }

        if(!alr_no){
        if(a.size()==1){
        cout<<"Yes\n";
        }
        if(n%2==1 && a.size()!=1){
        if(qntd[0]-qntd[1]==1 || qntd[0]-qntd[1]==-1)
        cout<<"Yes\n";
        else
        cout<<"No\n";
        }
        if(n%2==0 && a.size()!=1){
        if(qntd[0]-qntd[1]==0)
        cout<<"Yes\n";
        else
        cout<<"No\n";
        }
        }
    }
return 0;
}