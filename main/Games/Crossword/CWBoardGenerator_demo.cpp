#include "Base/Paths.hpp"
#include "Games/Crossword/CWBoardGenerator.hpp"
#include "io/io.hpp"

#include <iostream>
using namespace pc::games::crossword;
using namespace pc::base::paths;
using namespace pc::io;

int main()
{
    std::srand(time(0));
    CWBoardGenerator g(13, 13, linx_standard_dictionary_path());
    CWBoardGeneratorConfig c;
    c.template_id = 1;
    g.config(c);
    write(g.board_buleprint(), "");

    std::cout << "Board is " << std::endl;
    
    auto res =  g.generate();
    for (auto& row: res) {
        for (auto c: row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    write(res, "Board is");
}