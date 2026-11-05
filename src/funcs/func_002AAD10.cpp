struct Net_002AAD10;
extern Net_002AAD10* D_00392068;
extern "C" void* func_002A39E0(Net_002AAD10* n, int i);
extern "C" void func_002A3448(Net_002AAD10* n, void* p);

extern "C" int func_002AAD10()
{
    Net_002AAD10* n = D_00392068;
    func_002A3448(n, func_002A39E0(n, 0));
    return 1;
}
