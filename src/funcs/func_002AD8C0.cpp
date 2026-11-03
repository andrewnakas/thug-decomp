struct Obj_002AD8C0_D {
    int m0;
};

struct Obj_002AD8C0 {
    Obj_002AD8C0_D* m0;
    char pad[0x18];
    void* m1C;
    bool Launch();
};

extern char D_00379020[];
extern char D_00379030[];

extern "C" void* func_002A56E0(void* p);
extern "C" void func_002B2290(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

bool Obj_002AD8C0::Launch()
{
    void* t = func_002A56E0(m1C);
    Obj_002AD8C0_D* d = m0;
    func_002B2290(t);
    void* p = func_001E6978(func_001190D0(8));
    func_001E73C8(p, D_00379020, d->m0);
    func_001F0370(D_00379030, p, 0, 0);
    if (p) {
        func_001E6AE8(p, 3);
    }
    return true;
}
