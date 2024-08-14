class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> m; // Mapa de contagem de caracteres de t
    for (char c : t) {
        m[c]++;
    }

    unordered_map<char, int> m2; // Mapa de contagem de caracteres da janela atual
    int start = 0, count = 0, minLen = INT_MAX, minStart = 0;
    int size = s.size(), t_size = t.size();

    for (int i = 0; i < size; i++) {
        m2[s[i]]++;
        
        // Verifica se este caractere está em t e está na quantidade necessária
        if (m.find(s[i]) != m.end() && m2[s[i]] <= m[s[i]]) {
            count++;
        }

        // Quando todos os caracteres necessários estão na janela
        while (count == t_size) {
            // Atualiza a menor janela se necessário
            if (i - start + 1 < minLen) {
                minLen = i - start + 1;
                minStart = start;
            }

            m2[s[start]]--;
            // Reduz o contador se o caractere de início é necessário
            if (m.find(s[start]) != m.end() && m2[s[start]] < m[s[start]]) {
                count--;
            }
            start++;
        }
    }

    if (minLen == INT_MAX) {
        return ""; // Se não encontramos nenhuma janela válida
    }

    return s.substr(minStart, minLen); // Retorna a menor janela encontrada
}
};
