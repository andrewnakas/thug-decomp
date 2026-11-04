extern int D_0038F670;
extern void* D_0038C354;
extern void* D_0038C608;
extern char D_0038F368[];
extern char D_00370CD0[];

struct Obj_002173F0 {
    char pad[0xC];
    unsigned int m_flags;
};

extern "C" void* func_001046B0(int size);
extern "C" void* func_0022BC20(void* mem);
extern "C" void func_00182E38(void* mgr, void* task);
extern "C" void func_00182E88(void* mgr, void* task);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E73C8(void* s, char* str, unsigned int name);
extern "C" unsigned int func_001E55F8(char* str, int a);
extern "C" Obj_002173F0* func_00186D60(void* mgr, unsigned int name, void* params, int a);
extern "C" void func_001E6AE8(void* s, int flags);

bool func_002173F0()
{
    void* mgr = D_0038C354;
    if (D_0038F670) {
        return true;
    }
    void* task = func_0022BC20(func_001046B0(0x70));
    func_00182E38(mgr, task);
    func_00182E88(mgr, task);
    D_0038F670 = 1;
    void* params = func_001E6978(func_001190D0(8));
    func_001E73C8(params, D_0038F368, 0xEB17151B);
    void* objs = D_0038C608;
    Obj_002173F0* o = func_00186D60(objs, func_001E55F8(D_00370CD0, 0), params, 1);
    if (params) {
        func_001E6AE8(params, 3);
    }
    o->m_flags |= 2;
    return true;
}
