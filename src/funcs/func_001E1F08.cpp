struct Sound_001E1F08 {
    int m_addr;
    int m_loop;
    float m_volume;
};

struct Vol_001E1F08 {
    float m_left;
    float m_right;
    char m_pad[0x18];
};

extern volatile int D_003940E8[2];
extern volatile int D_003940F0[2];

extern "C" int func_001E1B20(int voice);
extern "C" int func_001E23B0(int cmd, unsigned short reg, int value);
extern "C" void func_001DC540(Vol_001E1F08* v);
extern "C" void func_001E1B38(int voice, Vol_001E1F08* v, float vol);
extern "C" void func_001DC578(Vol_001E1F08* v, int flags);

int Sound_001E1F08_Play(Sound_001E1F08* snd, int voice, float left, float right, float vol)
{
    int core = func_001E1B20(voice);
    int ch = voice;
    if (core == 1) {
        ch = voice - 21;
    }
    func_001E23B0(0x8050, core | (ch << 1) | 0x2040, snd->m_addr);
    int mask = 1 << ch;
    vol = vol * snd->m_volume * 0.01f;
    Vol_001E1F08 tmp;
    func_001DC540(&tmp);
    tmp.m_left = left;
    tmp.m_right = right;
    func_001E1B38(voice, &tmp, vol);
    func_001E23B0(0x8030, core | 0x1500, mask);
    if (snd->m_loop) {
        D_003940E8[core] |= mask;
    }
    D_003940F0[core] |= mask;
    func_001DC578(&tmp, 2);
    return voice;
}
