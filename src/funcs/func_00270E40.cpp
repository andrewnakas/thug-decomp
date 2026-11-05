extern "C" void func_001DC138(int id, int a, void* pos, int flag, float f0, float f1, float f2);

struct Body_00270E40 {
    char pad[0x50];
    char m50[0x10];
};

struct Obj_00270E40 {
    char pad[0xC];
    Body_00270E40* mC;
    char pad2[0x30 - 0x10];
    float m30;
    void Play(int a, float vol);
};

void Obj_00270E40::Play(int a, float vol)
{
    float v = vol * 100.0f;
    func_001DC138(10, a, mC->m50, 1, v * m30, v, v);
}
