#include <iostream>
#include <string>
#include "branch.h"
#include <ctime>

const std::size_t ARR_LEN = 1;
Branch* trees[ARR_LEN];

void Branch::accommodationElves()
{
    std::srand(std::time(nullptr));
    for (std::size_t i = 0; i < ARR_LEN; i++)
    {
        trees[i] = new Branch();

        trees[i]->fill();

        trees[i]->print(" ");
    }
}

void Branch::findElves()
{
    std::string search_name;
    Branch* search_branch = nullptr;
    std::cout << "Enter a search name: ";
    std::cin >> search_name;

    for (const auto& tree : trees)
    {
        search_branch = tree->find(search_name);
        if (search_branch != nullptr)
        {
            Branch* parent = search_branch->parent;

            if (!(parent == nullptr || parent->parent == nullptr))
            {
                search_branch = parent;
            }
            break;
        }
    }

    if (search_branch == nullptr)
        std::cout << "Branch \'" << search_name << "\' not found.\n";
    else
    {
        search_branch->print(" ");
        std::cout << "number of neighbors: " << search_branch->calc_neighbors() << std::endl;
    }

    for (auto& tree : trees)
    {
        delete tree;
        tree = nullptr;
    }
}

 