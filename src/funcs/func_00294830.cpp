struct Obj_00294830;
extern "C" void func_00292F40(Obj_00294830* o, int i);

struct Obj_00294830 {
    char pad0[0x2A1];
    unsigned char m2A1;
    unsigned char m2A2;
    unsigned char m2A3;
    unsigned char m2A4;
    void Reset();
};

void Obj_00294830::Reset()
{
    for (int i = 1; i < m2A1; i++)
        func_00292F40(this, i);
    m2A2 = 0;
    m2A4 = 0;
}
