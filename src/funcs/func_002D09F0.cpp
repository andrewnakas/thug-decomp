extern char D_0037BDC0[];
extern char D_0037B7D0[];
extern "C" void func_001F0370(char* s, int a, int b, int c);

struct Mgr_002D09F0 {
    char pad0[0xC];
    void* mC;
};

extern Mgr_002D09F0* D_00392068;
extern "C" int func_002D8158(void* p);
extern "C" int func_002D8160(void* p, int v);

struct Data_002D09F0 {
    char pad0[0x58];
    int m58;
};

struct Node_002D09F0 {
    int m0;
    Data_002D09F0* data;
    int m8;
    Node_002D09F0* next;
    Data_002D09F0* GetData() { return data; }
    Node_002D09F0* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D09F0 {
    int m0;
    Node_002D09F0* cur;
    void* vt;
    It_002D09F0() { vt = D_0037BDC0; cur = 0; }
    ~It_002D09F0() { vt = D_0037BDC0; }
    Data_002D09F0* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D09F0* First(Node_002D09F0* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002D09F0;
extern "C" void func_002D0858(Obj_002D09F0* o, Data_002D09F0* d);

struct Obj_002D09F0 {
    char pad0[0x18];
    Node_002D09F0 m18;
    void Check();
};

void Obj_002D09F0::Check()
{
    Mgr_002D09F0* mgr = D_00392068;
    It_002D09F0 it;
    func_001F0370(D_0037B7D0, 0, 0, 0);
    for (Data_002D09F0* d = it.First(&m18); d; d = it.Next()) {
        if (d->m58 != func_002D8158(mgr->mC) && d->m58 > 0 && !func_002D8160(mgr->mC, d->m58))
            func_002D0858(this, d);
    }
}
