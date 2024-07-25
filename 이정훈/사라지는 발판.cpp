#include <string>
#include <vector>

using namespace std;

const int a_win = 1;
const int b_win = -1;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

class minimax_tree_node {
private:
    int weight = 0;
    int depth = 0;
    int min_child_depth = 99999;
    int max_child_depth = 0;
    vector<int> loc = { 0, 0 };
    vector<class minimax_tree_node*> link;

public:
    minimax_tree_node(vector<vector<int>> board, int _depth, vector<int> aloc, vector<int> bloc) {
        depth = _depth;

        if (aloc == bloc) {
            if (depth % 2 == 0) {
                weight = b_win;
            }
            else {
                weight = a_win;
            }

            return;
        }

        if (depth % 2 == 0) {
            board[aloc[0]][aloc[1]] = 0;
            for (int i = 0; i < 4; i++) {
                vector<int> new_aloc = aloc;
                new_aloc[0] += dy[i];
                new_aloc[1] += dx[i];
                if (new_aloc[0] < 0 || new_aloc[0] >= board.size()) continue;
                if (new_aloc[1] < 0 || new_aloc[1] >= board[0].size()) continue;

                if (board[new_aloc[0]][new_aloc[1]]) {
                    link.push_back(new minimax_tree_node(board, depth + 1, new_aloc, bloc));
                }
            }
        }
        else {
            board[bloc[0]][bloc[1]] = 0;
            for (int i = 0; i < 4; i++) {
                vector<int> new_bloc = bloc;
                new_bloc[0] += dy[i];
                new_bloc[1] += dx[i];
                if (new_bloc[0] < 0 || new_bloc[0] >= board.size()) continue;
                if (new_bloc[1] < 0 || new_bloc[1] >= board[0].size()) continue;

                if (board[new_bloc[0]][new_bloc[1]]) {
                    link.push_back(new minimax_tree_node(board, depth + 1, aloc, new_bloc));
                }
            }
        }

        if (link.size() == 0) {
            if (depth % 2 == 0)
                weight = b_win;
            else
                weight = a_win;

            return;
        }

        int child_weight_sum = 0;

        for (auto each_link : link) {
            child_weight_sum += each_link->get_weight();
            if (each_link->get_depth() < min_child_depth) {
                min_child_depth = each_link->get_depth();
            }
            if (each_link->get_depth() > max_child_depth) {
                max_child_depth = each_link->get_depth();
            }
        }


        if (abs(child_weight_sum) == link.size()) {
            weight = child_weight_sum / link.size();
            depth = min_child_depth;
        }
        else {
            weight = 0;
        }
    }

    ~minimax_tree_node() {
        for (auto each_link : link) {
            delete each_link;
        }
    }

    inline int get_weight() { return weight; }
    inline int get_depth() { return depth; }
    inline int get_max_depth() { return max_child_depth; }

    int get_solution() {
        printf("get_solution\n");
        if (weight != 0) {
            printf("%d", depth);
            return depth;
        }

        int max_depth = 0;
        minimax_tree_node* target;

        if (depth % 2 == 0) {
            for (auto each_link : link) {
                if (max_depth < each_link->get_max_depth()) {
                    max_depth = each_link->get_max_depth();
                    target = each_link;
                }
                if (each_link->get_weight() == a_win) {
                    printf("a_win\n");
                    if (max_depth < each_link->get_max_depth()) {
                        max_depth = each_link->get_max_depth();
                        target = each_link;
                    }
                    return each_link->get_depth();
                }
            }
        }
        else {
            for (auto each_link : link) {
                if (max_depth < each_link->get_max_depth()) {
                    max_depth = each_link->get_max_depth();
                    target = each_link;
                }
                if (each_link->get_weight() == b_win) {
                    printf("b_win\n");
                    if (max_depth < each_link->get_max_depth()) {
                        max_depth = each_link->get_max_depth();
                        target = each_link;
                    }
                    return each_link->get_depth();
                }
            }
        }
        printf("%d\n", max_depth);
        printf("%p \n", target);
        return target->get_solution();
    }
};


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = 0;

    minimax_tree_node root(board, 0, aloc, bloc);

    answer = root.get_solution();

    return answer;
}

int main() {
    printf("%d\n", solution({ {1,1,1},{1,1,1},{1,1,1} }, { 1,0 }, { 1,2 }));
}