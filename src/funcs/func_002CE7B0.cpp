struct Info_002CE7B0 {
    int m0[6];
    int m18;
    int pad[5];
};

extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" void* func_0031BB90();
extern "C" void func_0031BBA0(void* p, Info_002CE7B0* info);

extern "C" int func_002CE7B0()
{
    Info_002CE7B0 info;
    func_003315B8(&info, 0, sizeof(info));
    func_0031BBA0(func_0031BB90(), &info);
    return info.m18;
}
