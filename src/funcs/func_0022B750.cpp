struct Params_0022B750;

struct Entry_0022B750 {
    char m_name[0x80];
    unsigned int m_80;
    unsigned int m_84;
};

struct Args_0022B750 {
    Entry_0022B750* m_entry;
};

extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_0022B750* func_001E6978(void* mem);
extern "C" void func_001E70C0(Params_0022B750* p, unsigned int name, const char* value);
extern "C" void func_001E7360(Params_0022B750* p, unsigned int name, unsigned int value);
extern "C" void func_001E6AE8(Params_0022B750* p, int flags);
extern "C" void func_0022B8A8(Entry_0022B750* e, Params_0022B750* p);

static inline void Delete_0022B750(Params_0022B750* p)
{
    if (p)
        func_001E6AE8(p, 3);
}

bool func_0022B750(Args_0022B750* args)
{
    Entry_0022B750* e = args->m_entry;
    Params_0022B750* p = func_001E6978(func_001190D0(8));
    Entry_0022B750* cur = args->m_entry;
    func_001E70C0(p, 0xB974F2FC, cur->m_name);
    func_001E7360(p, 0x6C2BFB7F, cur->m_80);
    func_001E7360(p, 0x09794932, cur->m_84);
    func_0022B8A8(e, p);
    Delete_0022B750(p);
    return true;
}
