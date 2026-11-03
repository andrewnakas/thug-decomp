extern char D_00379E70[];

struct Srv_002B4BF8 {
    char pad[0x14];
    virtual ~Srv_002B4BF8();
};

struct Node_002B4BF8 {
    int m0;
    Srv_002B4BF8* data;
    int m8;
    Node_002B4BF8* next;
    int m10;
    Srv_002B4BF8* GetData() { return data; }
    Node_002B4BF8* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002B4BF8 {
    int m0;
    Node_002B4BF8* cur;
    void* vt;
    It_002B4BF8() { vt = D_00379E70; cur = 0; }
    ~It_002B4BF8() { vt = D_00379E70; }
    Srv_002B4BF8* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Srv_002B4BF8* Advance(Node_002B4BF8* c)
    {
        cur = c->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Srv_002B4BF8* First(Node_002B4BF8* h)
    {
        cur = h;
        return Next();
    }
};

struct Mgr_002B4BF8 {
    char pad[0x124];
    Node_002B4BF8 m124;
    char pad138[4];
    Node_002B4BF8 m13C;
    void Clear();
};

extern "C" int func_002A1A18(Mgr_002B4BF8* m);
extern "C" void func_002A3950(Mgr_002B4BF8* m);

void Mgr_002B4BF8::Clear()
{
    It_002B4BF8 it;
    Srv_002B4BF8* s;
    s = it.First(&m13C);
    if (s) {
        It_002B4BF8* p = &it;
        do {
            Srv_002B4BF8* n = p->Advance(it.cur);
            delete s;
            s = n;
        } while (s);
    }
    s = it.First(&m124);
    if (s) {
        It_002B4BF8* q = &it;
        do {
            Srv_002B4BF8* n = q->Advance(it.cur);
            delete s;
            s = n;
        } while (s);
    }
    if (func_002A1A18(this))
        func_002A3950(this);
}
