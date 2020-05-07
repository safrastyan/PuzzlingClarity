int avoidObstacles(std::vector<int> inputArray) 
{
    for (int i = 2; i <= 1001; ++i) {
        bool worked = true;
        for (auto obs: inputArray) {
            if (obs % i == 0) {
                worked = false;
                break;
            }
        }
        if (worked) {
            return i;
        }
    }
    return -1;
}
