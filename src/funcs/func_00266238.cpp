extern "C" void func_002661C8(void* p);
extern "C" void func_002668B0(void* list, void (*fn)(void*), void* ctx);

struct Ctx_00266238 {
    int m_target;
    unsigned char m_index;
    int m_found;
};

struct Obj_00266238 {
    int m0;
    int m4;
    int m8[6];
    unsigned char IndexOf(int id);
};

unsigned char Obj_00266238::IndexOf(int id)
{
    Ctx_00266238 ctx;
    ctx.m_target = id;
    ctx.m_index = 0;
    ctx.m_found = 0;
    func_002668B0(m8, func_002661C8, &ctx);
    return ctx.m_index;
}
