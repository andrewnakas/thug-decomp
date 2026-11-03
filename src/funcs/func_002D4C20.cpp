extern char D_0037C198[];

struct Base_002D4C20 {
    char pad[0x14];
    virtual ~Base_002D4C20();
};

struct Node_002D4C20 {
    int m0;
    Base_002D4C20* data;
    int m8;
    Node_002D4C20* next;
    Base_002D4C20* GetData() { return data; }
    Node_002D4C20* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D4C20 {
    int m0;
    Node_002D4C20* cur;
    void* vt;
    It_002D4C20() { vt = D_0037C198; cur = 0; }
    ~It_002D4C20() { vt = D_0037C198; }
    Base_002D4C20* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002D4C20* Advance(Node_002D4C20* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002D4C20* First(Node_002D4C20* h) {
        cur = h;
        return Next();
    }
};

extern "C" void func_002E4550();

struct Obj_002D4C20 {
    char pad[0x350];
    Node_002D4C20 m350;
    void Clear();
};

void Obj_002D4C20::Clear()
{
    It_002D4C20 it;
    Base_002D4C20* d = it.First(&m350);
    if (d) {
        It_002D4C20* p = &it;
        do {
            Base_002D4C20* nx = p->Advance(it.cur);
            delete d;
            d = nx;
        } while (d);
    }
    func_002E4550();
}
