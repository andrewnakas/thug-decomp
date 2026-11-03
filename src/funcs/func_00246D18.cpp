extern char D_003738A8[];
extern "C" int func_001E8890(void* params, char* name, void* out, int required);

struct Comp_00246D18 {
    int m_pad[8];
    void* m_params;
    int Get(void* out);
};

int Comp_00246D18::Get(void* out)
{
    return func_001E8890(m_params, D_003738A8, out, 0);
}
