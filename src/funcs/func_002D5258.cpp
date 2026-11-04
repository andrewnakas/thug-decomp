struct Pool_002D5258 {
    char pad[0x108];
    int m108;
};

struct Item_002D5258;

struct Node_002D5258 {
    int m0;
    Item_002D5258* data;
    int m8;
    Node_002D5258* next;
    Node_002D5258* prev;
    Item_002D5258* GetData() { return data; }
    Node_002D5258* Valid() { return (int)data != -1 ? this : 0; }
};

struct Name8_002D5258 {
    char c[8];
};

struct Item_002D5258 : Node_002D5258 {
    int m14;
    int m18;
    Name8_002D5258 m1C;
};

struct It_002D5258 {
    int m0;
    Node_002D5258* cur;
    void* vt;
    Item_002D5258* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_002D5258* First(Node_002D5258* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002D5258 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x350 - 0x10];
    Node_002D5258 m350;
    char pad364[4];
    It_002D5258 m368;
    Item_002D5258* m374;
    unsigned int m378;
    char m37C[0x40];
};

struct Glob_002D5258 {
    int m0;
    int m4;
    Obj_002D5258* m8;
    void* mC;
};

extern Glob_002D5258* D_00392068;
extern char* D_0038C308;
extern Pool_002D5258* D_00388A70;
extern char D_00392C68[];
extern char D_00392C70[];
extern char D_00392C78[];
extern char D_00392C80[];
extern Name8_002D5258 D_00392C88[];
extern char D_0037C000[];
extern "C" int func_001E8A30(void* params, int name, unsigned int* out, int a);
extern "C" int func_003331D0(char* d, const char* fmt, ...);
extern "C" int func_002D8158(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int size);
extern "C" Item_002D5258* func_002D63F0(void* p);
extern "C" void func_002D4CF8(Obj_002D5258* o, char* buf);
extern "C" void func_00105260(char* p, int v);
extern "C" void func_002D5050(Obj_002D5258* o);

bool func_002D5258(void* params, void* script)
{
    Glob_002D5258* g = D_00392068;
    Obj_002D5258* o = g->m8;
    char* q = D_0038C308;
    void* r = g->mC;
    char buf[0x80];
    func_001E8A30(params, 0, &o->m378, 1);
    switch (o->m378) {
    case 0x5BE5569F:
        func_003331D0(o->m37C, D_00392C68);
        break;
    case 0x07364EA1:
        func_003331D0(o->m37C, D_00392C70);
        break;
    case 0x38DBE1D0:
        func_003331D0(o->m37C, D_00392C78);
        break;
    case 0x1E26FD3E:
        func_003331D0(o->m37C, D_00392C80);
        break;
    }
    if (func_002D8158(r) == 0x011B0C16) {
        func_0010A950(D_00388A70, D_00388A70->m108);
        Item_002D5258* n = func_002D63F0(func_001046B0(0x4C));
        Node_002D5258* h = &o->m350;
        n->prev = h;
        n->m18 = 1;
        n->next = h->next;
        h->next->prev = n;
        h->next = n;
        n->m1C = D_00392C88[0];
        o->m374 = o->m368.First(h);
        o->mC = 0;
        o->m4 = 5;
        func_003331D0(buf, D_0037C000, o->m37C);
        func_002D4CF8(o, buf);
        func_00105260(q + 8, o->m0);
        func_0010A9B0(D_00388A70);
    } else {
        func_002D5050(o);
    }
    return true;
}
