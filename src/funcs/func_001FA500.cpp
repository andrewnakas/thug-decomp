extern "C" void func_00331A9C(char* d, const char* s);

struct Obj_001FA500 {
    char pad0[0x260];
    char m260[0x20];
    void SetName(const char* s);
};

void Obj_001FA500::SetName(const char* s)
{
    if (!s) m260[0] = 0;
    func_00331A9C(m260, s);
}
