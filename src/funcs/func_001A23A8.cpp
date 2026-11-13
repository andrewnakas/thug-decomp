struct Node_001A23A8 {
    int m0;
    int m_tag;
    int m8;
    Node_001A23A8* m_next;
};

static inline Node_001A23A8* Valid_001A23A8(Node_001A23A8* n)
{
    Node_001A23A8* r = 0;
    if (n->m_tag != -1) r = n;
    return r;
}

extern "C" float func_0011A0E8(Node_001A23A8* n);
extern "C" void* func_0019EBD0(void* p);
extern "C" void func_00119FF8(Node_001A23A8* n, char* buf);

struct Obj_001A23A8 {
    char pad0[0x28];
    Node_001A23A8* m28;
    char pad2C[0x6C - 0x2C];
    void* m6C;
    void Fn(unsigned int idx, char* buf, float* weight);
    Node_001A23A8* First()
    {
        if (~m28->m_tag == 0)
            return 0;
        return m28;
    }
    Node_001A23A8* Nth(unsigned int idx)
    {
        for (Node_001A23A8* n = First(); n; n = Valid_001A23A8(n->m_next)) {
            if (idx-- == 0)
                return n;
        }
        return 0;
    }
};

void Obj_001A23A8::Fn(unsigned int idx, char* buf, float* weight)
{
    Node_001A23A8* p = Nth(idx);
    float w = func_0011A0E8(p);
    if (w <= 0.0f) {
        *weight = 0.0f;
        return;
    }
    func_0019EBD0(m6C);
    func_00119FF8(p, buf);
    *weight = w;
}
