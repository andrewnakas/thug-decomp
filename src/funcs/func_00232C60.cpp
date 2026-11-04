struct Params_00232C60;
extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_00232C60* func_001E6978(void* mem);
extern "C" void func_001E6AE8(Params_00232C60* p, int flags);
extern "C" void func_001E7360(Params_00232C60* p, unsigned int crc, int v);
extern "C" void func_001F0210(unsigned int crc, Params_00232C60* p, int a, int b, int c);

struct Info_00232C60 {
    int m0;
    char m4;
};

struct Self_00232C60 {
    Info_00232C60* m_info;

    bool Run();
};

bool Self_00232C60::Run()
{
    Params_00232C60* p = func_001E6978(func_001190D0(8));
    Info_00232C60* info = m_info;
    if (info->m4)
        func_001E7360(p, 0xF649D637, 0);
    func_001E7360(p, 0xAE94C183, info->m0);
    func_001F0210(0x3CF9E86D, p, 0, 0, 0);
    if (p)
        func_001E6AE8(p, 3);
    return true;
}
