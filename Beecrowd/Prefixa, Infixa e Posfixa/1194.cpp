#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Node{
    Node * left;
    Node * right;
    char value;
};

Node * tree(Node * n,vector<char> i, vector<char> p) {
    if(i.size()==0)
    return nullptr;
    if(p.size()==0)
    return nullptr;
    n->value = p[0];
    auto it= find(i.begin(), i.end(), n->value);
    int m = distance(i.begin(), it);
    
    vector<char> novo_i_l(i.begin(), i.begin() + m);
    vector<char> novo_p_l(p.begin()+1, p.begin()+m+1); // conhecendo m é possível pegar só a quantidade m necessária para o pre order

    Node * node_l = new Node;
    n->left = tree(node_l,novo_i_l,novo_p_l);

    vector<char> novo_i_r(i.begin() + m +1 ,i.end());
    vector<char> novo_p_r(p.begin()+m+1 , p.end());
    Node * node_r = new Node;
    n->right = tree(node_r,novo_i_r,novo_p_r);
    return n;

}

void printPostorder(Node* node)
{
    if (node == NULL)
        return;
 
    // First recur on left subtree
    printPostorder(node->left);
 
    // Then recur on right subtree
    printPostorder(node->right);
 
    // Now deal with the node
    cout << node->value;
}

int main(){
    int c;
    cin>>c;
    for(int t=0;t<c;t++){
        vector<char> prefixa,infixa;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            char node;
            cin>>node;
            prefixa.push_back(node);
        }
        for(int i=0;i<n;i++){
            char node;
            cin>>node;
            infixa.push_back(node);
        }
        Node * node = new Node;
        tree(node,infixa,prefixa);
        printPostorder(node);
        cout<<endl;
        }



    return 0;
}
