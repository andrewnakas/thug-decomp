/* fuzzy: 78.2 */
extern char D_00361AA0[];

struct Obj_00187080;

struct Node_00187080 {
    int m0;
    Obj_00187080* m4;
    int m8;
    Node_00187080* mC;
    Node_00187080* Valid() { return (int)m4 != -1 ? this : 0; }
    Obj_00187080* GetData() { return m4; }
};

struct It_00187080 {
    int m0;
    Node_00187080* cur;
    void* vt;
    It_00187080()
    {
        vt = D_00361AA0;
        cur = 0;
    }
    ~It_00187080() { vt = D_00361AA0; }
    Obj_00187080* Next()
    {
        cur = cur->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Obj_00187080* First(Node_00187080* h)
    {
        cur = h;
        return Next();
    }
    Obj_00187080* Advance(Node_00187080* c)
    {
        cur = c->mC->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
};

struct Bits_00187080 {
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

struct Obj_00187080 {
    int m0;
    Node_00187080 m4;
    int m14, m18;
    Bits_00187080 m1C;
    unsigned int m20;
    char pad[0x104 - 0x24];
    int m104;
    void Propagate(int on);
    void SetFlag(int on)
    {
        if (on) {
            m104 |= 1;
        } else {
            m104 &= ~1;
        }
    }
};

void Obj_00187080::Propagate(int on)
{
    It_00187080 it;
    unsigned int bit = m1C.Alloc();
    Obj_00187080* o = it.First(&m4);
    if (o) {
        It_00187080* p = &it;
        do {
            o->m20 &= ~bit;
            o = p->Advance(it.cur);
        } while (o);
    }
restart:
    m20 &= ~bit;
    Obj_00187080* d = it.First(&m4);
    if (d) {
        It_00187080* q = &it;
        do {
            Obj_00187080* x = d;
            d = q->Advance(it.cur);
            if (!(x->m20 & bit)) {
                x->m20 |= bit;
                x->SetFlag(on);
                if (m20 & bit) goto restart;
            }
        } while (d);
    }
    if (m20 & bit) goto restart;
    m1C.Free(bit);
}
