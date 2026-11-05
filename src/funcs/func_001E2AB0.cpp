struct Obj_001E2AB0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    void Play();
};
extern "C" void func_001E28F8(int cmd, int a, int b, int c);

void Obj_001E2AB0::Play()
{
    if (m0 == 0)
        func_001E28F8(0x140, m10 / 2, 0, 0);
    else
        func_001E28F8((m0 - 1) | 0x150, m10, 0, 0);
}
