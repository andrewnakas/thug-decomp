extern "C" void func_00331A9C(char* d, const char* s);

struct Obj_001FA528 {
    char pad0[0x280];
    char m280[0x20];
    void SetName(const char* s);
};

void Obj_001FA528::SetName(const char* s)
{
    if (!s) m280[0] = 0;
    func_00331A9C(m280, s);
}
