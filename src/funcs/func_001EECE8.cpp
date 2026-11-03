struct Heap_001EECE8 {
    char pad[0xEC];
    int mEC;
};
extern Heap_001EECE8* D_00388A70;
extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void* func_0010BDE0(unsigned int);
extern "C" void* func_001190D0(unsigned int);
extern "C" void* func_001E6978(void*);
extern "C" int func_001ED6B8(void*, int, int);
extern "C" void func_001E6A50(void*, void*);
extern "C" void func_00183CB8(void*, void*);
extern "C" void func_00183C98(void*, void*);

struct Frame_001EECE8 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
};

struct Ref_001EECE8 {
    void* p;
    void Clear()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
    void Set(void* o)
    {
        p = o;
        if (o)
            func_00183C98(o, this);
    }
};

struct Script_001EECE8 {
    char pad0[0x10];
    int m10;
    int m14;
    int m18;
    int m1C;
    char pad20[0x38 - 0x20];
    int m38;
    Frame_001EECE8 m3C[2];
    Frame_001EECE8* m94;
    int m98;
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    int padAC;
    int mB0;
    int padB4[2];
    Ref_001EECE8 mBC;
    int padC0[2];
    int mC8;
    void Run(int name, int code, void* params, void* obj, int flag);
};

extern "C" void func_001EE640(Script_001EECE8*, int, int, void*, void*);
extern "C" void func_001EE5E8(Script_001EECE8*);

void Script_001EECE8::Run(int name, int code, void* params, void* obj, int flag)
{
    if (!m10) {
        func_001EE640(this, name, code, params, obj);
        mB0 = flag;
        return;
    }
    Frame_001EECE8* old = m94;
    if (old == m3C && m38 == 2) {
        func_0010A950(D_00388A70, D_00388A70->mEC);
        m94 = (Frame_001EECE8*)func_0010BDE0(0x2C0);
        func_0010A9B0(D_00388A70);
        Frame_001EECE8* src = old;
        for (int i = 0; i < 2; i++)
            m94[i] = *src++;
    }
    Frame_001EECE8* f = &m94[m38];
    m38++;
    f->f0 = mC8;
    f->f4 = m18;
    f->f8 = m10;
    f->fC = (int)mBC.p;
    f->f10 = m1C;
    f->f14 = mA4;
    f->f18 = mA8;
    f->f1C = m98;
    f->f24 = mA0;
    f->f20 = m9C;
    f->f28 = mB0;
    mC8 = name;
    m10 = code;
    m18 = (int)func_001E6978(func_001190D0(8));
    m10 = func_001ED6B8((void*)m18, m10, 0);
    if (params)
        func_001E6A50((void*)m18, params);
    mBC.Clear();
    mBC.Set(obj);
    func_001EE5E8(this);
    mB0 = flag;
}
