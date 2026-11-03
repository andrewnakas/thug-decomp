struct A_002B1108 {
    char pad[0x18];
    void* m18;
};
struct B_002B1108 {
    char pad[0x1C];
    void* m1C;
};

extern void* D_0038FC78;
extern char D_00379590[];
struct T_002B1108;
extern "C" void* func_002A56E0(T_002B1108* t);
extern "C" void* func_0022E358(void* g);
extern "C" int func_0024F938(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" int func_002B1FE8(void* it);
extern "C" void* func_00240850();
extern "C" void func_0023DB90(void* p, int v);
extern "C" A_002B1108* func_002A52F0(void* t, unsigned short v);
extern "C" B_002B1108* func_00185578(void* p, unsigned int crc);
extern "C" void func_002392B8(void* p);

struct T_002B1108 { int m0; };
void func_002B1108(T_002B1108* self, int v)
{
    void* g = D_0038FC78;
    void* it = func_002A56E0(self);
    int t = func_0024F938(func_0022E358(g));
    if (t == func_001F0D78(D_00379590)) {
        if (!func_002B1FE8(it)) {
            func_0023DB90(func_00240850(), v);
            return;
        }
    }
    func_002392B8(func_00185578(func_002A52F0(self, v)->m18, 0xD262802F)->m1C);
}
