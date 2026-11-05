extern "C" void func_00266200(void* p);
extern "C" void func_002668B0(void* list, void (*fn)(void*), void* ctx);

struct Ctx_00266270 {
    void* m_result;
    unsigned char m_key;
    int m_extra;
};

struct Obj_00266270 {
    int m0;
    int m4;
    int m8[6];
    void* Find(unsigned char key);
};

void* Obj_00266270::Find(unsigned char key)
{
    Ctx_00266270 ctx;
    ctx.m_result = 0;
    ctx.m_key = key;
    ctx.m_extra = 0;
    func_002668B0(m8, func_00266200, &ctx);
    return ctx.m_result;
}
