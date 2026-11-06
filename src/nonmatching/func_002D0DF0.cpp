/* fuzzy: 94.7 */
/* nonmatch func_002D0DF0: best earlier draft (thug-claude-lane3/work/kz/func_002D0DF0.cpp), 104 of 152 words differ (size 0x25c, want 0x260). */
extern char D_0037BDC0[];
extern char D_0037B938[];
extern char D_0037B770[];
extern char D_00392B70[];
extern char D_0037B968[];
extern char D_00392B20[];
extern char D_00392B78[];
extern char D_0037B920[];

struct Item_002D0DF0;

struct Node_002D0DF0 {
    int m0;
    Item_002D0DF0* m4;
    int m8;
    Node_002D0DF0* mC;
    Node_002D0DF0* m10;
    Item_002D0DF0* GetData() { return m4; }
    void Link(Node_002D0DF0* head) {
        m10 = head->m10;
        mC = head;
        head->m10->mC = this;
        head->m10 = this;
    }
    Node_002D0DF0* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
};

struct Item_002D0DF0 : Node_002D0DF0 {
    char pad14[4];
    char m18[0x58 - 0x18];
    char m58[8];
    int m60;
};

struct Iter_002D0DF0 {
    int m0;
    Node_002D0DF0* m4;
    void* m8;
    Iter_002D0DF0() { m8 = D_0037BDC0; m4 = 0; }
    ~Iter_002D0DF0() { m8 = D_0037BDC0; }
    Item_002D0DF0* Next() {
        m4 = m4->mC->Valid();
        if (!m4) return 0;
        return m4->GetData();
    }
    Item_002D0DF0* First(Node_002D0DF0* head) {
        m4 = head;
        return Next();
    }
};

struct List_002D0DF0 {
    char pad[0x18];
    Node_002D0DF0 m18;
};

struct Pool_002D0DF0 {
    char pad[0x104];
    int m104;
};

extern Pool_002D0DF0* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_00336228(char* a, char* b);
extern "C" unsigned int func_00306CA8(void* self, char* name, int a, char* out);
extern "C" void* func_001046B0(int size);
extern "C" Item_002D0DF0* func_002D3D78(void* p);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_002D0198(List_002D0DF0* l, Item_002D0DF0* n);
extern "C" int func_002D3D40(List_002D0DF0* l, char* name);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002D0DF0 {
    void Add(int unused, char* name, List_002D0DF0* l);
};

void Obj_002D0DF0::Add(int unused, char* name, List_002D0DF0* l)
{
    char buf[1024];
    Iter_002D0DF0 it;
    func_0010A950(D_00388A70, D_00388A70->m104);
    for (Item_002D0DF0* e = it.First(&l->m18); e; e = it.Next()) {
        if (!func_00336228(e->m18, name)) {
            func_00306CA8(this, name, 0, e->m58);
            func_0010A9B0(D_00388A70);
            e->m60 = 1;
            return;
        }
    }
    Item_002D0DF0* n = func_002D3D78(func_001046B0(0x64));
    func_00331A9C(n->m18, name);
    func_00306CA8(this, name, 0, n->m58);
    n->m60 = 1;
    n->Link(&l->m18);
    func_001F0370(D_0037B938, 0, 0, 0);
    func_002D0198(l, n);
    func_001F0370(D_0037B770, 0, 0, 0);
    func_003331D0(buf, D_00392B70, func_002D3D40(l, name), func_001E54B8(D_0037B968, 0));
    void* s = func_001E6978(func_001190D0(8));
    func_001E7138(s, D_00392B20, buf);
    func_001E73C8(s, D_00392B78, 0);
    func_001F0370(D_0037B920, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);
    func_0010A9B0(D_00388A70);
}
