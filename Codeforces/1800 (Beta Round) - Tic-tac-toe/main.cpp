#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool VictoryFinder(int inicial, int peso, int tic_tac_toe [9]){
    int value = tic_tac_toe[inicial];
    if(value==2)
    return false;
    for(int i=1;i<3;i++){
        if(value!=tic_tac_toe[inicial+(i*peso)])
        return false;
    }
    return true;
}

int main(){
    int tic_tac_toe [9]; // o 0 // x 1 // . 2
    string line;
    int count_x=0;
    int count_o=0;
    for (int i=0;i<3;i++){
    getline(cin,line);
    for (int count=0;count<3;count++){
        switch(line[count]){
        case '0': 
                tic_tac_toe[i*3+count]=0;
                count_o++;
                break;
        case 'X': 
                tic_tac_toe[i*3+count]=1;
                count_x++;
                break;
        case '.': 
                tic_tac_toe[i*3+count]=2;
                break;
        }
    }
    }
    int count_vitorias=0;
    int change_winner=0;
    int winner=0;
    int past_winner=0;
    if(VictoryFinder(0,1,tic_tac_toe)){
        past_winner=winner;
        winner = tic_tac_toe[0];
            if(winner!=past_winner)
            change_winner++;
        count_vitorias++;
    }
    if(VictoryFinder(0,3,tic_tac_toe))
    {
    past_winner=winner;
    winner = tic_tac_toe[0];
    if(winner!=past_winner)
    change_winner++;
    count_vitorias++;
    }
    if(VictoryFinder(0,4,tic_tac_toe))
    {
    past_winner=winner;
    winner = tic_tac_toe[0];
    if(winner!=past_winner)
    change_winner++;
    count_vitorias++;
    }
    if(VictoryFinder(1,3,tic_tac_toe))
    {
    past_winner=winner;
    winner = tic_tac_toe[1];
    if(winner!=past_winner)
    change_winner++;
    count_vitorias++;
    }
    if(VictoryFinder(2,2,tic_tac_toe))
    {
    past_winner=winner;
    winner = tic_tac_toe[2];
    if(winner!=past_winner)
    change_winner++;
    count_vitorias++;
    }
    if(VictoryFinder(2,3,tic_tac_toe))
    {
    past_winner=winner;
    winner = tic_tac_toe[2];
    if(winner!=past_winner)
    change_winner++;
    count_vitorias++;
    }
    if(VictoryFinder(3,1,tic_tac_toe))
    {
    past_winner=winner;
    winner = tic_tac_toe[3];
    if(winner!=past_winner)
    change_winner++;
    count_vitorias++;
    }
    if(VictoryFinder(6,1,tic_tac_toe))
    {
    past_winner=winner;
    winner = tic_tac_toe[6];
    if(winner!=past_winner)
    change_winner++;
    count_vitorias++;
    }

    if((count_vitorias>1 && change_winner>1)|| (!(count_x-count_o==0 || count_x-count_o==1)))
    cout<<"illegal"<<endl;
    else if(count_vitorias>=1){
        if(winner==1)
            if(count_x-count_o!=1){
            cout<<"illegal"<<endl;
            return 0;
            }
            else
            cout<<"the first player won"<<endl;
        else{
            if(count_x-count_o!=0){
            cout<<"illegal"<<endl;
            return 0;
            }
            else
            cout<<"the second player won"<<endl;
        }
    }
    else if(count_x==5 && count_o==4)
    cout<<"draw"<<endl;
    else if(count_x-count_o==1)
    cout<<"second"<<endl;
    else
    cout<<"first"<<endl;
    return 0;
}