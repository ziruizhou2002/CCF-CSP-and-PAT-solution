#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(505);
struct Block {
    int num, count;  //块编号、以该结点为尾结点的链的长度
    Block* father;  //父块
    Block(int n, int c = 1, Block* f = nullptr) : num(n), count(c), father(f) {}
};
Block* root = new Block(0, 1);
vector<Block*> chains(505, root);
int n, m, t, k, order = 0;
struct Action {
    //结点编号num,操作op(op==0表示接收一条链,op==1表示产生一个块,op==2时表示进行查询),该操作对应的时刻time,命令编号order
    // block当op==0时为传递的链的尾块指针,当op==1时表示要产生的块的指针,当op==2时为nullptr
    int num, op, time, order;
    Block* block;
    Action(int n, int t, int oop, int ord, Block* b = nullptr) : num(n), time(t), op(oop), order(ord), block(b) {}
    bool operator<(const Action& a) const {
        if (this->time != a.time)
            return this->time > a.time;
        else if (this->op != a.op)
            return this->op > a.op;
        else
            return this->order > a.order;
    }
};
priority_queue<Action> actions;
bool canAccept(Block* Old, Block* New) {
    return Old->count < New->count or (Old->count == New->count and Old->num > New->num);
}
void diffuse(int v, int time) {
    for (int i : graph[v]) {
        if (canAccept(chains[i], chains[v])) {
            actions.push(Action(i, time + t, 0, ++order, chains[v]));
        }
    }
}
void outputChain(Block* b) {
    if (not b)
        return;
    outputChain(b->father);
    cout << " " << b->num;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> t >> k;
    getchar();
    for (int ii = 0; ii < k; ++ii) {
        string line;
        getline(cin, line);
        vector<int> a;
        for (int i = 0, j = 0; i < line.size(); i = j + 1) {
            j = line.find(' ', i);
            if (j == string::npos)
                j = line.size();
            a.push_back(stoi(line.substr(i, j - i)));
        }
        if (a.size() == 2) {
            actions.push(Action(a[0], a[1], 2, ++order));
        } else {
            actions.push(Action(a[0], a[1], 1, ++order, new Block(a[2])));
        }
    }
    while (not actions.empty()) {
        auto a = actions.top();
        actions.pop();
        if (a.op == 0 and canAccept(chains[a.num], a.block)) {  //接收一条链
            chains[a.num] = a.block;
            diffuse(a.num, a.time);
        } else if (a.op == 1) {  //产生一个块
            a.block->count = chains[a.num]->count + 1;
            a.block->father = chains[a.num];
            chains[a.num] = a.block;
            diffuse(a.num, a.time);
        } else if (a.op == 2) {  //查询
            cout << chains[a.num]->count;
            outputChain(chains[a.num]);
            cout << "\n";
        }
    }
    return 0;
}