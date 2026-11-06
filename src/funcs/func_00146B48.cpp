extern "C" void func_00143F60(void* p);

class Obj_00146B48 {
public:
    char pad[0x20];
    void* m_20;
    char pad24[0x88 - 0x24];
    int m_88;
    void Set(int v);
};

void Obj_00146B48::Set(int v)
{
    m_88 = v;
    if (v && m_20) func_00143F60(m_20);
}
