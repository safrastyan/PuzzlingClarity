#include "Games/Crossword/CWBoardGenerator.hpp"

#include <cassert>
#include <algorithm>

namespace pc {
namespace games {
namespace crossword {

std::vector<std::pair<int, int>> Node::all_coords() const
{
    int px, py;
    if (across) {
        px = 0;
        py = 1;
    } else {
        px = 1;
        py = 0;
    }
    std::vector<std::pair<int,int>> res;
    res.push_back(std::make_pair(row, col));
    for (int i = 1; i < len; ++i) {
        res.push_back(std::make_pair(res.back().first + px, res.back().second + py));  
    }
    return res;
}
CWBoardGeneratorConfig::CWBoardGeneratorConfig(): word_count(24)
                                                , template_id(1)
{

}

CWBoardGenerator::CWBoardGenerator(int rows, int cols, const std::string& path): m_dict(path)
                                                                               , m_nodes()
                                                                               , m_node_intersections()  
                                                                               , m_config()             
                                                                               , m_rows(rows)
                                                                               , m_cols(cols)

{
}



void CWBoardGenerator::config(CWBoardGeneratorConfig c)
{
    m_config = c; ///unused for now
    m_nodes = template_loader(m_config.template_id);
    calculate_intersections();
}

Board CWBoardGenerator::board_buleprint() const 
{
    Board res(m_rows, std::vector<char>(m_cols, '#'));
    for (auto node: m_nodes) {
        int px = 0, py = 1;
        if (!node.across) {
            px = 1;
            py = 0;
        }
        int x = node.row;
        int y = node.col;
        for (int j = 0; j < node.len; ++j) {
            res[x][y] = 'a';
            x += px;
            y += py;
        }
    }
    return res;
}
Board CWBoardGenerator::generate()
{
    return Board(); ///todo
}


NodeIntersection CWBoardGenerator::do_intersect(Node n1, Node n2)
{
    ///TODO , horrible approach but this is done only once
    NodeIntersection res;
    res.pos1 = -1;
    res.pos2 = -1;
    auto cords1 = n1.all_coords();
    auto cords2 = n2.all_coords();
    for (int i = 0; i < cords1.size(); ++i) {
        auto f = std::find(cords2.begin(), cords2.end(), cords1[i]);
        if (f != cords2.end()) {
            res.pos1 = i;
            res.pos2 = f - cords2.begin();
            break;
        }
    }
    return res;

}

void CWBoardGenerator::calculate_intersections()
{
    m_node_intersections = std::vector<std::vector<NodeIntersection>>(m_nodes.size());
    for (int i = 0; i < m_nodes.size(); ++i) {
        for (int j = 0; j < m_nodes.size(); ++j) {
            if (i == j) {
                continue;
            }
            auto res = do_intersect(m_nodes[i], m_nodes[j]);
            if (res.pos1 == -1) {
                continue;
            }
            res.node1_id = i;
            res.node2_id = j;
            m_node_intersections[i].push_back(res);
        }
    }
}


}
}
}





namespace pc {
namespace games {
namespace crossword {

std::vector<Node> template_loader(int id)
{
    std::vector<Node> res;
    if (id != 1) {
        ////TODO , more templates , for now die
        assert(false);
    }
    
    Node d;

    std::vector<std::vector<int>> meta = {
        {0, 0, 4, 1, 1},
        {0, 1, 10, 0, 2},
        {0, 3, 4, 0, 3},
        {0, 5, 6, 0, 4},
        {0, 7, 6, 0, 5},
        {0, 9, 8, 0, 6},
        {0, 12, 4, 0, 7},
        {1, 3, 10, 1, 8},
        {3, 0, 8, 1, 9},
        {3, 9, 4, 1, 10},
        {3, 11, 10, 0, 11},
        {5, 0, 6, 1, 12},
        {5, 3, 8, 0, 13},
        {5, 7, 6, 1, 14},
        {7, 0, 6, 1, 15},
        {7, 5, 6, 0, 16},
        {7, 7, 5, 1, 17},
        {7, 7, 6, 0, 17},
        {9, 0, 4, 1, 18},
        {9, 0, 4, 0, 18},
        {9, 5, 8, 1, 19},
        {9, 9, 4, 0, 20},
        {11, 0, 10, 1, 21},
        {12, 9, 4, 1, 22}
    } ;

    for (int i = 0; i < meta.size(); ++i) {
        d.row = meta[i][0];
        d.col = meta[i][1];
        d.len = meta[i][2];
        d.across = meta[i][3] >= 1;
        d.quiz_id = meta[i][4];
        res.push_back(d);
    }

    return res;
}
}
}
}