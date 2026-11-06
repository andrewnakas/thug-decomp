extern "C" void* func_00185578(void* o, unsigned int name);

struct Obj_001A9DF8 {
    int m0[3];
    void* m_C;
    int m10[8];
    void* m_30;
    void Init();
};

void Obj_001A9DF8::Init()
{
    m_30 = func_00185578(m_C, 0x286A8D26);
}
