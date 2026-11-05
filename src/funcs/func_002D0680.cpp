extern char D_0037BDC0[];

struct Base_002D0680 {
    char pad[0x14];
    virtual ~Base_002D0680();
};

struct Node_002D0680 {
    int m0;
    Base_002D0680* data;
    int m8;
    Node_002D0680* next;
    Base_002D0680* GetData() { return data; }
    Node_002D0680* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D0680 {
    int m0;
    Node_002D0680* cur;
    void* vt;
    It_002D0680() { vt = D_0037BDC0; cur = 0; }
    ~It_002D0680() { vt = D_0037BDC0; }
    Base_002D0680* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002D0680* Advance(Node_002D0680* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002D0680* First(Node_002D0680* h) {
        cur = h;
        return Next();
    }
};

extern char D_0037B770[];
extern "C" void func_001F0370(char* s, int a, int b, int c);

struct Obj_002D0680 {
    char pad[0x18];
    Node_002D0680 m18;
    void Clear();
};

void Obj_002D0680::Clear()
{
    It_002D0680 it;
    Base_002D0680* d = it.First(&m18);
    It_002D0680* p = &it;
    while (d) {
        Base_002D0680* nx = p->Advance(it.cur);
        delete d;
        d = nx;
    }
    func_001F0370(D_0037B770, 0, 0, 0);
}
