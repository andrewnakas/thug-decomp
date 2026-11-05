struct Obj_001F7CA0 {
    int m0;
    char pad[0x28];
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    char pad2[8];
    int m4C;
    int m50;
    int m54;
    void Reset();
};
extern "C" void func_001F7B90(Obj_001F7CA0* self);

void Obj_001F7CA0::Reset()
{
    func_001F7B90(this);
    m0 = 0;
    m2C = 0;
    m34 = 0;
    m38 = 0;
    m40 = 0;
    m54 = 0;
    m4C = 0;
    m50 = 0;
}
