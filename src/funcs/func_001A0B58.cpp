struct Node_001A0B58 {
    int m0;
    int m_tag;
    int m8;
    Node_001A0B58* m_next;
    Node_001A0B58* m_prev;
    virtual ~Node_001A0B58();
    virtual void V1();
    virtual void V2();
    Node_001A0B58* First();
    int Count();
};

static inline Node_001A0B58* Valid_001A0B58(Node_001A0B58* n)
{
    Node_001A0B58* r = 0;
    if (n->m_tag != -1) r = n;
    return r;
}

inline Node_001A0B58* Node_001A0B58::First()
{
    return Valid_001A0B58(m_next);
}

static inline Node_001A0B58* Next_001A0B58(Node_001A0B58* n)
{
    Node_001A0B58* r = n->m_next;
    if (r->m_tag == -1) r = 0;
    return r;
}

inline int Node_001A0B58::Count()
{
    int cnt = 0;
    for (Node_001A0B58* n = Next_001A0B58(this); n; n = Next_001A0B58(n))
        cnt++;
    return cnt;
}

struct Owner_001A0B58 {
    char pad0[0x14];
    void* m14;
};

extern int D_0038CBC8;

extern "C" void* func_001A0718(void* self);
extern "C" float func_00119768(void* p);
extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* mem);
extern "C" int func_001EE610(void* p);
extern "C" void func_001EE608(void* p);
extern "C" void func_001A0E50(void* self, float* a, float* b, float* c);
extern "C" void func_001A0730(void* self);
extern "C" int func_001A9E98(void* p, void* q);
extern "C" void func_001A2828(void* self);
extern "C" int func_001A2480(void* self);
extern "C" void func_001A24C8(void* self);

struct C_001A0B58 {
    int m0;
    int m4;
    int m8;
    Owner_001A0B58* mC;
    int m_pad[3];
    Node_001A0B58 m_head;
    char pad34[0x50 - 0x34];
    float m50;
    int m54;
    float m58;
    char m5C[0x68 - 0x5C];
    void* m68;
    void Update();
};

void C_001A0B58::Update()
{
    void* p = func_001A0718(this);
    if (p) m50 = func_00119768(p);
    if (m54) {
        Owner_001A0B58* o = mC;
        if (!o->m14) o->m14 = func_001EE428(func_00121960(0xF4));
        if (func_001EE610(mC->m14)) {
            float a, b, c;
            func_001A0E50(this, &a, &b, &c);
            if ((a <= c && b >= m58) || (c <= a && b <= m58)) {
                func_001EE608(mC->m14);
                m54 = 0;
            }
        } else {
            m54 = 0;
        }
    }
    D_0038CBC8 = 1;
    int cnt = m_head.Count();
    Node_001A0B58* n = m_head.First();
    for (int i = 0; i < cnt; i++) {
        n->V2();
        n = Valid_001A0B58(n->m_next);
    }
    D_0038CBC8 = 0;
    func_001A0730(this);
    if (func_001A9E98(m68, m5C)) {
        func_001A2828(this);
        if (func_001A2480(this)) func_001A24C8(this);
    }
}
