class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto f = ind2num.find(index);
        
        if (f == ind2num.end() || f->second == -1) {
            ind2num[index] = number;
            num2i[number].insert(index);
            return;
        }
        
        int prev = f->second;
        num2i[prev].erase(index);
        num2i[number].insert(index);
        ind2num[index] = number;
        
    }
    
    int find(int number) {
        if (num2i.find(number) == num2i.end()) {
            return -1;
        }
        if (num2i[number].size() == 0) {
            return -1;
        }
        return *num2i[number].begin();
    }
    
    std::unordered_map<int, int> ind2num;
    std::unordered_map<int, std::set<int>> num2i;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */