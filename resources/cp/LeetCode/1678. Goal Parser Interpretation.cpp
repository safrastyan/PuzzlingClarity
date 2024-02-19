class Solution {
public:
    string interpret(string command) {
        std::string res;
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                res.push_back('G');
                continue;
            }
            if(command[i + 1] == ')') {
                res.push_back('o'); 
                ++i;
                continue;
            }
            i += 3;
            res += "al";
        }
        return res;
    }
};