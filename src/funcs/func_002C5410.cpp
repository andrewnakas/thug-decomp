struct Sub_002C5410 {
    char pad[0x7C];
    int m7C;
    bool Is6() { return m7C == 6; }
};

extern "C" void func_0020B0A0(unsigned int id, int a, int b);

struct Obj_002C5410 {
    char pad[0xA0];
    Sub_002C5410* mA0;
    void Play();
};

void Obj_002C5410::Play()
{
    if (mA0 && mA0->Is6())
        func_0020B0A0(0x5B509AD3, 0, 0);
    else
        func_0020B0A0(0x64716BEE, 0, 0);
}
