//https://onlinejudge.org/external/119/11987.pdf

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int find_parent(int x, const std::vector<int>& parents) {
    for (int i = 1; i < (int)parents.size(); i++) {
        if (i == x) {
            if (parents[i] > 0) {
                return find_parent(parents[i], parents);
            }
            else {
                return i;
            }
        }
    }
}

std::vector<int> sets_union(int p, int q, const std::vector<int>& parents) {
    std::vector<int> _new{ parents };
    int p_parent = find_parent(p, parents);
    int q_parent = find_parent(q, parents);

    if (parents[p_parent] <= parents[q_parent]) {
        _new[q_parent] = p_parent;
        --_new[p_parent];
    }
    else {
        _new[p_parent] = q_parent;
        --_new[q_parent];
    }

    return _new;
}

std::vector<int> sets_move(int p, int q, const std::vector<int>& parents) {
    std::vector<int> _new{ parents };
    int temp{};

    for (int i = 1; i < (int)parents.size(); i++) {
        if (find_parent(i, parents) == p && i != p) {
            _new[i] = 0;
            temp = i;
        }
    }

    _new[temp] = -1;

    for (int i = 1; i < (int)parents.size(); i++) {
        if (_new[i] == 0) {
            _new[i] = temp;
        }
    }

    _new[p] = find_parent(q, parents);

    return _new;
}

std::pair<int, int> sum(int p, const std::vector<int>& parents) {
    int p_parent = find_parent(p, parents);
    int sum{};
    int count{};

    for (int i = 1; i < (int)parents.size(); i++) {
        if (find_parent(i, parents) == p_parent) {
            ++count;
            sum += i;
        }
    }

    return std::make_pair(count, sum);
}

int main()
{
    std::vector<int> parents{ -1 };
    std::pair<int, int> ans{};
    int n{}, p{}, q{};
    std::string command{};

    std::cout << "Enter number of sets:\n";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        parents.push_back(-1);
    }

    std::cout << "\nCommand list:\n" 
        << "union - Union the sets containing p and q\n" 
        << "move - Move p to the set containing q\n" 
        << "sum - Return the number of elements and the sum of elements in the set containing p\n" 
        << "quit - Quit the program\n\n";

    while (std::cout << "\nEnter a command:" && std::cin >> command) {
        for (auto i : command) {
            i = tolower(i);
        }

        if (command == "union") {
            std::cout << "Please enter 2 numbers, p and q:";
            std::cin >> p >> q;
            parents = sets_union(p, q, parents);
            std::cout << "\nSuccess!\n";
        }
        else if (command == "move") {
            std::cout << "Please enter 2 numbers, p and q:";
            std::cin >> p >> q;
            parents = sets_move(p, q, parents);
            std::cout << "\nSuccess!\n";
        }
        else if (command == "sum") {
            std::cout << "Please enter a number, p:";
            std::cin >> p;
            ans = sum(p, parents);
            std::cout << ans.first << " " << ans.second << "\n" << "Success!\n";
        }
        else if (command == "quit") {
            std::cout << "Quitting...\n";
            break;
        }
        else {
            std::cout << "This command does not exist!\n";
        }

    }

}

