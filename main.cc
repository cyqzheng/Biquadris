#include <iostream>
#include <sstream>
#include <string>

#include "sumheap.h"

void printTree(SumHeap *node, SumHeap *cursor, std::string prefix = "");

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: a5q2 <root value>" << std::endl;
        return 1;
    }

    std::istringstream aiss{argv[1]};
    unsigned int rv;
    aiss >> rv;
    SumHeap root{rv};
    SumHeap *cur = &root;

    std::string s;
    while (std::getline(std::cin, s)) {
        std::istringstream iss{s};
        std::string cmd;
        iss >> cmd;

        if (cmd == "addchild") {
            unsigned int v;
            iss >> v;
            try {
                cur = cur->addChild(v);
                printTree(&root, cur);
            } catch (InvalidValueException &i) {
                std::cout << "Invalid value!" << std::endl;
            }

        } else if (cmd == "child") {
            unsigned int i;
            iss >> i;
            if (i < cur->numChildren())
                cur = cur->getChild(i);
            printTree(&root, cur);

        } else if (cmd == "parent") {
            SumHeap *p = cur->getParent();
            if (p)
                cur = p;
            printTree(&root, cur);

        } else if (cmd == "swap") {
            SumHeap *other = &root;
            unsigned int step;
            while (iss >> step) {
                if (step < other->numChildren())
                    other = other->getChild(step);
            }

            try {
                cur->swap(other);
                printTree(&root, cur);
            } catch (InvalidValueException &i) {
                std::cout << "Invalid value!" << std::endl;
            }

        } else {
            std::cerr << "Unrecognized command " << cmd << "!" << std::endl;

        }
    }

    return 0;
}

void printTree(SumHeap *node, SumHeap *cursor, std::string prefix) {
    std::cout << prefix;
    if (node == cursor)
        std::cout << "*";
    std::cout << node->getValue() << std::endl;

    prefix += "  ";
    for (size_t i = 0; i < node->numChildren(); i++)
        printTree(node->getChild(i), cursor, prefix);
}
