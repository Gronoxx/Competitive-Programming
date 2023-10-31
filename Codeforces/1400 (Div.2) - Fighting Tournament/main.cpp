/*
Burenka is about to watch the most interesting sporting event of the year — a fighting tournament organized by her friend Tonya.

n
 athletes participate in the tournament, numbered from 1
 to n
. Burenka determined the strength of the i
-th athlete as an integer ai
, where 1≤ai≤n
. All the strength values are different, that is, the array a
 is a permutation of length n
. We know that in a fight, if ai>aj
, then the i
-th participant always wins the j
-th.

The tournament goes like this: initially, all n
 athletes line up in ascending order of their ids, and then there are infinitely many fighting rounds. In each round there is exactly one fight: the first two people in line come out and fight. The winner goes back to the front of the line, and the loser goes to the back.

Burenka decided to ask Tonya q
 questions. In each question, Burenka asks how many victories the i
-th participant gets in the first k
 rounds of the competition for some given numbers i
 and k
. Tonya is not very good at analytics, so he asks you to help him answer all the questions.

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers n
 and q
 (2≤n≤105
, 1≤q≤105
) — the number of tournament participants and the number of questions.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — the array a
, which is a permutation.

The next q
 lines of a test case contain questions. Each line contains two integers i
 and k
 (1≤i≤n
, 1≤k≤109
) — the number of the participant and the number of rounds.

It is guaranteed that the sum of n
 and the sum of q
 over all test cases do not exceed 105
.

Output
For each Burenka's question, print a single line containing one integer — the answer to the question.
*/

/*Ideia inicial:
Vamos usar uma pilha na ordem descrescente, de forma que os dois menores que estariam no começo da fila do enunciaasdo serão os ultimo a entrar
na nossa pilha e logo os primeiros a sairem. O vencedor é adicionado na pilha sendo o proximo primeira a sair, representrando a entrada dele no
inicio da fila do enunciado
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <utility>
#include <map>


auto compareByFirstPair = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    };

int main(){
    int t=0;
    std::cin>>t;
    for(int count=0;count<t;count++){
    int n=0;
    int q=0;
    std::cin>>n;
    std::cin>>q;
    std::stack<std::tuple<int,int>> s;
    std::vector<int> participantes(n);
    
    for(int i=0;i<n;i++){
        std::cin>>participantes[i];
    }
    for(int i=participantes.size()-1;i>=0;i--){
        s.push(std::make_tuple(i,participantes[i]));
    }
    std::vector<std::tuple<int,int>> info_q; // para não termos que guardar a informação de todos os participantes em todos os round vamos
                                             // armazenar quais são as informaçãoes que realmente precisamos
    std::map<int, std::unordered_map<int, int>> id_round_Order; //Iremos usar como chave o id e o round, pois o mesmo id pode ser perguntado em diferentes rounds e vice versa
    std::unordered_map<int,int> id_v_atual; // vai guardar quantas vitorias o id tem ate aquele momento
    std::vector<bool> monitorados(n);
    for(int i=0;i<q;i++){
       int aux_i=0;
       int aux_k=0;
       std::cin>>aux_i;
       aux_i--; // apenas para ficar de acordo com o vetor de tamnho n
       if(monitorados[aux_i]==false){
       monitorados[aux_i]=true; // usaremos para saber em O(1) se precisamos computar ou não
       id_v_atual[aux_i]=0;
       }
       std::cin>>aux_k;
       id_round_Order[aux_i][aux_k]=i;
       info_q.push_back(std::make_tuple(aux_i,aux_k));        
    }
    std::sort(info_q.begin(), info_q.end(), [](const auto& a, const auto& b) {
        return std::get<1>(a) < std::get<1>(b);
    });
    std::vector<std::pair<int,int>> output; //segura a ordem de saida e o valor que deve ser impresso
    int i_atual=std::get<0>(info_q[0]);
    int k_atual=std::get<1>(info_q[0]);
    int count_q=0;
    for(int i=1;i<n;i++) //são no total n-1 rounds, porque sempre eliminamos um competidor
    { 
        //quero a para no k_atual e informar quantas vitorias o i_atual tem
        //para encontrar o i_atual e quantas vitorias ele possui usaremos busca binaria
        std::tuple<int,int> p_participante = s.top();
        s.pop();
        std::tuple<int,int> s_participante = s.top();
        s.pop();
        int p_1=std::get<1>(p_participante);
        int p_0=std::get<0>(p_participante);
        int s_0=std::get<0>(s_participante);
        int s_1=std::get<1>(s_participante);
        if(p_1>s_1){
            s.push(p_participante);
            if(monitorados[p_0]){
                id_v_atual[p_0]++;
            }
        }
        else{
            s.push(s_participante);
            if(monitorados[s_0]){
                id_v_atual[s_0]++;
            }
        }
        while(i==k_atual){// e possivel que mais de um indice seja perguntado para o mesmo round
            output.push_back(std::make_pair(id_round_Order[i_atual][k_atual],id_v_atual[i_atual])); //a ordem do output e o valor atual de vitorias, não podemos utilizar o vetor de id, pois pode ser perguntado o valor de vitorias do mesmo i para k diferentes 
            count_q++;
            if(count_q==info_q.size())
            break;
            k_atual=std::get<1>(info_q[count_q]);
            i_atual=std::get<0>(info_q[count_q]);
        }
        if(i==n-1){ //se já passamos por todos os rounds, ja temos toda informação que precisamoss apra computar aqueles cujo k é superior a n-1
        while(k_atual>n-1){ //podemos ter mais de um k superior a n-1 e aplicamos a mesma logica para cada um deles
            std::tuple<int,int> vencedor = s.top();
            if(i_atual==std::get<0>(vencedor)){// se ele for o vencedor iremos somar, pois todo round excedente ele ganha dele mesmo
            int aux= k_atual - (n-1);
            output.push_back(std::make_pair(id_round_Order[i_atual][k_atual],id_v_atual[i_atual]+aux));;  
            }
            else{
            output.push_back(std::make_pair(id_round_Order[i_atual][k_atual],id_v_atual[i_atual]));
            } 
            count_q++;
            if(count_q==info_q.size())
            break;   
            k_atual=std::get<1>(info_q[count_q]);
            i_atual=std::get<0>(info_q[count_q]);
        }
        }
    }
    std::sort(output.begin(), output.end(), compareByFirstPair);
    for(int j=0;j<output.size();j++){
        std::cout<<output[j].second<<std::endl;
    }
    }
    return 0;
}