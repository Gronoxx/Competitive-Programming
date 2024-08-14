#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Perm(const string& text, const vector<int>& perm) {
    string result(text.size(), ' ');
    for (size_t i = 0; i < perm.size(); ++i) {
        result[i] = text[perm[i] - 1];
    }
    return result;
}

vector<int> invPerm(const vector<int>& perm) {
    vector<int> inv(perm.size());
    for (size_t i = 0; i < perm.size(); ++i) {
        inv[perm[i] - 1] = i + 1;
    }
    return inv;
}

vector<int> PermVet(const vector<int>& v, const vector<int>& perm) {
    vector<int> result(v.size());
    for (size_t i = 0; i < perm.size(); ++i) {
        result[i] = v[perm[i] - 1];
    }
    return result;
}

vector<int> matrixExponentiation(const vector<int>& perm, unsigned long long M) {
    vector<int> result(perm.size());
    vector<int> base = perm;

    for (size_t i = 0; i < perm.size(); ++i) {
        result[i] = i + 1; 
    }

    vector<int> origin = result;
    unsigned long long originalM = M;
    unsigned long long cycleLength = 0;

    while (M > 0) {
        if (M % 2 == 1) {
            result = PermVet(result, base);
        }
        base = PermVet(base, base);
        M /= 2;
    }

    return result;
}

string decryptText(int N, unsigned long long M, const vector<int>& perm, const string& encryptedText) {
    vector<int> inv = invPerm(perm);
    vector<int> exp = matrixExponentiation(inv, M);
    return Perm(encryptedText, exp);
}

int main() {

    int N;
    unsigned long long M;
    
    while (cin >> N >> M) {

        if (N == 0 && M == 0) {
            break;
        }

        vector<int> permutation(N);
        for (int i = 0; i < N; ++i) {
            cin >> permutation[i];
        }

        cin.ignore();  

        string input;
        getline(cin, input);  

        string origin = decryptText(N, M, permutation, input);
        cout << origin << endl;
    }

    return 0;
}
