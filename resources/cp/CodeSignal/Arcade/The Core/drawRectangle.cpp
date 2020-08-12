std::vector<std::vector<char>> drawRectangle(std::vector<std::vector<char>> canvas, std::vector<int> rectangle) 
{
    int y1 = rectangle[0], x1 = rectangle[1], y2 = rectangle[2], x2 = rectangle[3];
    canvas[x1][y1] = canvas[x1][y2] = canvas[x2][y1] = canvas[x2][y2] = '*';
    ///columns
    for (int i = x1 + 1; i < x2; ++i) {
        canvas[i][y1] = canvas[i][y2] = '|';
    }
    ///row
    for (int i = y1 + 1; i < y2; ++i) {
        canvas[x1][i] = canvas[x2][i] = '-';      
    }
    return canvas;
}
