extern int D_00388570;
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Str_001040A8 {
    int m0;
    int m_id;
    char* m_str;

    ~Str_001040A8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Str_001040A8::~Str_001040A8()
{
    if (m_str) {
        func_0010A8D8(D_00388A70, m_str);
        m_str = 0;
    }
    D_00388570 = D_00388570 - 1;
}
