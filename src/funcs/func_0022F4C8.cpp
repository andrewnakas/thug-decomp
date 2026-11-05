struct H_0022F4C8 {
    char m_pad[0xDC];
    int mDC;
};
extern H_0022F4C8* D_00388A70;
extern void* D_0038FC78;
extern "C" void func_0010A950(H_0022F4C8* h, int v);
extern "C" void func_0022E9B8(void* a);
extern "C" void func_0010A9B0(H_0022F4C8* h);

extern "C" int func_0022F4C8()
{
    func_0010A950(D_00388A70, D_00388A70->mDC);
    func_0022E9B8(D_0038FC78);
    func_0010A9B0(D_00388A70);
    return 1;
}
