struct P_002B0CD0 {
    unsigned int m0;
    unsigned int m4;
};

struct Item_002B0CD0 {
    char pad[0x34];
    char m34[0x10];
};

extern "C" Item_002B0CD0* func_002A5248(void* s, int id);
extern "C" int func_002A8580(void* s);
extern "C" void func_002A8588(void* s);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E70C0(void* p, unsigned int name, char* s);
extern "C" void func_001F0210(unsigned int name, void* a, int b, int c, int d);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002B0CD0 {
    P_002B0CD0* m0;
    char pad[0x10];
    int m14;
    int m18;
    void* m1C;
    bool Check();
};

bool Obj_002B0CD0::Check()
{
    void* s = m1C;
    Item_002B0CD0* it = func_002A5248(s, m14);
    P_002B0CD0* p = m0;
    if ((p->m0 ^ 0xDEADFACE) != p->m4 && !func_002A8580(s)) {
        void* e = func_001E6978(func_001190D0(8));
        func_001E70C0(e, 0xA4B08520, it->m34);
        func_001F0210(0x62DDBE0A, e, 0, 0, 0);
        if (e) {
            func_001E6AE8(e, 3);
        }
        func_002A8588(s);
    }
    return true;
}
