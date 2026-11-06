extern unsigned int D_003940F8[2];
extern "C" void func_001E23B0(int cmd, int id, unsigned int mask);

extern "C" void func_001E1A88(int key)
{
    int pad;
    if (key >= 21) {
        key -= 21;
        pad = 1;
    } else {
        pad = 0;
    }
    unsigned int mask = 1 << key;
    func_001E23B0(0x8030, pad | 0x1600, mask);
    D_003940F8[pad] |= mask;
}
