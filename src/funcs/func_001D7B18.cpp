struct Vec_001D7B18 {
    float x, y, z, w;
};

struct Link_001D7B18 {
    unsigned int m_bit : 1;
};

struct Node_001D7B18 {
    union {
        struct {
            unsigned char m_type : 2;
        } b;
        int m_word;
    } u;
    Link_001D7B18 m_link;
    void Walk(Vec_001D7B18* v, int mode, int top);
};

extern "C" void func_001D7A60(Node_001D7B18* n, Vec_001D7B18* v);
extern "C" void func_001D7A30(Link_001D7B18* l, int b);
extern "C" void func_001D7750(Node_001D7B18* n, int t);
extern "C" Node_001D7B18* func_001DA7D8(Link_001D7B18* l);
extern "C" Node_001D7B18* func_001DA820(Link_001D7B18* l);

static inline void Flip_001D7B18(Node_001D7B18* n)
{
    n->u.m_word = (-(n->u.m_word >> 2) << 2) | n->u.b.m_type;
    func_001D7A30(&n->m_link, n->m_link.m_bit ^ 1);
}

void Node_001D7B18::Walk(Vec_001D7B18* v, int mode, int top)
{
    if (top) {
        Vec_001D7B18 t;
        t.x = -v->x;
        t.y = -v->y;
        t.z = -v->z;
        t.w = -v->w;
        func_001D7A60(this, &t);
    }
    int bits = u.b.m_type;
    bool leaf = bits == 3;
    if (!leaf) {
        char type = bits;
        if (type != 1) {
            int k = type ? 0 : 2;
            switch (mode) {
            case 0: break;
            case 1:
                if (type == 0) Flip_001D7B18(this);
                func_001D7750(this, k);
                break;
            case 2:
                Flip_001D7B18(this);
                break;
            case 3:
                if (type == 2) Flip_001D7B18(this);
                func_001D7750(this, k);
                break;
            }
        }
        func_001DA7D8(&m_link)->Walk(v, mode, 0);
        func_001DA820(&m_link)->Walk(v, mode, 0);
    }
    if (top) func_001D7A60(this, v);
}
