extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void* func_001E9D70(void* s, void* src);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6AE8(void* p, int flags);

struct Obj_00261B38 {
    char pad[0x5C];
    char m_params[4];
    void* Fn(void* src);
};

void* Obj_00261B38::Fn(void* src)
{
    void* p = func_001E6978(func_001190D0(8));
    src = func_001E9D70(p, src);
    func_001E6AC8(m_params, p);
    if (p) func_001E6AE8(p, 3);
    return src;
}
