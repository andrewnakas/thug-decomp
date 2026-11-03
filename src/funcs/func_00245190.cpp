extern "C" void func_001E6AC8(void* params);

struct Comp_00245190 {
    int m_pad[8];
    void* m_params;
    int Clear();
};

int Comp_00245190::Clear()
{
    func_001E6AC8(m_params);
    return 0;
}
