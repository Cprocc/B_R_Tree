#include <cstdio>
using namespace std;

#define bro(x) (((x)->ftr->lc == (x)) ? ((x)->ftr->rc):((x)->ftr-lc))

typedef bool RB_COLOR;
#define RB_COLOR_RED true
#define RB_COLOR_BLACK false

template <typename T>
class readblacktree{
    protected:
        struct RB_Node;
        RB_Node* _root;
        RB_Node* _hot;
        int _size;
        void init(T);
        RB_Node* zig(RB_Node*);
        RB_Node* zag(RB_Node*);

        void SolveDoubleRed(RB_Node*);
        void SolveLostBladk(RB_Node*);

        RB_Node* find();

        void removetree(RB_Node*); //dfs
    public:
        struct iterator;
        readblacktree() : _root(NULL), _hot(NULL), _size(0) {}
        iterator insert(T);

        bool remove(T);
        bool remove(iterator&);

        iterator search(T);
        iterator lower_bound(T);
        iterator upper_bound(T);

        void clear();  //dfs 后续遍历

        int size();
        bool empty();
        iterator begin();
        static iterator end();
};