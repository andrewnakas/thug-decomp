extern unsigned int D_0038E200[2];
extern unsigned int D_0038E208[2];
extern volatile unsigned int D_00394338[2];
extern "C" void func_001E2170(int pad);

void Set_001E2600(unsigned short id, unsigned int mask)
{
    int pad = id & 1;
    switch (id & 0xFF00) {
    case 0x1500: {
        unsigned int b = D_0038E208[pad] & mask;
        if (b) D_0038E208[pad] &= ~b;
        D_0038E200[pad] |= mask;
        D_00394338[pad] &= ~mask;
        break;
    }
    case 0x1600: {
        func_001E2170(pad);
        unsigned int b = D_0038E200[pad] & mask;
        if (b) D_0038E200[pad] &= ~b;
        D_0038E208[pad] |= mask;
        break;
    }
    }
}
