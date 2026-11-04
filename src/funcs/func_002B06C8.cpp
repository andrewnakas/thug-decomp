struct P_002B06C8 {
    signed char m0;
    char pad[3];
    int m4;
};

struct Item_002B06C8 {
    char pad[0x30];
    int m30;
    char m34[0x10];
};

extern "C" void* func_00240850();
extern "C" void* func_0023BAD8(void* p, int id, int v);
extern "C" Item_002B06C8* func_002A52F0(void* s, unsigned short id);
extern "C" Item_002B06C8* func_002A56E0(void* s);
extern "C" void func_00246D18(void* p, int* out);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E70C0(void* p, unsigned int name, char* s);
extern "C" void func_001F0210(unsigned int name, void* a, int b, int c, int d);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002B06C8 {
    P_002B06C8* m0;
    char pad[0x18];
    void* m1C;
    bool Notify();
};

bool Obj_002B06C8::Notify()
{
    P_002B06C8* p = m0;
    void* s = m1C;
    void* x = func_0023BAD8(func_00240850(), p->m4, 1);
    if (x) {
        int v = 0;
        Item_002B06C8* it = func_002A52F0(s, p->m0);
        if (func_002A56E0(s)->m30 == it->m30) {
            func_00246D18(x, &v);
            void* e = func_001E6978(func_001190D0(8));
            func_001E70C0(e, 0x9196D920, it->m34);
            func_001E70C0(e, 0xB8A88B50, (char*)v);
            func_001F0210(0xA77758DE, e, 0, 0, 0);
            if (e) {
                func_001E6AE8(e, 3);
            }
        }
    }
    return true;
}
