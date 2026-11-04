struct Params_0022B820;

struct Args_0022B820 {
    unsigned int* m_data;
};

extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_0022B820* func_001E6978(void* mem);
extern "C" void func_001E9D70(Params_0022B820* p, void* src);
extern "C" void func_001F0210(unsigned int script, Params_0022B820* p, void* obj, int a, int b);
extern "C" void func_001E6AE8(Params_0022B820* p, int flags);

static inline void Delete_0022B820(Params_0022B820* p)
{
    if (p)
        func_001E6AE8(p, 3);
}

bool func_0022B820(Args_0022B820* args)
{
    unsigned int* data = args->m_data;
    unsigned int script = *data++;
    Params_0022B820* p = func_001E6978(func_001190D0(8));
    func_001E9D70(p, data);
    func_001F0210(script, p, 0, 0, 0);
    Delete_0022B820(p);
    return true;
}
