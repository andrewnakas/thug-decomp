extern "C" int func_00130B80(int v);

struct Obj_00126260 {
    int m0[3];
    unsigned int m_flags;
    char pad[0x194];
    int m_1A4;
    int m_1A8;
    void Set(int v);
};

void Obj_00126260::Set(int v)
{
    m_1A4 = v;
    m_1A8 = func_00130B80(v);
    m_flags |= 0x1000;
}
