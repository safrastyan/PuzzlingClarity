class Solution {
public:

    std::map<std::string, std::string> m_map;
    
    static constexpr char alnum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    static std::string generate()
    {
        std::string res;
        for (int i = 0; i < 6; ++i) {
            int index = std::rand() % sizeof(alnum);
            res.push_back(alnum[index]);
        }
        return res;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        while (true) {
            auto new_tiny = generate();
            if (m_map.find(new_tiny) == m_map.end()) {
                m_map[new_tiny] = longUrl;
                return new_tiny;
            }
        }    
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return m_map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));