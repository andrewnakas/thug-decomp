extern char D_0037BDC0[];
extern char D_0037B9B0[];
extern char D_0037B9C0[];
extern char D_00392B40[];
extern char D_00392B48[];

struct Data_002D1390 {
    char pad0[0x18];
    char name[0x5C - 0x18];
    int m5C;
};

struct Node_002D1390 {
    int m0;
    Data_002D1390* data;
    int m8;
    Node_002D1390* next;
    Data_002D1390* GetData() { return data; }
    Node_002D1390* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct It_002D1390 {
    int m0;
    Node_002D1390* cur;
    void* vt;
    It_002D1390() { vt = D_0037BDC0; cur = 0; }
    ~It_002D1390() { vt = D_0037BDC0; }
    Data_002D1390* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D1390* Advance(Node_002D1390* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D1390* First(Node_002D1390* h) {
        cur = h;
        return Next();
    }
};

struct Owner_002D1390 {
    char pad0[0x18];
    Node_002D1390 m18;
};

extern "C" int func_00336228(const char* a, const char* b);
extern "C" int func_00334120(char* s);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

void func_002D1390(void* a0, void* a1, void* a2, char* name, int n, char** type, char** val, Owner_002D1390* o)
{
    for (int i = 0; i < n; i++) {
    }
    if (n > 0) {
        It_002D1390 it;
        if (*type && !func_00336228(*type, D_0037B9B0)) {
            for (Data_002D1390* d = it.First(&o->m18); d; d = it.Next()) {
                if (!func_00336228(d->name, name)) {
                    int v = func_00334120(*val);
                    d->m5C = v;
                    int x = (int)(v * 0.003448275849f);
                    void* s = func_001E6978(func_001190D0(8));
                    func_001E73C8(s, D_00392B48, func_001F0D78(d->name));
                    func_001E7268(s, D_00392B40, x);
                    func_001F0370(D_0037B9C0, s, 0, 0);
                    if (s)
                        func_001E6AE8(s, 3);
                }
            }
        }
    }
}
