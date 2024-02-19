class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small): m_data{big, medium, small} {
        
    }
    
    bool addCar(int carType) {
        --carType;
        if (m_data[carType] == 0) {
            return false;
        }
        --m_data[carType];
        return true;
    }

    std::vector<int> m_data;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */