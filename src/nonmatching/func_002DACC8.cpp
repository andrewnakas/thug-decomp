/* fuzzy: 97.5 */
/* sym: _vt$13Link_002DACC8 = 0x0037CA60 */
/* sym: _vt$13Head_002DACC8 = 0x0037CA00 */
extern char D_0037C9D0[];
extern char D_0037C9E8[];
extern char D_0037CA18[];
extern char D_00392ED8[];
extern char D_00392E90[];
extern char D_00392EE0[];
extern char D_00392EE8[];
extern char D_00392EC8[];

struct Net_002DACC8 {
    char pad[0x10];
    void* m10;
};
extern Net_002DACC8* D_00392068;

struct Params_002DACC8;
extern "C" void* func_001046B0(unsigned int size);
extern "C" void* func_001190D0(int size);
extern "C" Params_002DACC8* func_001E6978(void* mem);
extern "C" char* func_002DA190(void* p, int id);
extern "C" void func_001E7138(Params_002DACC8* p, char* name, char* value);
extern "C" void func_001E7268(Params_002DACC8* p, char* name, int value);
extern "C" void func_001F0210(unsigned int name, Params_002DACC8* p, int a, int b, int c);
extern "C" void func_001E6AE8(Params_002DACC8* p, int flags);
extern "C" void func_00331A9C(char* dst, char* src);

struct Player_002DACC8 {
    char pad[0x18];
    char name[0x20];
    int m38;
    int m3C;
};

struct PNode_002DACC8 {
    int m0;
    Player_002DACC8* data;
    int m8;
    PNode_002DACC8* next;
    Player_002DACC8* GetData() { return data; }
    bool IsEnd() { return (int)data == -1; }
    PNode_002DACC8* NextItem()
    {
        if (next->IsEnd())
            return 0;
        return next;
    }
};

struct Team_002DACC8 {
    char pad[0x18];
    int m18;
    PNode_002DACC8 m1C;
};

struct TNode_002DACC8 {
    int m0;
    Team_002DACC8* data;
    int m8;
    TNode_002DACC8* next;
    Team_002DACC8* GetData() { return data; }
    TNode_002DACC8* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct TIt_002DACC8 {
    int m0;
    TNode_002DACC8* cur;
    void* vt;
    TIt_002DACC8() { vt = D_0037C9D0; cur = 0; }
    ~TIt_002DACC8() { vt = D_0037C9D0; }
    Team_002DACC8* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Team_002DACC8* First(TNode_002DACC8* h)
    {
        cur = h;
        return Next();
    }
};

struct PIt_002DACC8 {
    int m0;
    PNode_002DACC8* cur;
    void* vt;
    PIt_002DACC8() { vt = D_0037C9E8; cur = 0; }
    ~PIt_002DACC8() { vt = D_0037C9E8; }
    Player_002DACC8* Next()
    {
        cur = cur->NextItem();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Player_002DACC8* First(PNode_002DACC8* h)
    {
        cur = h;
        return Next();
    }
};

struct Entry_002DACC8;

struct Link_002DACC8 {
    int m0;
    Entry_002DACC8* m4;
    int m8;
    Link_002DACC8* mC;
    Link_002DACC8* m10;
    Link_002DACC8() {
        m4 = (Entry_002DACC8*)-1;
        m8 = 0;
        mC = this;
        m10 = this;
    }
    virtual ~Link_002DACC8() {
        m10->mC = mC;
        mC->m10 = m10;
        mC = this;
        m10 = this;
    }
    virtual void Key();
    Entry_002DACC8* GetData() { return m4; }
    Link_002DACC8* Valid() { return (int)m4 != -1 ? this : 0; }
    void InsertBefore(Link_002DACC8* h) {
        m10 = h->m10;
        mC = h;
        h->m10->mC = this;
        h->m10 = this;
    }
    void InsertSorted(Link_002DACC8* n) {
        int pri = n->m8;
        for (Link_002DACC8* p = mC->Valid(); p; p = p->mC->Valid()) {
            if (pri >= p->m8) {
                n->InsertBefore(p);
                return;
            }
        }
        n->InsertBefore(this);
    }
};

struct Head_002DACC8 : Link_002DACC8 {
    Head_002DACC8() {}
    ~Head_002DACC8() {}
    virtual void Key();
};

struct Entry_002DACC8 : Link_002DACC8 {
    char name[0x20];
    int m38;
    int m3C;
    int m40;
    Entry_002DACC8();
};

extern "C" Entry_002DACC8* func_002DB438(void* mem);

struct LIt_002DACC8 {
    int m0;
    Link_002DACC8* m4;
    void* m8;
    LIt_002DACC8() { m8 = D_0037CA18; m4 = 0; }
    ~LIt_002DACC8() { m8 = D_0037CA18; }
    Entry_002DACC8* Next() {
        m4 = m4->mC->Valid();
        if (!m4) return 0;
        return m4->GetData();
    }
    Entry_002DACC8* First(Link_002DACC8* h) {
        m4 = h;
        return Next();
    }
};

struct Obj_002DACC8 : TNode_002DACC8 {
    char pad10[4];
    char pad14[4];
    PNode_002DACC8 m18;
};

extern "C" void func_002DACC8(Obj_002DACC8* obj, int solo)
{
    TIt_002DACC8 ti;
    PIt_002DACC8 pi;
    Head_002DACC8 list;
    LIt_002DACC8 li;
    void* info = D_00392068->m10;
    Entry_002DACC8* e;
    if (solo) {
        for (Player_002DACC8* p = pi.First(&obj->m18); p; p = pi.Next()) {
            e = func_002DB438(func_001046B0(0x44));
            e->m8 = p->m38;
            e->m3C = p->m3C;
            e->m40 = p->m38;
            func_00331A9C(e->name, p->name);
            list.InsertSorted(e);
        }
    } else {
        for (Team_002DACC8* t = ti.First(obj); t; t = ti.Next()) {
            for (Player_002DACC8* p = pi.First(&t->m1C); p; p = pi.Next()) {
                e = func_002DB438(func_001046B0(0x44));
                e->m8 = p->m3C;
                e->m3C = p->m3C;
                e->m38 = t->m18;
                e->m40 = p->m38;
                func_00331A9C(e->name, p->name);
                list.InsertSorted(e);
            }
        }
    }
    int k = 0;
    for (e = li.First(&list); e && e->m3C && k != 50; e = li.Next()) {
        Params_002DACC8* s = func_001E6978(func_001190D0(8));
        func_001E7268(s, D_00392ED8, e->m40);
        func_001E7268(s, D_00392E90, e->m3C);
        func_001E7268(s, D_00392EE0, (int)(e->m40 * (1.0f / 290.0f)));
        func_001E7138(s, D_00392EE8, e->name);
        if (solo) {
            func_001F0210(0x0AC09E3B, s, 0, 0, 0);
        } else {
            func_001E7138(s, D_00392EC8, func_002DA190(info, e->m38));
            func_001F0210(0x19F7BC28, s, 0, 0, 0);
        }
        if (s)
            func_001E6AE8(s, 3);
        k++;
    }
    e = li.First(&list);
    while (e) {
        Entry_002DACC8* n = li.Next();
        delete e;
        e = n;
    }
}
