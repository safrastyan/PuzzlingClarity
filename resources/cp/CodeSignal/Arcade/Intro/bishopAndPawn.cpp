bool bishopAndPawn(std::string bishop, std::string pawn) 
{
    return std::abs(bishop[0] - pawn[0]) == std::abs(bishop[1] - pawn[1]);
}
