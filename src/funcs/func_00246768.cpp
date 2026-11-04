extern "C" int func_001E7200(void* params, unsigned int name, int def);

struct Comp_00246768 {
    int m_pad[8];
    void* m_params;
    int Get();
};

int Comp_00246768::Get()
{
    return func_001E7200(m_params, 0x5FD80EDC, 0);
}
