class RecentCounter {
public:
    RecentCounter(): m_data() {
        
    }
    
    int ping(int t) {
        m_data.push_back(t);
        int ans = 0;
        for (int i = m_data.size() - 1; i >= 0; --i) {
            if (t - m_data[i] <= 3000) {
                ++ans;
                continue;
            } 
            break;
        }
        return ans;
    }
    std::vector<int> m_data;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */