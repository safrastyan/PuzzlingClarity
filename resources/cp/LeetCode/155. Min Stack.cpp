class MinStack {
public:
    MinStack(): m_data()
    {
        
    }
    
    void push(int val) 
    {
        m_data.push_back(val);
    }
    
    void pop() 
    {
        m_data.pop_back();
    }
    
    int top() 
    {
        return m_data.back();
    }
    
    int getMin() 
    {
        return *std::min_element(m_data.begin(), m_data.end());
    }
private:
    std::vector<int> m_data;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */