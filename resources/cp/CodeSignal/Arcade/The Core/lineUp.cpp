int lineUp(std::string commands) 
{
    /// 0 - facing front
    /// 1 - facing left
    /// 2 - facing back 
    /// 3 - facing right
    
    ///a - normal guy
    ///b - idiot
    
    int res = 0;
    int a, b;
    a = 0, b = 0;
    for (auto c: commands) {
        if (c == 'A') {
            a += 2;
            b += 2;
        } else if (c == 'L') {
            a += 1;
            b -= 1;
            b += 4;
        } else {
            a -= 1;
            b += 1;
            a += 4;
        }
        a %= 4;
        b %= 4;
        
        if (a == b) {
            ++res;
        }
    }
    return res;
}

