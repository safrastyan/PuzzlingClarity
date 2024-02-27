class CustomStack {
public:
    CustomStack(int maxSize): m_data()
                            , m_max(maxSize) {
        
    }
    
    void push(int x) {
        if (m_data.size() >= m_max) {
            return;
        }
        m_data.push_back(x);

    }
    
    int pop() {
        if (m_data.empty()) {
            return -1;
        }
        auto t = m_data.back();
        m_data.pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < std::min(k, static_cast<int>(m_data.size())); ++i) {
            m_data[i] += val;
        }
    }

private:
    std::vector<int> m_data;
    int m_max;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */