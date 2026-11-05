struct Mgr_0010F5B0 {
    char pad[0x114];
    int m114;
};

extern Mgr_0010F5B0* D_00388A70;
extern "C" void func_0010A950(Mgr_0010F5B0* mgr, int v);
extern "C" void func_0010A9B0(Mgr_0010F5B0* mgr);
extern "C" void* func_0010E1E8(const char* name, int* size, int a, int b);

struct Obj_0010F5B0;
extern "C" void func_0010F408(Obj_0010F5B0* self, int arg, int size);

struct Obj_0010F5B0 {
    int m0;
    int m4;
    void* m8;
    void* mC;
    void Load(const char* name, int arg);
};

void Obj_0010F5B0::Load(const char* name, int arg)
{
    int size;
    func_0010A950(D_00388A70, D_00388A70->m114);
    mC = m8 = func_0010E1E8(name, &size, 0, 0);
    func_0010A9B0(D_00388A70);
    func_0010F408(this, arg, size);
}
