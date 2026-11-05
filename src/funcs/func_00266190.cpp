extern "C" void func_00266158(void* p);
extern "C" void func_002668B0(void* list, void (*fn)(void*), void* ctx);

struct Ctx_00266190 {
    void* m_result;
    int m_key;
};

struct Obj_00266190 {
    int m0;
    int m4;
    int m8[6];
    void* Find(int key);
};

void* Obj_00266190::Find(int key)
{
    Ctx_00266190 ctx;
    ctx.m_key = key;
    ctx.m_result = 0;
    func_002668B0(m8, func_00266158, &ctx);
    return ctx.m_result;
}
