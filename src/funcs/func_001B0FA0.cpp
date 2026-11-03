extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E69A0(void* mem, void* src);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void func_001AE120(void* comp, unsigned int a, void* b, void* params);

struct Obj_001B0FA0 {
    int m_pad[47];
    void* mBC;
};

int func_001B0FA0(void* params, Obj_001B0FA0* o)
{
    void* comp = func_00185578(o->mBC, 0x270F56E1);
    unsigned int a = 0;
    void* b = 0;
    func_001E8398(params, 0x148FEE96, &a, 0);
    func_001E8180(params, 0x7031F10C, &b, 0);
    void* c = 0;
    func_001E8180(params, 0x31261D2F, &c, 0);
    if (c) {
        void* p = func_001E69A0(func_001190D0(8), c);
        func_001AE120(comp, a, b, p);
        if (p) func_001E6AE8(p, 3);
    } else {
        func_001AE120(comp, a, b, 0);
    }
    return 1;
}
