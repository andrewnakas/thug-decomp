extern char D_0037C690[];

struct Base_002D8070 {
    char pad[0x14];
    virtual ~Base_002D8070();
};

struct Node_002D8070 {
    int m0;
    Base_002D8070* data;
    int m8;
    Node_002D8070* next;
    Base_002D8070* GetData() { return data; }
    Node_002D8070* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D8070 {
    int m0;
    Node_002D8070* cur;
    void* vt;
    It_002D8070() { vt = D_0037C690; cur = 0; }
    ~It_002D8070() { vt = D_0037C690; }
    Base_002D8070* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002D8070* Advance(Node_002D8070* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Base_002D8070* First(Node_002D8070* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002D8070;
extern "C" void func_002E89D0(Obj_002D8070* o);
extern "C" void func_001048F0(void* p);

struct Obj_002D8070 {
    char pad[0xC];
    void* mC;
    int m10;
    Node_002D8070 m14;
    void Clear();
};

void Obj_002D8070::Clear()
{
    It_002D8070 it;
    func_002E89D0(this);
    func_001048F0(mC);
    m10 = 0;
    Base_002D8070* d = it.First(&m14);
    if (d) {
        It_002D8070* p = &it;
        do {
            Base_002D8070* nx = p->Advance(it.cur);
            delete d;
            d = nx;
        } while (d);
    }
}
