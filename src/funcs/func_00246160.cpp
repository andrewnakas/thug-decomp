struct Params_00246160;

extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_00246160* func_001E6978(void* mem);
extern "C" void func_001E7360(Params_00246160* p, unsigned int name, unsigned int value);
extern "C" void func_001F0210(unsigned int script, Params_00246160* p, void* obj, int a, int b);
extern "C" void func_001E6AE8(Params_00246160* p, int flags);

static inline void Delete_00246160(Params_00246160* p)
{
    if (p)
        func_001E6AE8(p, 3);
}

struct Goal_00246160 {
    void RunEnded();
};

extern "C" unsigned int func_00246258(Goal_00246160* self);

void Goal_00246160::RunEnded()
{
    Params_00246160* p = func_001E6978(func_001190D0(8));
    func_001E7360(p, 0x9982E501, func_00246258(this));
    func_001F0210(0xF3C20AF5, p, 0, 0, 0);
    Delete_00246160(p);
}
