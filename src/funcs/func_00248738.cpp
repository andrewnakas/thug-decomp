extern "C" int func_001E8708(void* params, unsigned int name);

struct Comp_00248738 {
    int m_pad[8];
    void* m_params;
    int Has();
};

int Comp_00248738::Has()
{
    return func_001E8708(m_params, 0xC5EC08E6);
}
