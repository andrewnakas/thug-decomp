extern "C" void func_001DC138(int id, int a, void* pos, int flag, float f0, float f1, float f2);

struct Body_00270D50 {
    char pad[0x50];
    char m50[0x10];
};

struct Obj_00270D50 {
    char pad[0xC];
    Body_00270D50* mC;
    char pad2[0x28 - 0x10];
    int m28;
    char pad4[0x30 - 0x2C];
    float m30;
    void Play(int a, int state, float vol);
};

void Obj_00270D50::Play(int a, int state, float vol)
{
    int id;
    if (state == 4)
        id = m28 ? 8 : 5;
    else
        id = 2;
    vol *= 100.0f;
    func_001DC138(id, a, mC->m50, 1, vol * m30, vol, vol);
}
