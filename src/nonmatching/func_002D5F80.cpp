/* fuzzy: 90.8 */
/* nonmatch func_002D5F80: best earlier draft (thug-claude-lane3/work/w53/p1/func_002D5F80.fail), 39 of 196 words differ. */
extern char D_0037C180[];

struct LNode_002D5F80 {
    int m0;
    int data;
    int m8;
    LNode_002D5F80* next;
    LNode_002D5F80* prev;
    bool IsHead() { return data == -1; }
};

struct Search_002D5F80 {
    int m0;
    LNode_002D5F80* cur;
    void* m8;
    Search_002D5F80() { m8 = D_0037C180; cur = 0; }
    ~Search_002D5F80() { m8 = D_0037C180; }
    int Next()
    {
        LNode_002D5F80* n = cur->next;
        LNode_002D5F80* r = 0;
        if (!n->IsHead()) r = n;
        cur = r;
        if (r) return r->data;
        return 0;
    }
    int First(LNode_002D5F80* head)
    {
        cur = head;
        return Next();
    }
};

struct Info_002D5F80 {
    char pad0[0x18];
    char m18[0x98 - 0x18];
    char m98[0xB0 - 0x98];
    char mB0[0x10];
    char mC0[0xF1 - 0xC0];
    char mF1[0x1F4 - 0xF1];
    int m1F4;
    int m1F8;
    int m1FC;
    int m200;
    int m204;
    int m208;
    int m20C;
    int m210;
    int m214;
};

struct Lobby_002D5F80 {
    char pad0[0x34];
    LNode_002D5F80 list;
};

struct Mgr_002D5F80 {
    char pad0[0x374];
    Lobby_002D5F80* m374;
    unsigned int m378;
};

struct Pool_002D5F80 {
    char pad0[0x104];
    int m104;
};

struct Glob_002D5F80 {
    char pad0[0x8];
    Mgr_002D5F80* m8;
};

extern Pool_002D5F80* D_00388A70;
extern Glob_002D5F80* D_00392068;
extern char D_00392D10[];
extern char D_00392D18[];
extern char D_00392D20[];
extern char D_00392CD8[];
extern char D_0037C060[];
extern char D_0037C070[];
extern char D_00392C98[];
extern char D_00392CA0[];
extern char D_0037C080[];
extern char D_00392CA8[];
extern char D_0037C090[];
extern char D_00392CC0[];
extern char D_0037C0C0[];
extern char D_00392C58[];
extern char D_0037BF68[];
extern char D_0037C160[];
extern char D_0037C128[];
extern char D_0037C148[];
extern char D_0037C110[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E7860(void* p, char* name, void* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct Obj_002D5F80 {
    bool List();
};

bool Obj_002D5F80::List()
{
    Search_002D5F80 sh;
    Mgr_002D5F80* mgr = D_00392068->m8;
    func_0010A950(D_00388A70, D_00388A70->m104);
    for (Info_002D5F80* e = (Info_002D5F80*)sh.First(&mgr->m374->list); e; e = (Info_002D5F80*)sh.Next()) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E7138(p, D_00392D10, e->m98);
        func_001E7138(p, D_00392D18, e->mB0);
        func_001E7138(p, D_00392D20, e->mC0);
        func_001E7268(p, D_00392CD8, e->m1F4);
        func_001E7268(p, D_0037C060, e->m200);
        func_001E7268(p, D_0037C070, e->m204);
        func_001E7268(p, D_00392C98, e->m1F8);
        func_001E7268(p, D_00392CA0, e->m1FC);
        func_001E7268(p, D_0037C080, e->m208);
        func_001E7268(p, D_00392CA8, e->m20C);
        func_001E73C8(p, D_0037C090, e->m210);
        func_001E7268(p, D_00392CC0, e->m214);
        func_001E7138(p, D_0037C0C0, e->mF1);
        void* q = func_001E6978(func_001190D0(8));
        func_001E7138(q, D_00392C58, e->m18);
        func_001E7860(p, D_0037BF68, q);
        switch (mgr->m378) {
        case 0x5BE5569F:
            func_001F0370(D_0037C110, p, 0, 0);
            break;
        case 0x07364EA1:
            func_001F0370(D_0037C128, p, 0, 0);
            break;
        case 0x38DBE1D0:
            func_001F0370(D_0037C148, p, 0, 0);
            break;
        case 0x1E26FD3E:
            func_001F0370(D_0037C160, p, 0, 0);
            break;
        }
        if (p) func_001E6AE8(p, 3);
        if (q) func_001E6AE8(q, 3);
    }
    func_0010A9B0(D_00388A70);
    return true;
}
