extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned char* func_001E9D70(void* o, unsigned char* src);
extern "C" void func_001E6B30(void* list);
extern "C" void func_001E6AC8(void* list, void* o);
extern "C" void func_001E6AE8(void* o, int n);

struct C_0011FD78 {
    char pad[0x48];
    char m48[0xC];
    int m54;
    unsigned char* Read(unsigned char* src);
};

unsigned char* C_0011FD78::Read(unsigned char* s)
{
    void* o = func_001E6978(func_001190D0(8));
    s = func_001E9D70(o, s);
    func_001E6B30(m48);
    func_001E6AC8(m48, o);
    if (o)
        func_001E6AE8(o, 3);
    m54 = *s++ != 0;
    return s;
}
