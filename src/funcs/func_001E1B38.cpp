extern float D_0038E1E8;
extern "C" int func_001E1B20(int ch);
extern "C" void func_001DC5A8(float* vol, float f);
extern "C" void func_001E23B0(int, unsigned short, int);

void SetVoice_001E1B38(int ch, float* vol, float pitch)
{
    int core = func_001E1B20(ch);
    if (core == 1) {
        ch -= 0x15;
    }
    func_001DC5A8(vol, D_0038E1E8);
    int l = (int)(vol[0] * 163.83f);
    int r = (int)(vol[1] * 163.83f);
    if (l > 0x3FFF) {
        l = 0x3FFF;
    } else if (l < -0x3FFF) {
        l = -0x3FFF;
    }
    if (r > 0x3FFF) {
        r = 0x3FFF;
    } else if (r < -0x3FFF) {
        r = -0x3FFF;
    }
    if (pitch != 0.0f) {
        int p = (int)(pitch * 40.96f);
        if (p > 0x3FFF) {
            p = 0x3FFF;
        }
        if (p <= 0) {
            p = 1;
        }
        func_001E23B0(0x8010, core | (ch << 1) | 0x200, p);
    }
    if (l < 0) {
        l += 0x7FFF;
    }
    if (r < 0) {
        r += 0x7FFF;
    }
    func_001E23B0(0x8010, core | (ch << 1), l);
    func_001E23B0(0x8010, core | (ch << 1) | 0x100, r);
}
