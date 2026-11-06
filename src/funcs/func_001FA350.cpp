extern "C" int func_00331950(const char* a, const char* b);
extern "C" char* func_00331A9C(char* dst, const char* src);

struct Obj_001FA350 {
    char m_pad0[0x13C];
    char m13C[0x2CC - 0x13C];
    int m2CC;
    void SetName(const char* name);
};

void Obj_001FA350::SetName(const char* name)
{
    if (func_00331950(name, m13C)) {
        func_00331A9C(m13C, name);
        m2CC = 1;
    }
}
