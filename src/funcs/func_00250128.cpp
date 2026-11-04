extern void* D_00392068;

struct Node_00250128 {
    int pad0;
    int m_pri;
    int pad8;
    Node_00250128* m_next;
};

static inline Node_00250128* Valid_00250128(Node_00250128* n)
{
    return (n->m_pri != -1) ? n : 0;
}

static inline unsigned int Count_00250128(Node_00250128* head)
{
    unsigned int n = 0;
    Node_00250128* q;
    for (Node_00250128* p = head->m_next; (q = Valid_00250128(p)) != 0; p = q->m_next)
        n++;
    return n;
}

struct Game_00250128 {
    char pad[0x30];
    Node_00250128 m_skaters;
};

extern Game_00250128* D_0038FC78;

class Iter_00250128 {
public:
    void* m_node;
    int m_index;
    Iter_00250128() : m_index(0) {}
    virtual ~Iter_00250128() {}
    virtual void Run();
};

struct Conn_00250128 {
    char pad[0x18];
    void* m_obj;
    char pad1C[0x30 - 0x1C];
    int m_team;
};

struct Self_00250128 {
    char pad[0x8];
    int m_target;
};

extern "C" Conn_00250128* func_002A53F8(void* net, Iter_00250128* it, int a);
extern "C" Conn_00250128* func_002A5490(void* net, Iter_00250128* it, int a);
extern "C" void* func_003315B8(void* p, int c, unsigned int n);
extern "C" void* func_0022E358(Game_00250128* g);
extern "C" bool func_0024F540(void* p);
extern "C" void* func_00203360(void* p);
extern "C" int func_002392B8(void* p);
extern "C" void* func_0022DE70(Game_00250128* g, unsigned int i);

bool func_00250128(Self_00250128* self)
{
    Game_00250128* g = D_0038FC78;
    if (func_0024F540(func_0022E358(g))) {
        void* net = D_00392068;
        Iter_00250128 it;
        int scores[4];
        func_003315B8(scores, 0, sizeof(scores));
        for (Conn_00250128* c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0))
            scores[c->m_team] += func_002392B8(func_00203360(c->m_obj));
        for (int i = 0; i < 4; i++) {
            if (scores[i] >= self->m_target)
                return true;
        }
    } else {
    for (unsigned int i = 0; i < Count_00250128(&g->m_skaters); i++) {
        if (func_002392B8(func_00203360(func_0022DE70(g, i))) >= self->m_target)
            return true;
    }
    }
    return false;
}
