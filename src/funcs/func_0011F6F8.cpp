extern "C" int func_001E8180(void* list, unsigned int id, void** out, int req);
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7A68(void* list, unsigned int id, int type, void* s);
extern "C" void func_001E6B30(void* s);
extern "C" int func_001E7DE8(void* s, unsigned int id, int* out, int req);
extern "C" void func_001E7200(void* s, unsigned int id, int v);
extern "C" void func_001E7360(void* s, unsigned int id, int v);

struct C_0011F6F8 {
    char pad[0x48];
    char m48[0xC];
    void Set(unsigned int id, int value, void* params);
};

void C_0011F6F8::Set(unsigned int id, int value, void* params)
{
    void* s;
    if (!func_001E8180(m48, id, &s, 0)) {
        s = func_001E6978(func_001190D0(8));
        func_001E7A68(m48, id, 0xB, s);
    }
    func_001E6B30(s);
    int keep = 1;
    func_001E7DE8(params, 0x97DBDDE6, &keep, 0);
    if (!keep) {
        int a;
        int b;
        int c;
        func_001E7DE8(params, 0x6E94F918, &a, 1);
        func_001E7DE8(params, 0xE4F130F4, &b, 1);
        func_001E7DE8(params, 0x949BC47B, &c, 1);
        func_001E7200(s, 0x97DBDDE6, 0);
        func_001E7200(s, 0x6E94F918, a);
        func_001E7200(s, 0xE4F130F4, b);
        func_001E7200(s, 0x949BC47B, c);
    }
    func_001E7360(s, 0x4BB2084E, value);
}
