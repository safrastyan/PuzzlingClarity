std::vector<std::vector<int>> spiralNumbers(int n) 
{
    int di = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int x = 0, y = 0;
    int cur_num = 2;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));
    a[0][0] = 1;
    while (true) {
        if (cur_num == n * n + 1) {
            break;
        }
        int new_x = x + dx[di];
        int new_y = y + dy[di];
        
        /// change direction or not
        if ( (new_x < 0 || new_y < 0 || new_x == n || new_y == n) || a[new_x][new_y] != 0) {
            ++di;
            if (di == 4) {
                di = 0;
            }
            new_x = x + dx[di];
            new_y = y + dy[di];
        }
        
        a[new_x][new_y] = cur_num;
        x = new_x;
        y = new_y;
        ++cur_num;
    }
    return a;
}
