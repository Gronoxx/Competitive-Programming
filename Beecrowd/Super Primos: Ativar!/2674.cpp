#include <iostream>
#include <vector>
#include <cmath>

#define rep(i,a,b) for(int i = a; a < b; a++)

using namespace std;

bool Primo(int num) {
    if (num <= 1) 
        return false;
    if (num == 2) 
        return true;
    if (num % 2 == 0) 
        return false;
    
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) 
            return false;
    }

    return true;
}

bool Super(int num) {
    while (num > 0) {
        int digit = num % 10;
        
        if (!Primo(digit)) 
            return false;
        
        num /= 10;
    }

    return true;
}

int main() {
    int N;
    
    while (cin >> N) {
    if(Primo(N)){
        if(Super(N))
            cout<<"Super"<<endl;
        else
            cout<<"Primo"<<endl;
    }
    else
        cout<<"Nada"<<endl;
    }

    return 0;
}
