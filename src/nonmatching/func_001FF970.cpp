/* fuzzy: 52.6 */
/* sym: _vt$11It_001FF970 = 0x00366B58 */

struct LNode_001FF970 {
    int m0;
    int m4;
    int m8;
    LNode_001FF970* mC;
    LNode_001FF970* m10;
    LNode_001FF970* Valid() { return ~m4 != 0 ? this : 0; }
    void InsertBefore(LNode_001FF970* n)
    {
        m10 = n;
        mC = n->mC;
        n->mC->m10 = this;
        n->mC = this;
    }
    void AddSorted(LNode_001FF970* item)
    {
        LNode_001FF970* n = m10->Valid();
        while (n) {
            if (!(n->m8 < item->m8)) {
                item->InsertBefore(n);
                return;
            }
            n = n->m10->Valid();
        }
        item->InsertBefore(this);
    }
};

struct ItemA_001FF970 : LNode_001FF970 {
    int m14;
    int m18;
    int m1C;
};

struct ItemB_001FF970 : LNode_001FF970 {
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
};

struct ItemC_001FF970 : LNode_001FF970 {
    int m14;
    char m18;
    unsigned char m19;
    unsigned char m1A;
    char m1B;
    int m1C;
    int m20;
    int m24;
    int m28;
};

struct Mask_001FF970 {
    int v;
    Mask_001FF970(int x) { v = x; }
    Mask_001FF970(const Mask_001FF970& o) { v = o.v; }
};

struct Conn_001FF970 {
    LNode_001FF970 q0;
    int m14;
    LNode_001FF970 q18;
    int m2C;
    LNode_001FF970 q30;
    int m44;
    int m48;
    char pad4C[0x68 - 0x4C];
    int m68;
    bool Test(Mask_001FF970 f) { return m68 & f.v; }
    char pad6C[0x80 - 0x6C];
    int m80[8];
};

struct Ref_001FF970 {
    int m0;
    int m4;
    void AddRef() { m4++; }
    int Count() { return m4; }
};

struct Msg_001FF970 {
    int m0;
    int m4;
    Ref_001FF970 ref;
};

struct Msg2_001FF970 {
    int m0;
    int m4;
    int m8;
    Ref_001FF970 ref;
};

struct Desc_001FF970 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    void* m4;
    int m8;
    int mC;
    unsigned char m10;
    int m14;
    int m18;
    int m1C;
};

struct CNode_001FF970 {
    int m0;
    Conn_001FF970* m4;
    int m8;
    CNode_001FF970* mC;
    CNode_001FF970* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
    CNode_001FF970* Valid2()
    {
        if (~(int)m4) return this;
        return 0;
    }
    CNode_001FF970* GetNext()
    {
        CNode_001FF970* n = mC;
        if (~(int)n->m4 == 0) return 0;
        return n;
    }
    CNode_001FF970* GetNextK(unsigned k = 0) { return mC->Valid(k); }
};

struct It_001FF970 {
    int m0;
    CNode_001FF970* m_cur;
    It_001FF970() { m_cur = 0; }
    virtual void Reset();
    virtual ~It_001FF970() {}
    Conn_001FF970* Next() { CNode_001FF970* n = m_cur->GetNext(); m_cur = n; if (!n) return 0; return n->m4; } Conn_001FF970* First(CNode_001FF970* h) { m_cur = h; m_cur = m_cur->GetNextK(); if (!m_cur) return 0; return m_cur->m4; }
};

struct Heap_001FF970 {
    char pad[0xF4];
    int mF4;
};
extern Heap_001FF970* D_00388A70;

class Net_001FF970;

extern "C" void func_0031BCE0(int m);
extern "C" void func_0031BCC0(int m);
extern "C" void func_0010A950(Heap_001FF970* h, int ctx);
extern "C" void func_0010A9B0(Heap_001FF970* h);
extern "C" void* func_0010A638(Heap_001FF970* h, int size, int a, int b);
extern "C" Msg_001FF970* func_001FA838(void* p, int type, int len, void* data);
extern "C" Msg2_001FF970* func_001FEBC8(Net_001FF970* n, int type, int len, void* data, int c);
extern "C" void func_001FF670(Net_001FF970* n, Conn_001FF970* c, int q, int type);
extern "C" void* func_001046B0(int size);
extern "C" ItemA_001FF970* func_001FA6C0(void* p, Msg_001FF970* m);
extern "C" ItemB_001FF970* func_001FA6F0(void* p, Msg_001FF970* m);
extern "C" ItemC_001FF970* func_001FA720(void* p, Msg2_001FF970* m);
extern "C" Conn_001FF970* func_001FEA20(Net_001FF970* n, int id);
extern "C" void func_001FA8C0(Msg_001FF970* m, int f);
extern "C" void func_001FA9B0(Msg2_001FF970* m, int f);

class Net_001FF970 {
public:
    int m0;
    char pad4[0x429C - 4];
    int m429C;
    char pad42A0[0x42D8 - 0x42A0];
    CNode_001FF970 m42D8;

    void Send(int to, Desc_001FF970* d);
};

void Net_001FF970::Send(int to, Desc_001FF970* d)
{
    It_001FF970 it;

    func_0031BCE0(m429C);
    func_0010A950(D_00388A70, D_00388A70->mF4);
    switch (d->mC) {
    case 0: {
        Msg_001FF970* msg = func_001FA838(func_0010A638(D_00388A70, 0x10, 1, 0), d->m0, d->m2, d->m4);
        if (to == 0xFF) {
            for (Conn_001FF970* c = it.First(&m42D8); c; c = it.Next()) {
                if (c->m68 == 1) {
                    if (d->m14) func_001FF670(this, c, d->mC, d->m0);
                    msg->ref.AddRef();
                    ItemA_001FF970* item = func_001FA6C0(func_001046B0(0x20), msg);
                    item->m8 = d->m8;
                    item->m1C = m0 + d->m18;
                    c->q0.AddSorted(item);
                }
            }
        } else if (to & 0x80) {
            int id = to & ~0x80;
            for (Conn_001FF970* c = it.First(&m42D8); c; c = it.Next()) {
                if (c->m48 != id && c->m68 == 1) {
                    if (d->m14) func_001FF670(this, c, d->mC, d->m0);
                    msg->ref.AddRef();
                    ItemA_001FF970* item = func_001FA6C0(func_001046B0(0x20), msg);
                    item->m8 = d->m8;
                    item->m1C = m0 + d->m18;
                    c->q0.AddSorted(item);
                }
            }
        } else {
            Conn_001FF970* c = func_001FEA20(this, to);
            if (c->m68 == 1 || d->m0 == 9) {
                if (d->m14) func_001FF670(this, c, d->mC, d->m0);
                msg->ref.AddRef();
                ItemA_001FF970* item = func_001FA6C0(func_001046B0(0x20), msg);
                item->m8 = d->m8;
                item->m1C = m0 + d->m18;
                c->q0.AddSorted(item);
            }
        }
        if (msg->ref.Count() == 0 && msg) func_001FA8C0(msg, 3);
        break;
    }
    case 1: {
        Msg_001FF970* msg = func_001FA838(func_0010A638(D_00388A70, 0x10, 1, 0), d->m0, d->m2, d->m4);
        if (to == 0xFF) {
            for (Conn_001FF970* c = it.First(&m42D8); c; c = it.Next()) {
                if (!c->Test(8)) {
                    if (d->m14) func_001FF670(this, c, d->mC, d->m0);
                    msg->ref.AddRef();
                    ItemB_001FF970* item = func_001FA6F0(func_001046B0(0x2C), msg);
                    item->m8 = d->m8;
                    item->m18 = 0;
                    item->m28 = m0 + d->m18;
                    c->q18.AddSorted(item);
                }
            }
        } else if (to & 0x80) {
            int id = to & ~0x80;
            for (Conn_001FF970* c = it.First(&m42D8); c; c = it.Next()) {
                if (c->m48 != id && !c->Test(8)) {
                    if (d->m14) func_001FF670(this, c, d->mC, d->m0);
                    msg->ref.AddRef();
                    ItemB_001FF970* item = func_001FA6F0(func_001046B0(0x2C), msg);
                    item->m8 = d->m8;
                    item->m18 = 0;
                    item->m28 = m0 + d->m18;
                    c->q18.AddSorted(item);
                }
            }
        } else {
            Conn_001FF970* c = func_001FEA20(this, to);
            if (!c->Test(8)) {
                if (d->m14) func_001FF670(this, c, d->mC, d->m0);
                msg->ref.AddRef();
                ItemB_001FF970* item = func_001FA6F0(func_001046B0(0x2C), msg);
                item->m8 = d->m8;
                item->m18 = 0;
                item->m28 = m0 + d->m18;
                c->q18.AddSorted(item);
            }
        }
        if (msg->ref.Count() == 0 && msg) func_001FA8C0(msg, 3);
        break;
    }
    case 2: {
        Msg2_001FF970* msg = func_001FEBC8(this, d->m0, d->m2, d->m4, d->m10);
        if (to == 0xFF) {
            for (Conn_001FF970* c = it.First(&m42D8); c; c = it.Next()) {
                if (!c->Test(8)) {
                    msg->ref.AddRef();
                    ItemC_001FF970* item = func_001FA720(func_001046B0(0x30), msg);
                    item->m8 = d->mC;
                    item->m20 = 0;
                    item->m28 = m0 + d->m18;
                    item->m19 = d->m10;
                    if (d->m1C) {
                        item->m24 = d->m1C;
                    } else {
                        item->m24 = c->m80[d->m10]++;
                    }
                    item->m1A = d->m1;
                    c->q30.AddSorted(item);
                }
            }
        } else if (to & 0x80) {
            int id = to & ~0x80;
            for (Conn_001FF970* c = it.First(&m42D8); c; c = it.Next()) {
                if (c->m48 != id && !c->Test(8)) {
                    msg->ref.AddRef();
                    ItemC_001FF970* item = func_001FA720(func_001046B0(0x30), msg);
                    item->m8 = d->m8;
                    item->m20 = 0;
                    item->m28 = m0 + d->m18;
                    item->m19 = d->m10;
                    if (d->m1C) {
                        item->m24 = d->m1C;
                    } else {
                        item->m24 = c->m80[d->m10]++;
                    }
                    item->m1A = d->m1;
                    c->q30.AddSorted(item);
                }
            }
        } else {
            Conn_001FF970* c = func_001FEA20(this, to);
            if (!c->Test(8)) {
                msg->ref.AddRef();
                ItemC_001FF970* item = func_001FA720(func_001046B0(0x30), msg);
                item->m8 = d->m8;
                item->m20 = 0;
                item->m28 = m0 + d->m18;
                item->m19 = d->m10;
                if (d->m1C) {
                    item->m24 = d->m1C;
                } else {
                    item->m24 = c->m80[d->m10]++;
                }
                item->m1A = d->m1;
                c->q30.AddSorted(item);
            }
        }
        if (msg->ref.Count() == 0 && msg) func_001FA9B0(msg, 3);
        break;
    }
    }
    func_0010A9B0(D_00388A70);
    func_0031BCC0(m429C);
}
