bool tennisSet(int score1, int score2) 
{
    int min = std::min(score1, score2);
    int max = std::max(score1, score2);
    return (max == 6 && min < 5) || (max == 7 && min >= 5 && min < 7);
}
