extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6B30(void* s);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);
extern "C" void* func_00262330(void* src, unsigned int name);
extern "C" void func_001E6AC8(void* dst, void* src);

struct Info_001AB7C0 {
    int m0;
    int m_value;
    unsigned int m_name;
    int m_kind;
};

extern "C" void func_00261FB0(Info_001AB7C0* info, void* src, int i);
extern "C" int func_00264738(Info_001AB7C0* info);

struct C_001AB7C0 {
    int m_pad[667];
    void* mA6C;
    void Build(void* src);
};

void C_001AB7C0::Build(void* src)
{
    if (!mA6C) mA6C = func_001E6978(func_001190D0(8));
    func_001E6B30(mA6C);
    for (int i = 0; i < 12; i++) {
        Info_001AB7C0 info;
        func_00261FB0(&info, src, i);
        if (func_00264738(&info)) continue;
        if (info.m_kind) {
            func_001E7A68(mA6C, info.m_name, 1, info.m_value);
        } else {
            func_001E7A68(mA6C, info.m_name, 13, info.m_value);
        }
    }
    func_001E6AC8(mA6C, func_00262330(src, 0xD544AA2D));
}
