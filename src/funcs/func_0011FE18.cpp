struct Prm_0011FE18 {
    int m0;
    int m4;
};

extern "C" int func_001E8180(Prm_0011FE18* p, unsigned int name, unsigned int* out, int req);
extern "C" void* func_0011F548(unsigned int id);
extern "C" int func_00121AB0(unsigned int name, void* s, int a);

class Comp_0011FE18 {
public:
    char pad0[0x48];
    Prm_0011FE18 m_params;
    int Run(unsigned int name);
};

int Comp_0011FE18::Run(unsigned int name)
{
    unsigned int id;
    if (func_001E8180(&m_params, name, &id, 0)) {
        return func_00121AB0(name, func_0011F548(id), 0);
    }
    return 0;
}
