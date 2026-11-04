extern char D_0037BDC0[];
extern "C" int func_00336228(char* a, char* b);
extern "C" void func_001F0370(char* s, int a, int b, int c);

struct Node_002D1580;
struct Data_002D1580;

struct Node_002D1580 {
    int m0;
    Data_002D1580* data;
    int m8;
    Node_002D1580* next;
    Data_002D1580* GetData() { return data; }
    Node_002D1580* Valid() { return (int)data != -1 ? this : 0; }
    Node_002D1580* prev;
    void Link(Node_002D1580* n) {
        prev = n->prev;
        next = n;
        n->prev->next = this;
        n->prev = this;
    }
};

struct Data_002D1580 : Node_002D1580 {
    char pad14[4];
    char m18[0x40];
    int m58;
};

struct It_002D1580 {
    int m0;
    Node_002D1580* cur;
    void* vt;
    It_002D1580() { vt = D_0037BDC0; cur = 0; }
    ~It_002D1580() { vt = D_0037BDC0; }
    Data_002D1580* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D1580* First(Node_002D1580* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002D1580 {
    char pad0[0x18];
    Node_002D1580 m18;
};

struct Pool_002D1580 {
    char pad[0x108];
    int m108;
};

extern Pool_002D1580* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001046B0(int size);
extern "C" Data_002D1580* func_002D3D78(void* p);
extern "C" void func_00331A9C(char* d, char* s);
extern "C" int func_00306CA8(void* a, char* name, int b, int* out);

void func_002D1580(void* scr, int ok, int a2, int id, char* name, int t1, Obj_002D1580* o)
{
    It_002D1580 it;
    if (!ok) return;
    if (id == -1) return;
    Data_002D1580* d;
    for (d = it.First(&o->m18); d; d = it.Next()) {
        if (!func_00336228(d->m18, name)) return;
    }
    func_0010A950(D_00388A70, D_00388A70->m108);
    d = func_002D3D78(func_001046B0(0x64));
    func_00331A9C(d->m18, name);
    func_00306CA8(scr, name, 0, &d->m58);
    d->Link(&o->m18);
    func_0010A9B0(D_00388A70);
}
