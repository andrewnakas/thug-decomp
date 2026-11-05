struct Params_002325D8;

struct Heap_002325D8 {
    char pad0[0xEC];
    void* m_EC;
};

struct Info_002325D8 {
    unsigned int m_script;
    unsigned int m_objId;
    char m_params[4];
};

struct Args_002325D8 {
    Info_002325D8* m_info;
    char pad4[0x18];
    void* m_world;
};

extern Heap_002325D8* D_00388A70;

extern "C" void func_0010A950(Heap_002325D8* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_002325D8* mgr);
extern "C" void* func_0022E040(void* mgr);
extern "C" void* func_00187B48(void* mgr, unsigned int id);
extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_002325D8* func_001E6978(void* mem);
extern "C" void func_001E9D70(Params_002325D8* p, void* src);
extern "C" void func_001F0210(unsigned int script, Params_002325D8* p, void* obj, int a, int b);
extern "C" void func_001E6AE8(Params_002325D8* p, int flags);

static inline void Delete_002325D8(Params_002325D8* p)
{
    if (p)
        func_001E6AE8(p, 3);
}

bool func_002325D8(Args_002325D8* args)
{
    func_0010A950(D_00388A70, D_00388A70->m_EC);
    Info_002325D8* info = args->m_info;
    void* obj = func_00187B48(func_0022E040(args->m_world), info->m_objId);
    Params_002325D8* p = func_001E6978(func_001190D0(8));
    func_001E9D70(p, info->m_params);
    func_001F0210(info->m_script, p, obj, 0, 0);
    Delete_002325D8(p);
    func_0010A9B0(D_00388A70);
    return true;
}
