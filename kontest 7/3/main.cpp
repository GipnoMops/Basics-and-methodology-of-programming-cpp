#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:

    bool Has(const std::vector<std::string>& node) const;

    void Insert(const std::vector<std::string>& node);

    void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string>& node) const {
    const Node* folder = &root;
    for (size_t i = 0; i < node.size(); ++i) {
        try {
            folder = &(*folder).children.at(node[i]);
        }
        catch (std::out_of_range) {
            return false;
        }
    }
    return true;
}

void Tree::Insert(const std::vector<std::string> &node) {
    Node* folder = &root;
    for (size_t i = 0; i < node.size(); ++i) {
        try {
            folder = &(*folder).children.at(node[i]);
        }
        catch (std::out_of_range) {
            Node in_new_node;
            (*folder).children[node[i]] = in_new_node;
            folder = &(*folder).children.at(node[i]);
        }
    }
}

void Tree::Delete(const std::vector<std::string>& node) {
    Node* folder = &root;
    for (size_t i = 0; i < node.size() - 1; ++i) {
        try {
            folder = &(*folder).children.at(node[i]);
        }
        catch (std::out_of_range) {
            return;
        }
    }
    (*folder).children.erase(node[node.size() - 1]);
}


int main() {
    Tree b;
    std::vector<std::string> v = {"root", "first", "in first"};
    std::vector<std::string> t1 = {"root"};
    std::vector<std::string> t2 = {"root", "first"};
    std::vector<std::string> t3 = {"root", "first", "in first"};

    std::vector<std::string> t12 = {"roott"};
    std::vector<std::string> t22 = {"root", "firstt"};
    std::vector<std::string> t32 = {"root", "first", "in firstt"};

    std::vector<std::string> v2 = {"root", "second", "in second"};

    std::vector<std::string> T1 = {"root"};
    std::vector<std::string> T2 = {"root", "second"};
    std::vector<std::string> T3 = {"root", "second", "in second"};

    std::vector<std::string> T12 = {"roott"};
    std::vector<std::string> T22 = {"root", "secondd"};
    std::vector<std::string> T32 = {"root", "second", "in secondd"};


    b.Insert(v);
    b.Insert(v2);
    std::cout << b.Has(t1) << " " << b.Has(t12) << "\n";
    std::cout << b.Has(t2) << " " << b.Has(t22) << "\n";
    std::cout << b.Has(t3) << " " << b.Has(t32) << "\n";

    std::cout << "\n";

    std::cout << b.Has(T1) << " " << b.Has(T12) << "\n";
    std::cout << b.Has(T2) << " " << b.Has(T22) << "\n";
    std::cout << b.Has(T3) << " " << b.Has(T32) << "\n";

    std::cout << "\n";

    std::cout << b.Has(t1) << " " << b.Has(t2) << " " << b.Has(t3) << " ";

    b.Delete(t3);
    std::cout << b.Has(t3) << " ";

    b.Delete(t1);
    std::cout << b.Has(t2) << " " << b.Has(t1) << " ";

    std::cout << "\n";

    std::cout << b.Has(T1) << " " << b.Has(T12) << "\n";
    std::cout << b.Has(T2) << " " << b.Has(T22) << "\n";
    std::cout << b.Has(T3) << " " << b.Has(T32) << "\n";

}
