struct Obj_0028E928_C {
    char pad0[0x14];
    void* m14;
};

struct Obj_0028E928_D {
    char pad0[0x138];
    int m138;
};

struct Obj_0028E928 {
    char pad0[0xC];
    Obj_0028E928_C* mC;
    char pad10[0x42C - 0x10];
    int m42C;
    char pad430[0x5B0 - 0x430];
    Obj_0028E928_D* m5B0;
    int Setup(int n, int a, int b, int c, int d);
};

extern "C" void* func_001E55B8(unsigned int id, int v);
extern "C" void* func_001E93A0(void* p, int n);
extern "C" void* func_001E9300(void* p, int flags);
extern "C" void* func_00185578(void* p, unsigned int id);
extern "C" void func_002919B0(void* p);
extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* p);
extern "C" void func_001EE8C8(void* p, void* q, int v, void* r);
extern "C" int func_001EFDC0(void* p);

int Obj_0028E928::Setup(int n, int a, int b, int c, int d)
{
    int idx = 0;
    switch (n) {
    case 0: idx = 0; break;
    case 1: idx = 1; break;
    case 2: idx = 2; break;
    case 3: idx = 3; break;
    case 4: idx = 4; break;
    case 5: idx = 5; break;
    case 6: idx = 6; break;
    case 7: idx = 7; break;
    case 8: idx = 8; break;
    }
    void* r = func_001E93A0(func_001E55B8(0x2AB3341D, 0), idx);
    int flags = 0;
    if (a) flags |= 1;
    m42C = 0;
    if (b) flags |= 2;
    if (c) flags |= 4;
    if (d) flags |= 8;
    func_002919B0(func_00185578(mC, 0x488AF07A));
    Obj_0028E928_C* cc = mC;
    if (cc->m14 == 0) {
        cc->m14 = func_001EE428(func_00121960(0xF4));
    }
    void* q = mC->m14;
    func_001EE8C8(q, func_001E9300(r, flags), 0, mC);
    int ret = func_001EFDC0(mC->m14);
    m5B0->m138 = 1;
    return ret;
}
