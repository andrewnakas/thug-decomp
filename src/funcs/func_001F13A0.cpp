struct Obj_001F13A0 {
    char pad0[5];
    unsigned char m5;
    char pad6[0x144 - 6];
    int m144;
    char pad148[0x1E8 - 0x148];
    int m1E8;
    char pad1EC[0x1F4 - 0x1EC];
    int m1F4;
    void Update();
};

extern "C" void func_001F1318(Obj_001F13A0* self);

void Obj_001F13A0::Update()
{
    if (m144 || m5 || m1E8 || m1F4)
        func_001F1318(this);
}
