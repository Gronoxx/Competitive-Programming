#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

//SE EU FIZER COM MATRIZ FICA MUITO MAIS FACIL E EVITA SEGMENTATION FAULT

using namespace std;


bool insideIndex (int M,int N, pair <int,int> pos_desejada){
    bool result = true;
    if(pos_desejada.second>=M || pos_desejada.second <0)
    result = false;
    if(pos_desejada.first>=N || pos_desejada.first < 0)
    result = false;

    return result;
}


bool Valid (vector<vector<int>> &tabuleiro, pair<int,int> pos_atual, pair<int,int> pos_desejada, int N, int M){

    if((pos_desejada.first == pos_atual.first + 2 || pos_desejada.first == pos_atual.first - 2 ) && (pos_desejada.second == pos_atual.second + 2 || pos_desejada.second == pos_atual.second - 2) ){
        //conferir se é uma jogada dentro das regras
    }
    else
    return false;
    if(!insideIndex(M,N,pos_desejada)) // essa jogada sai do tabuleiro?
    return false;
    if(tabuleiro[pos_desejada.first][pos_desejada.second]!=0) // o local de destino está vazio?
    return false;
    // no meio do caminho existe uma peça do oponente que vlaida o movimento?
    int aux_i,aux_j;
    if(pos_desejada.first > pos_atual.first) //subindo
    aux_i = pos_atual.first + 1;
    else //descendo
    aux_i = pos_atual.first - 1;
    if(pos_desejada.second > pos_atual.second) //direita
    aux_j = pos_atual.second + 1;
    else //esquerda
    aux_j = pos_atual.second - 1;
    if(tabuleiro[aux_i][aux_j]!=2)
    return false;
    else
    return true;
}

int BruteForce(vector<vector<int>>&tabuleiro,pair<int,int> pos_atual, int M, int N){
    int count = 0;
    pair<int,int> pos1,pos2,pos3,pos4;
    pos1 = make_pair(pos_atual.first + 2, pos_atual.second +2); //pra baixo, direita
    pos2 = make_pair(pos_atual.first - 2, pos_atual.second +2); // pra cima, direita
    pos3 = make_pair(pos_atual.first + 2, pos_atual.second -2);// pra baixo, esquerda
    pos4= make_pair(pos_atual.first - 2, pos_atual.second -2); //pra cima, esquerda
    

    
    if(Valid(tabuleiro, pos_atual,pos1, N,M)){
        tabuleiro[pos_atual.first+1][pos_atual.second+1] = 0; //come a peça do jogador
        tabuleiro[pos_atual.first][pos_atual.second] =0 ; //limpando o local q sai
        tabuleiro[pos1.first][pos1.second] = 1;
        count = max(1 + BruteForce(tabuleiro,pos1,M,N), count);
        tabuleiro[pos_atual.first+1][pos_atual.second+1] = 2; //rreverte
        tabuleiro[pos_atual.first][pos_atual.second] = 1 ; 
        tabuleiro[pos1.first][pos1.second] = 0;
    }
    if(Valid(tabuleiro,pos_atual,pos2, N,M)){
        tabuleiro[pos_atual.first-1][pos_atual.second+1] = 0; //come a peça do jogador
        tabuleiro[pos_atual.first][pos_atual.second] =0 ; //limpando o local q sai
        tabuleiro[pos2.first][pos2.second] = 1;
        count = max(1 + BruteForce(tabuleiro,pos2,M,N), count);
        tabuleiro[pos_atual.first-1][pos_atual.second+1] = 2; //reverte
        tabuleiro[pos_atual.first][pos_atual.second] =1 ; 
        tabuleiro[pos2.first][pos2.second] = 0;
    }
    if(Valid(tabuleiro, pos_atual,pos3, N,M)){
        tabuleiro[pos_atual.first+1][pos_atual.second-1] = 0; //come a peça do jogador
        tabuleiro[pos_atual.first][pos_atual.second] =0 ; //limpando o local q sai
        tabuleiro[pos3.first][pos3.second] = 1;
        count = max(1 + BruteForce(tabuleiro, pos3,M,N), count);
        tabuleiro[pos_atual.first+1][pos_atual.second-1] = 2; //reverte
        tabuleiro[pos_atual.first][pos_atual.second] =1 ; 
        tabuleiro[pos3.first][pos3.second] = 0;
    }
    if(Valid(tabuleiro,pos_atual,pos4, N,M)){
        tabuleiro[pos_atual.first-1][pos_atual.second-1] = 0; //come a peça do jogador
        tabuleiro[pos_atual.first][pos_atual.second] =0 ; //limpando o local q sai
        tabuleiro[pos4.first][pos4.second] = 1;
        count = max(1 + BruteForce(tabuleiro,pos4,M,N), count);
        tabuleiro[pos_atual.first-1][pos_atual.second-1] = 2; //reverte
        tabuleiro[pos_atual.first][pos_atual.second] =1 ; 
        tabuleiro[pos4.first][pos4.second] = 0;
    }
    return count;  

}

int main(){

    int N,M;
    while(cin>>N){
    cin>>M;
    if(N==0 && M==0)
    return 0;
    vector<vector<int>> tabuleiro (N,vector<int> (M));
    vector<pair<int,int>> minhas_pecas;
    int casas = ceil((double(N)*double(M))/2);
    int count = -1;
    bool imprimir;
    for(int i=N-1;i>=0;i--){
        count++;
        if(count%2 ==0)
        imprimir = true;
        else
        imprimir = false;
        for(int j=0;j<M;j++){
            if(imprimir){
                int aux;
                cin>>aux;
                tabuleiro[i][j] = aux;
                imprimir =false;
                if(aux==1){ //se a peça for minha eu guardo
                minhas_pecas.push_back(make_pair(i,j));
                }
            }
            else{
            tabuleiro[i][j] = -1;
            imprimir = true;
            }
        }
    }
    vector<pair<int,int>> caminho;
    int maior=0;
    for(int i =0 ; i< minhas_pecas.size();i++)
    maior = max(BruteForce(tabuleiro,minhas_pecas[i],M,N),maior);
    cout<<maior<<endl;    
    }
    
    return 0;
}
