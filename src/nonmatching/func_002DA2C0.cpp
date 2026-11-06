/* fuzzy: 84.3 */
extern char D_0037CA18[];
extern char D_00392E90[];
extern char D_00392EC8[];
extern int D_00355048[12];

struct Mgr_002DA2C0 {
    char pad0[0x10];
    void* m10;
};
extern Mgr_002DA2C0* D_00392068;

extern "C" void* func_001046B0(unsigned int size);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001F0210(unsigned int name, void* a, int b, int c, int d);
extern "C" char* func_002DA190(void* p, int v);

struct Prio_002DA2C0;

struct Link_002DA2C0 {
    int m0;
    Prio_002DA2C0* m4;
    int m8;
    Link_002DA2C0* mC;
    Link_002DA2C0* m10;
    Link_002DA2C0() {
        m4 = (Prio_002DA2C0*)-1;
        m8 = 0;
        mC = this;
        m10 = this;
    }
    virtual ~Link_002DA2C0() {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    virtual void Key();
    Prio_002DA2C0* GetData() { return m4; }
    Link_002DA2C0* Valid() { return (int)m4 != -1 ? this : 0; }
    void InsertBefore(Link_002DA2C0* h) {
        m10 = h->m10;
        mC = h;
        h->m10->mC = this;
        h->m10 = this;
    }
    void InsertSorted(Link_002DA2C0* h, int pri) {
        Link_002DA2C0* p = h;
        while ((p = p->mC->Valid()) != 0) {
            if (pri >= p->m8) {
                InsertBefore(p);
                return;
            }
        }
        InsertBefore(h);
    }
};

struct Head_002DA2C0 : Link_002DA2C0 {
    Head_002DA2C0() {}
    ~Head_002DA2C0() {}
    virtual void Key();
};

struct Prio_002DA2C0 : Link_002DA2C0 {
    char pad18[0x38 - 0x18];
    int m38;
    int m3C;
    char pad40[4];
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Prio_002DA2C0();
};

struct Iter_002DA2C0 {
    int m0;
    Link_002DA2C0* m4;
    void* m8;
    Iter_002DA2C0() { m8 = D_0037CA18; m4 = 0; }
    ~Iter_002DA2C0() { m8 = D_0037CA18; }
    Prio_002DA2C0* Next() {
        m4 = m4->mC->Valid();
        if (!m4) return 0;
        return m4->GetData();
    }
    Prio_002DA2C0* Advance(Link_002DA2C0* c) {
        m4 = c->mC->Valid();
        if (!m4) return 0;
        return m4->GetData();
    }
    Prio_002DA2C0* First(Link_002DA2C0* h) {
        m4 = h;
        return Next();
    }
};

struct Obj_002DA2C0 {
    int m0;
    int m4[12];
    void Send();
};

void Obj_002DA2C0::Send()
{
    Iter_002DA2C0 it;
    Head_002DA2C0 head;
    void* tbl = D_00392068->m10;
    Prio_002DA2C0* d;
    for (int i = 0; i < 12; i++) {
        if (!m4[i]) continue;
        d = new Prio_002DA2C0;
        int pri = m4[i];
        d->m8 = pri;
        d->m3C = m4[i];
        d->m38 = D_00355048[i];
        d->InsertSorted(&head, pri);
    }
    d = it.First(&head);
    Iter_002DA2C0* q = &it;
    if (d) {
        do {
            void* s = func_001E6978(func_001190D0(8));
            func_001E7268(s, D_00392E90, d->m3C);
            func_001E7138(s, D_00392EC8, func_002DA190(tbl, d->m38));
            func_001F0210(0xA6111F30, s, 0, 0, 0);
            d = q->Advance(it.m4);
        } while (d);
    }
    d = it.First(&head);
    if (d) {
        Iter_002DA2C0* q = &it;
        do {
            Prio_002DA2C0* nx = q->Advance(it.m4);
            delete d;
            d = nx;
        } while (d);
    }
}
