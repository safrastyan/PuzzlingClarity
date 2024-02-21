class OrderedStream {
public:
    OrderedStream(int n): m_data(n, "") {
        
    }
    
    vector<string> insert(int idKey, string value) {
        if (m_data.size() == 1) {
            return {value};
        }
        m_data[idKey - 1] = value;
        
        if (idKey == m_data.size()) {
            for (int i = 0; i < idKey; ++i) {
                if (m_data[i].empty()) {
                    return {};
                }
            }
            
        }
        
        for (int i = 0; i < idKey && idKey != 1; ++i) {
            if (m_data[i].empty()) {
                return {};
            }
        }
        std::vector<std::string> res{m_data[idKey - 1]};
        
        for (int i = idKey; i < m_data.size(); ++i) {
            if (m_data[i].empty()) {
                break;
            }
            res.push_back(m_data[i]);
        }
        return res;
    }

private:
    std::vector<std::string> m_data;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */