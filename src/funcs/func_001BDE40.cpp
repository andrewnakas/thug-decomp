extern "C" int func_00185578(void* p, unsigned int id);

struct Obj1BDE40 {
    char m_pad[0xC];
    void* mC;
    char m_pad10[0x1C - 0x10];
    int m1C;
    void Init();
};

void Obj1BDE40::Init()
{
    m1C = func_00185578(mC, 0xCE0CA665);
}
