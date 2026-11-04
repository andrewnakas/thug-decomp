struct Params_002102F8;

struct Script_002102F8 {
    char pad0[0x18];
    void* m_params;
    char pad1C[0xA0];
    int m_BC;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_002102F8* func_001E6978(void* mem);
extern "C" void func_001E6AC8(Params_002102F8* p, void* src);
extern "C" void func_001E6AE8(Params_002102F8* p, int flags);
extern "C" void func_001EE8C8(Script_002102F8* script, unsigned int name, Params_002102F8* p, int a);

static inline void Delete_002102F8(Params_002102F8* p)
{
    if (p)
        func_001E6AE8(p, 3);
}

bool func_002102F8(void* params, Script_002102F8* script)
{
    unsigned int name = 0;
    func_001E8398(params, 0, &name, 0);
    Params_002102F8* p = func_001E6978(func_001190D0(8));
    func_001E6AC8(p, script->m_params);
    void* extra = 0;
    func_001E8180(params, 0x7031F10C, &extra, 0);
    func_001E6AC8(p, extra);
    func_001EE8C8(script, name, p, script->m_BC);
    Delete_002102F8(p);
    return true;
}
