extern char D_0037BD78[];

struct Base_002D2DB8 {
    char pad[0x14];
    virtual ~Base_002D2DB8();
};

struct Node_002D2DB8 {
    int m0;
    Base_002D2DB8* data;
    int m8;
    Node_002D2DB8* next;
    Base_002D2DB8* GetData() { return data; }
    Node_002D2DB8* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D2DB8 {
    int m0;
    Node_002D2DB8* cur;
    void* vt;
    It_002D2DB8() { vt = D_0037BD78; cur = 0; }
    ~It_002D2DB8() { vt = D_0037BD78; }
    Base_002D2DB8* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002D2DB8* Advance(Node_002D2DB8* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002D2DB8* First(Node_002D2DB8* h) {
        cur = h;
        return Next();
    }
};

struct Heap_002D2DB8 {
    char pad[0x104];
    int m104;
};
extern Heap_002D2DB8* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_00306790(void* p);

struct Obj_002D2DB8 : Node_002D2DB8 {
    char pad10[0x158 - 0x10];
    void* m158;
    void Clear();
};

void Obj_002D2DB8::Clear()
{
    It_002D2DB8 it;
    func_0010A950(D_00388A70, D_00388A70->m104);
    if (m158) func_00306790(m158);
    Base_002D2DB8* d = it.First(this);
    if (d) {
        It_002D2DB8* p = &it;
        do {
            Base_002D2DB8* nx = p->Advance(it.cur);
            delete d;
            d = nx;
        } while (d);
    }
    func_0010A9B0(D_00388A70);
}
