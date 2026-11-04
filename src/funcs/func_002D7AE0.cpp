extern char D_0037C690[];
extern char D_00392DB8[];
extern char D_0037C318[];
extern char D_0037C550[];
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" int func_001F0D78(char* s);

struct Base_002D7AE0 {
    char pad[0x14];
    virtual ~Base_002D7AE0();
};

struct Item_002D7AE0 : Base_002D7AE0 {
    char pad18[0x38 - 0x18];
    int m38;
};

struct Node_002D7AE0 {
    int m0;
    Item_002D7AE0* data;
    int m8;
    Node_002D7AE0* next;
    Item_002D7AE0* GetData() { return data; }
    Node_002D7AE0* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D7AE0 {
    int m0;
    Node_002D7AE0* cur;
    void* vt;
    It_002D7AE0() { vt = D_0037C690; cur = 0; }
    ~It_002D7AE0() { vt = D_0037C690; }
    Item_002D7AE0* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Item_002D7AE0* First(Node_002D7AE0* h) {
        cur = h;
        return Next();
    }
};

struct Mgr_002D7AE0 {
    char pad[0x14];
    Node_002D7AE0 m14;
    void Remove(int id);
};

extern "C" void func_002E8D78(Mgr_002D7AE0* m, int id);

void Mgr_002D7AE0::Remove(int id)
{
    It_002D7AE0 it;
    for (Item_002D7AE0* p = it.First(&m14); p; p = it.Next()) {
        if (p->m38 == id) {
            delete p;
            break;
        }
    }
    func_002E8D78(this, id);
    void* s = func_001E6978(func_001190D0(8));
    func_001E73C8(s, D_00392DB8, func_001F0D78(D_0037C318) + id);
    func_001F0370(D_0037C550, s, 0, 0);
    if (s) func_001E6AE8(s, 3);
}
