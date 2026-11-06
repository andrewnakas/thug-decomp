extern "C" void* func_003315B8(void* p, int c, int n);

class Obj_00142F58 {
public:
    int m_0;
    int m_4;
    char m_buf[0x4000];
    void Init();
};

void Obj_00142F58::Init()
{
    m_0 = 0;
    m_4 = 0;
    func_003315B8(m_buf, 3, 0x4000);
}
