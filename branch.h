#pragma once
#ifndef VILLAGE_ELVES_BRANCH_H
#define VILLAGE_ELVES_BRANCH_H
#pragma once
#include <string>
#include <iostream>
#include <vector>

class Branch
{
public:
    ~Branch()
    {
        for (auto& ch : children)
        {
            delete ch;
            ch = nullptr;
        }
    }

    void fill()
    {
        auto rand_value = [](int min, int max)
        {
            return min + (rand() % static_cast<int>(max - min + 1));
        };

        std::cout << "Enter elf name: ";
        std::cin >> this->elf_name;

        std::size_t i_len = rand_value(3, 5);

        for (size_t i = 0; i < i_len; i++)
        {
            Branch* branch_i = new Branch();
            branch_i->parent = this;
            std::cout << "Enter elf name: ";
            std::cin >> branch_i->elf_name;

            std::size_t j_len = rand_value(2, 3);
            for (size_t j = 0; j < j_len; j++)
            {
                Branch* branch_j = new Branch();
                branch_j->parent = branch_i;
                std::cout << "Enter elf name: ";
                std::cin >> branch_j->elf_name;
                branch_i->children.push_back(branch_j);
            }
            children.push_back(branch_i);
        }
    }

    Branch* find_internal(const std::string& name)
    {
        if (this->elf_name == name)
            return this;

        for (Branch* node : this->children)
        {
            Branch* found = node->find_internal(name);
            if (found != nullptr)
            {
                return found;
            }
        }
        return nullptr;
    }

    Branch* find(const std::string& name)
    {
        if (name == "None")
            return nullptr;

        return find_internal(name);
    }

    void calc_neighbors(const Branch* root, std::size_t& n)
    {
        for (const auto& br : root->children)
        {
            if (br->elf_name != "None")
                n++;
            br->calc_neighbors(br, n);
        }
    }
    std::size_t calc_neighbors()
    {
        std::size_t n = 0;
        calc_neighbors(this, n);
        if (this->elf_name == "None")
            n--;
        return n;
    }

    void print(const Branch* branch, const std::string& indent)
    {
        std::cout << indent << branch->elf_name << std::endl;
        for (std::size_t i = 0; i < branch->children.size(); i++)
        {
            print(branch->children[i], indent + "    ");
        }
    }

    void print(const std::string& indent)
    {
        print(this, indent);
        std::cout << indent << std::endl;
    }

    Branch* parent = nullptr;
    std::string elf_name;
    std::vector<Branch*> children;
    void accommodationElves();
    void findElves();
};
#endif //VILLAGE_ELVES_BRANCH_H
