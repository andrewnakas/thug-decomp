extern "C" void func_001DC138(int id, int a, void* pos, int flag, float f0, float f1, float f2);

struct Body_00270C98 {
    char pad[0x50];
    char m50[0x10];
};

struct Obj_00270C98 {
    char pad[0xC];
    Body_00270C98* mC;
    char pad2[0x1C - 0x10];
    int m1C;
    char pad3[0x28 - 0x20];
    int m28;
    char pad4[0x30 - 0x2C];
    float m30;
    void Play(int a, float vol);
};

void Obj_00270C98::Play(int a, float vol)
{
    int id;
    if (m1C == 4)
        id = m28 ? 9 : 6;
    else
        id = 3;
    vol *= 100.0f;
    func_001DC138(id, a, mC->m50, 1, vol * m30, vol, vol);
}
