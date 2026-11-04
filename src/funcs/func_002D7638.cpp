extern char D_0037C690[];
extern char D_0037C500[];
extern "C" void func_001F0370(char* s, int a, int b, int c);

struct Item_002D7638 {
    char pad[0x40];
    int m40;
};

struct Node_002D7638 {
    int m0;
    Item_002D7638* data;
    int m8;
    Node_002D7638* next;
    Item_002D7638* GetData() { return data; }
    Node_002D7638* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D7638 {
    int m0;
    Node_002D7638* cur;
    void* vt;
    It_002D7638() { vt = D_0037C690; cur = 0; }
    ~It_002D7638() { vt = D_0037C690; }
    Item_002D7638* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_002D7638* First(Node_002D7638* h) {
        cur = h;
        return Next();
    }
};

struct Mgr_002D7638 {
    char pad[0x14];
    Node_002D7638 m14;
    void Run(int dbg, int a, int b);
};

extern "C" void func_002D72E8(Mgr_002D7638* m, Item_002D7638* it, int a, int b);

void Mgr_002D7638::Run(int dbg, int a, int b)
{
    It_002D7638 it;
    if (dbg) func_001F0370(D_0037C500, 0, 0, 0);
    for (Item_002D7638* p = it.First(&m14); p; p = it.Next()) {
        if (!p->m40) func_002D72E8(this, p, a, b);
    }
}
