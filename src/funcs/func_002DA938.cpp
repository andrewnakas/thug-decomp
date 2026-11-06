extern char D_0037C9D0[];
extern char D_0037C9E8[];
extern char D_00392ED0[];
extern char D_00392ED8[];
extern char D_00392E90[];
extern char D_00392EE0[];
extern char D_00392EE8[];
extern char D_00392EC8[];

struct Player_002DA938 {
    char pad[0x18];
    char name[0x20];
    unsigned int m38;
    int m3C;
};

struct PNode_002DA938 {
    int m0;
    Player_002DA938* data;
    int m8;
    PNode_002DA938* next;
    Player_002DA938* GetData() { return data; }
    PNode_002DA938* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
    int Count()
    {
        int n = 0;
        PNode_002DA938* x = next->Valid();
        if (x) {
        again:
            n++;
            x = x->next->Valid();
            if (x)
                goto again;
        }
        return n;
    }
};

struct Team_002DA938 {
    char pad[0x18];
    int m18;
    PNode_002DA938 m1C;
};

struct TNode_002DA938 {
    int m0;
    Team_002DA938* data;
    int m8;
    TNode_002DA938* next;
    Team_002DA938* GetData() { return data; }
    TNode_002DA938* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct TIt_002DA938 {
    int m0;
    TNode_002DA938* cur;
    void* vt;
    TIt_002DA938() { vt = D_0037C9D0; cur = 0; }
    ~TIt_002DA938() { vt = D_0037C9D0; }
    Team_002DA938* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Team_002DA938* First(TNode_002DA938* h)
    {
        cur = h;
        return Next();
    }
};

struct PIt_002DA938 {
    int m0;
    PNode_002DA938* cur;
    void* vt;
    PIt_002DA938() { vt = D_0037C9E8; cur = 0; }
    ~PIt_002DA938() { vt = D_0037C9E8; }
    Player_002DA938* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Player_002DA938* First(PNode_002DA938* h)
    {
        cur = h;
        return Next();
    }
};

struct Net_002DA938 {
    char pad[0x10];
    void* m10;
};

struct Params_002DA938;
extern Net_002DA938* D_00392068;
extern "C" int func_002DA7A8(TNode_002DA938* l, int v);
extern "C" void* func_001190D0(int size);
extern "C" Params_002DA938* func_001E6978(void* mem);
extern "C" char* func_002DA190(void* p, int id);
extern "C" char* func_001E54E8(unsigned int name, int a);
extern "C" void func_001E7138(Params_002DA938* p, char* name, char* value);
extern "C" void func_001E7268(Params_002DA938* p, char* name, int value);
extern "C" void func_001F0210(unsigned int name, Params_002DA938* p, int a, int b, int c);
extern "C" void func_001E6AE8(Params_002DA938* p, int flags);

extern "C" void func_002DA938(TNode_002DA938* teams)
{
    TIt_002DA938 ti;
    PIt_002DA938 pi;
    void* info = D_00392068->m10;
    func_002DA7A8(teams, 3);
    for (Team_002DA938* t = ti.First(teams); t; t = ti.Next()) {
        if (t->m1C.Count()) {
            Params_002DA938* p = func_001E6978(func_001190D0(8));
            func_001E7138(p, D_00392ED0, func_002DA190(info, t->m18));
            func_001F0210(0x1AADEE21, p, 0, 0, 0);
            if (p)
                func_001E6AE8(p, 3);
        }
        int k = 0;
        for (Player_002DA938* pl = pi.First(&t->m1C); pl && k < 3; pl = pi.Next()) {
            Params_002DA938* p = func_001E6978(func_001190D0(8));
            func_001E7268(p, D_00392ED8, pl->m38);
            func_001E7268(p, D_00392E90, pl->m3C);
            int scaled = (int)(pl->m38 * (1.0f / 290.0f));
            func_001E7268(p, D_00392EE0, scaled);
            func_001E7138(p, D_00392EE8, pl->name);
            func_001E7138(p, D_00392EC8, func_002DA190(info, t->m18));
            func_001F0210(0x19F7BC28, p, 0, 0, 0);
            if (p)
                func_001E6AE8(p, 3);
            k++;
        }
    }
    Params_002DA938* p = func_001E6978(func_001190D0(8));
    func_001E7138(p, D_00392ED0, func_001E54E8(0xC2283319, 0));
    func_001F0210(0x1AADEE21, p, 0, 0, 0);
    if (p)
        func_001E6AE8(p, 3);
}
