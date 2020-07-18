bool remove_pair(std::vector<std::vector<int>>& shoes)
{
    for (int i = 1; i < shoes.size(); ++i) {
        if (shoes[i][1] == shoes[0][1]) {
            if (shoes[i][0] ^ shoes[0][0] == 1) {
                shoes.erase(shoes.begin() + i);
                shoes.erase(shoes.begin());
                return true;
            }
        }
    }
    return false;
}

bool pairOfShoes(std::vector<std::vector<int>> shoes) 
{
    while (remove_pair(shoes)) {}
    return shoes.empty();  
}
