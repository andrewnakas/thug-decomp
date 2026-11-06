extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Ent_0014C9B0 {
    int m0;
    int m4;
};

struct Anim_0014C9B0 {
    char pad[0xB0];
    int mB0;
    char padB4[0x28];
    Ent_0014C9B0* mDC;
    int mE0;
    bool Load(int* p);
};

extern "C" void func_00177988();
extern "C" void func_00177A08(int v, Ent_0014C9B0* e);

bool Anim_0014C9B0::Load(int* p)
{
    p++;
    mB0 = *p++;
    mE0 = *p++;
    func_00177988();
    if (mE0 > 0) {
        mDC = (Ent_0014C9B0*)func_0010A638(D_00388A70, mE0 * 8, 1, 0);
        for (int i = 0; i < mE0; i++) {
            mDC[i].m0 = *p++;
            func_00177A08(*p++, &mDC[i]);
        }
    }
    return mE0 > 0;
}
