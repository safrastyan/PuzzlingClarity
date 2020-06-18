std::vector<int> metroCard(int lastNumberOfDays) 
{
    /// < 28 everything
    /// 28 - 31
    /// {29, 30 } -  31
    /// {31} - everything
    
    return lastNumberOfDays >= 28 && lastNumberOfDays <= 30 ? std::vector<int>{31} : std::vector<int>{28, 30, 31};
}
