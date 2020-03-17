class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        std::vector<std::string> table = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        std::set<std::string> codes;
        
        for (auto& w : words) {
            std::string result;
            for (int i = 0; i < w.size(); ++i) {
                result += table[w[i] - 'a'];
            }
            codes.insert(result);
        }
        
        return codes.size();
        
    }
};