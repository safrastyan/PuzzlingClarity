#pragma once

#include <string>

/**
 * This file is for enumerating the tasks which will be used a lot
 **/

namespace pc {
namespace base {

enum class Task : int 
{
    sorting, 
};

/// return the number of testcases for the task
int test_case_count(Task);

/// slugs are used everywhere aren't day
std::string task_slug(Task);

}
}


namespace pc {
namespace base {

/// return the number of testcases for the task
inline int test_case_count(Task t)
{
    switch (t) {
    case Task::sorting:
        return 20;
    }
    return 0;
}

inline std::string task_slug(Task t)
{
    switch (t)  {
    case Task::sorting:
        return "sorting";
    }
    return "";
}

}
}
