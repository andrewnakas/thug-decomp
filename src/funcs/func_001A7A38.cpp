extern "C" void func_001A6AB8(void* self, int v);

struct Obj_001A7A38 {
    int m0[7];
    int m_flags;
    char pad[0x1D0];
    int m_1F0;
    void Start();
};

void Obj_001A7A38::Start()
{
    func_001A6AB8(this, m_1F0);
    m_flags = (m_flags | 0x10) & ~8;
}
