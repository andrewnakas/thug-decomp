extern "C" int func_0031AF08(int, int, ...);

struct Strm_001F7B90 {
    int m0;
    int m_pad[16];
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
};

extern "C" void func_001F82E8(int);

void func_001F7B90(Strm_001F7B90* s)
{
    s->m0 = 3;
    func_001F82E8(0);
    s->m50 = (func_0031AF08(1, 0x80E0, 0, 2, 0, 0) & 0xFFFFFF) - s->m44;
    func_0031AF08(1, 0x80D0, 0, 0, s->m58, 0x4000, 0x800);
}
