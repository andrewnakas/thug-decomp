extern unsigned int D_0038E288;

struct Voice_001E3548 {
    char pad0[8];
    int m8;
    char padC[0x14];
    unsigned int m20;
};

extern Voice_001E3548* D_00351DF8[];
extern "C" void func_001E28F8(int ch, unsigned int vol, int a, int b);

int SetVolume_001E3548(int ch, float l, float r)
{
    int vl = (int)(l * (float)D_0038E288 * 0.01f);
    vl = (int)(vl * 81.90999603f);
    if (vl > 0x3FFF) {
        vl = 0x3FFF;
    } else if (vl < -0x3FFF) {
        vl = -0x3FFF;
    }
    int vr = vl;
    if (r != l) {
        vr = (int)(r * (float)D_0038E288 * 0.01f);
        vr = (int)(vr * 81.90999603f);
        if (vr > 0x3FFF) {
            vr = 0x3FFF;
        } else if (vr < -0x3FFF) {
            vr = -0x3FFF;
        }
    }
    if (vl < 0) {
        vl += 0x7FFF;
    }
    if (vr < 0) {
        vr += 0x7FFF;
    }
    D_00351DF8[ch]->m20 = ((vl & 0x7FFF) << 16) | (vr & 0x7FFF);
    if (D_00351DF8[ch]->m8 == 4) {
        func_001E28F8(ch | 0xC0, D_00351DF8[ch]->m20, 0, 0);
    }
    return 1;
}
