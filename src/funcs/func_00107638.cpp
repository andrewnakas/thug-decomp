extern "C" int func_0031A6B8(int a, int b);
extern "C" int func_001079B8(void* self);

struct Snd_00107638 {
    char pad0[0x10];
    int m10;
    int m14;
    char pad18[0xDC - 0x18];
    int mDC;
    int mE0;
    void Update();
};

void Snd_00107638::Update()
{
    if (func_0031A6B8(m10, m14) == 2) return;
    if (func_001079B8(this) == 3) return;
    mDC = mE0;
    mE0 = 0;
}
