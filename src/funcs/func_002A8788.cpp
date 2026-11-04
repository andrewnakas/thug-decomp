struct Net_002A8788 {
    char pad[0xB0];
    void* mB0;
};
extern Net_002A8788* D_00392068;
extern "C" void func_001048F0(void* p);

extern "C" bool func_002A8788()
{
    func_001048F0(D_00392068->mB0);
    return true;
}
