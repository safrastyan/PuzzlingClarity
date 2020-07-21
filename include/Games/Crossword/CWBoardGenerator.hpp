#pragma once

#include "CWOptimalDictionary.hpp"

#include <string>
#include <vector>

namespace pc {
namespace games {
namespace crossword {

using Board = std::vector<std::vector<char>>;

struct Node 
{
    /// those are the starting coordinates
    int row;
    int col;
    int len;
    int quiz_id;

    /// if false then this word is vertical
    bool across;
    
};


/// initial agreement that templates of the crosswords have unique id associated with it. For now id=1 is the only template we have
std::vector<Node> template_loader(int id);

struct CWBoardGeneratorConfig
{
    CWBoardGeneratorConfig();
    int word_count;
    int template_id;    
};


class CWBoardGenerator
{
public:
    
    CWBoardGenerator(int rows, int cols, const std::string& path);
    /// call this or else nothign will work
    void config(CWBoardGeneratorConfig);

    /// return a picture of how the board will look like
    Board board_buleprint() const;
    Board generate();



private:

    static bool do_intersect(Node n1, Node n2); /// check if they have an intersection point
    
    void calculate_intersections();

    CWOptimalDictionary m_dict;
    std::vector<Node> m_nodes;
    
    std::vector<std::vector<int>> m_node_intersections; /// thos will store the intersections, those are basically the constraints for the crossword

    
    CWBoardGeneratorConfig m_config; ///for adding extra constraints
    
    int m_rows;
    int m_cols;


    //// all are for the algo
};

}
}
}
