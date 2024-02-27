class MyQueue {
public:
    MyQueue(): m_data() {
        
    }
    
    void push(int x) {
        m_data.push(x);
    }
    
    int peek() {
        return m_data.front();
    }
    
    int pop() {
        auto t = m_data.front();
        m_data.pop();
        return t;
    }
    
    bool empty() {
        return m_data.empty();
    }

private:
    std::queue<int> m_data;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */