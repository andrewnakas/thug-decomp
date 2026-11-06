struct Req_001E2228 {
    char pad0[0x24];
    int m24;
    char pad28[8];
};

extern int D_00394330;
extern volatile int D_00394334;
extern Req_001E2228 D_004686F0[28];

extern "C" int func_0031ADC8();
extern "C" int func_0031AF08(int, int, ...);
extern "C" void func_001E26E8();
extern "C" void func_0031D0E8(int cause, void (*handler)(), int arg);

extern "C" void func_001E2228()
{
    D_00394330 = 0;
    D_00394334 = 0;
    if (func_0031ADC8() == -1)
        return;
    if (func_0031AF08(1, 0x8000, 0) == -1)
        return;
    for (int i = 27; i >= 0; i--)
        D_004686F0[i].m24 = 0;
    func_0031D0E8(3, func_001E26E8, 0);
}
