struct Params_0022B5B0;

struct Entry_0022B5B0 {
    char m_name[0x80];
};

struct Args_0022B5B0 {
    Entry_0022B5B0* m_entry;
};

extern char D_0038FC08[];
extern char D_003726E8[];

extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_0022B5B0* func_001E6978(void* mem);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7A30(Params_0022B5B0* p, unsigned int name, int type, const char* value);
extern "C" void func_001F0370(const char* script, Params_0022B5B0* p, int a, int b);
extern "C" void func_001E6AE8(Params_0022B5B0* p, int flags);

static inline void Delete_0022B5B0(Params_0022B5B0* p)
{
    if (p)
        func_001E6AE8(p, 3);
}

bool func_0022B5B0(Args_0022B5B0* args)
{
    Entry_0022B5B0* e = args->m_entry;
    Params_0022B5B0* p = func_001E6978(func_001190D0(8));
    func_001E7A30(p, func_001F0D78(D_0038FC08), 3, e->m_name);
    func_001F0370(D_003726E8, p, 0, 0);
    Delete_0022B5B0(p);
    return true;
}
