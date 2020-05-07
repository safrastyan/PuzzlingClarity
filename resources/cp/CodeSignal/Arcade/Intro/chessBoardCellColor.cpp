bool chessBoardCellColor(std::string cell1, std::string cell2) 
{
    return (int(cell1[0] - 'A') + int(cell1[1] - '0')) % 2 == (int(cell2[0] - 'A') + int(cell2[1] - '0')) % 2;
}
