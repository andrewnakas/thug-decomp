extern char D_0037BDC0[];
extern char D_0037B770[];
extern char D_00392B80[];
extern char D_0037B980[];
extern char D_00392B70[];
extern char D_0037B998[];
extern char D_00392B20[];
extern char D_00392B88[];
extern char D_0037B920[];
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" int func_001F0D78(char* s);
extern "C" int func_003331D0(char* d, const char* fmt, ...);
extern "C" int func_001E54B8(char* s, int v);
extern "C" char* func_002D3D40(void* o, char* name);
extern "C" int func_00336228(char* a, char* b);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct DBase_002D1170 {
    char pad0[0x14];
    virtual ~DBase_002D1170();
};

struct Data_002D1170 : DBase_002D1170 {
    char m18[0x40];
};

struct Node_002D1170 {
    int m0;
    Data_002D1170* data;
    int m8;
    Node_002D1170* next;
    Data_002D1170* GetData() { return data; }
    Node_002D1170* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D1170 {
    int m0;
    Node_002D1170* cur;
    void* vt;
    It_002D1170() { vt = D_0037BDC0; cur = 0; }
    ~It_002D1170() { vt = D_0037BDC0; }
    Data_002D1170* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D1170* First(Node_002D1170* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002D1170 {
    char pad0[0x18];
    Node_002D1170 m18;
};

void func_002D1170(void* a, void* b, char* name, void* c, Obj_002D1170* o)
{
    char buf[0x400];
    void* s;
    It_002D1170 it;
    for (Data_002D1170* d = it.First(&o->m18); d; d = it.Next()) {
        if (!func_00336228(d->m18, name)) {
            s = func_001E6978(func_001190D0(8));
            func_001E73C8(s, D_00392B80, func_001F0D78(name));
            func_001F0370(D_0037B980, s, 0, 0);
            delete d;
            if (s) func_001E6AE8(s, 3);
            func_001F0370(D_0037B770, 0, 0, 0);
            break;
        }
    }
    char* x = func_002D3D40(o, name);
    func_003331D0(buf, D_00392B70, x, func_001E54B8(D_0037B998, 0));
    s = func_001E6978(func_001190D0(8));
    func_001E7138(s, D_00392B20, buf);
    func_001E73C8(s, D_00392B88, 0);
    func_001F0370(D_0037B920, s, 0, 0);
    if (s) func_001E6AE8(s, 3);
}
