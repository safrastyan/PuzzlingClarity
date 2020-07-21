#include "Base/Paths.hpp"
#include "Games/Crossword/CWBoardGenerator.hpp"
#include "io/io.hpp"

#include <iostream>
using namespace pc::games::crossword;
using namespace pc::base::paths;
using namespace pc::io;

int main()
{

    CWBoardGenerator g(13, 13, linx_standard_dictionary_path());
    CWBoardGeneratorConfig c;
    c.template_id = 1;
    g.config(c);
    write(g.board_buleprint(), "");

    std::cout << "Board is " << std::endl;
    
    auto res =  g.generate();
    write(res, "Board is");
}