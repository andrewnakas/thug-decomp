extern "C" int func_001E8A30(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0022E058(void* p);
extern "C" void* func_00202EF8(void* p, unsigned int name);
extern void* D_0038FC78;

struct Obj_0024F780 {
    int m0;
    char m_params[4];

    int GetType();
};

int Obj_0024F780::GetType()
{
    unsigned int type;
    func_001E8A30(m_params, 0x9BAB2EAE, &type, 1);
    switch (type) {
    case 0x3558D8E6:
        return 0;
    case 0x9D65D0E7:
        return 4;
    case 0x06AB02F2:
        {
            unsigned int mode;
            func_001E8A30(func_00202EF8(func_0022E058(D_0038FC78), 0x6F82C71E), 0x21902065, &mode, 1);
            if (mode == 0x92F5B4CB) return 1;
            if (mode == 0x7C442511) return 2;
            return 1;
        }
    }
    return 0;
}
