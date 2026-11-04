struct Mgr_002D98A0 {
    char pad0[0x10];
    char* m10;
};

struct Obj_002D98A0 {
    char pad0[0x18];
    void* m18;
};

extern Mgr_002D98A0* D_00392068;
extern "C" int func_002DA2A8(char* p);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool func_002D98A0(void* params, Obj_002D98A0* o)
{
    int n = func_002DA2A8(D_00392068->m10 + 0x14);
    func_001E7200(o->m18, 0x7786171A, (int)(n * 0.003448275849f));
    return true;
}
