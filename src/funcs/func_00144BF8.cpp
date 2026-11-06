extern "C" int func_001177A8(void* p, int a, int b, void* owner);

class Obj_00144BF8 {
public:
    int m_0;
    void* m_4;
    char pad[0xA0C - 8];
    int m_A0C;
    int m_A10;
    int m_A14;
    void Start(int a, int b, int c, int d);
};

void Obj_00144BF8::Start(int a, int b, int c, int d)
{
    m_A10 = c;
    m_A14 = d;
    func_001177A8(m_4, a, b, this);
    m_A0C = 1;
}
