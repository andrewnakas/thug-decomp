extern "C" int func_00331950(const char* a, const char* b);
extern "C" char* func_00331A9C(char* d, const char* s);

class Obj_001FA288 {
public:
    char pad0[0x180];
    char m_name[0x2CC - 0x180];
    int m2CC;
    void SetName(const char* name);
};

void Obj_001FA288::SetName(const char* name)
{
    if (func_00331950(name, m_name)) {
        func_00331A9C(m_name, name);
        m2CC = 1;
    }
}
