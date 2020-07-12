std::vector<int> houseOfCats(int legs) 
{
    std::vector<int> res;
    for (int i = 0; i <= legs; ++i) {
        if (legs - i * 2 < 0) {
            break;
        }
        if ( (legs - i * 2) % 4 == 0) {
            res.push_back(i);
        }
    }
    return res;
}
