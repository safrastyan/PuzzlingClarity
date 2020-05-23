int chessKnight(std::string cell) 
{
    int px[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int py[] = {2, 1, -1 , -2, -2, -1, 1, 2};
    int x = cell[0] - 'a';
    int y = cell[1] - '1';
    int res = 0;
    for (int i = 0; i < 8; ++i) {
        int newX = x + px[i];
        int newY = y + py[i];
        if (newX >= 0 && newY >= 0 && newX <= 7 && newY <= 7) {
            ++res;
        }
    }

    return res;
}
