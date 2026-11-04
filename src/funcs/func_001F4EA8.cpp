extern "C" void* func_001190D0(unsigned int);
extern "C" void* func_001E6978(void*);
extern "C" void func_001E7138(void*, const char*, int);
extern "C" void func_001E7268(void*, const char*, int);
extern "C" void* func_001F0D78(const char*);
extern "C" void func_001F0210(void*, void*, int, int, int);
extern "C" void func_001E6AE8(void*, int);
extern char D_0038E970[];
extern char D_0038E918[];
extern char D_0038E978[];
extern char D_0038E980[];
extern char D_00366280[];

struct Entry_001F4EA8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int pad[4];
};

struct Obj_001F4EA8 {
    char pad[0x28];
    Entry_001F4EA8 m_entries[1];
    void Send(int i);
};

void Obj_001F4EA8::Send(int i)
{
    void* s = func_001E6978(func_001190D0(8));
    func_001E7138(s, D_0038E970, m_entries[i].mC);
    func_001E7268(s, D_0038E918, m_entries[i].m0);
    if (m_entries[i].m10)
        func_001E7138(s, D_0038E978, m_entries[i].m10);
    func_001E7268(s, D_0038E980, i);
    func_001F0210(func_001F0D78(D_00366280), s, 0, 0, 0);
    m_entries[i].m4 = 1;
    if (s)
        func_001E6AE8(s, 3);
}
