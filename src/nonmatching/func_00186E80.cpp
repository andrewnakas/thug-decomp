/* fuzzy: 94.9 */
extern char D_00361AA0[];

struct Obj_00186E80;

struct Node_00186E80 {
    int m0;
    Obj_00186E80* m4;
    int m8;
    Node_00186E80* mC;
    Node_00186E80* Valid() { return (int)m4 != -1 ? this : 0; }
    Obj_00186E80* GetData() { return m4; }
};

struct It_00186E80 {
    int m0;
    Node_00186E80* cur;
    void* vt;
    It_00186E80()
    {
        vt = D_00361AA0;
        cur = 0;
    }
    ~It_00186E80() { vt = D_00361AA0; }
    Obj_00186E80* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Obj_00186E80* First(Node_00186E80* h)
    {
        cur = h;
        return Next();
    }
    Obj_00186E80* Advance(Node_00186E80* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
};

extern "C" void func_00185058(Obj_00186E80* o);

struct Bits_00186E80 {
    unsigned int m;
    unsigned int Alloc()
    {
        unsigned int b;
        for (b = 1; m & b; b <<= 1) {
        }
        m |= b;
        return b;
    }
    void Free(unsigned int b) { m &= ~b; }
};

struct Obj_00186E80 {
    int m0;
    Node_00186E80 m4;
    int m14, m18;
    Bits_00186E80 m1C;
    unsigned int m20;
    char pad[0x104 - 0x24];
    int m104;
    void Propagate();
};

void Obj_00186E80::Propagate()
{
    It_00186E80 it;
    unsigned int bit = m1C.Alloc();
    Obj_00186E80* o = it.First(&m4);
    if (o) {
        It_00186E80* p = &it;
        do {
            o->m20 &= ~bit;
            o = p->Advance(it.cur);
        } while (o);
    }
restart:
    m20 &= ~bit;
    Obj_00186E80* d = it.First(&m4);
    if (d) {
        It_00186E80* q = &it;
        do {
            Obj_00186E80* x = d;
            d = q->Advance(it.cur);
            if (!(x->m20 & bit)) {
                x->m20 |= bit;
                func_00185058(x);
                if (m20 & bit) goto restart;
            }
        } while (d);
    }
    if (m20 & bit) goto restart;
    m1C.Free(bit);
}
