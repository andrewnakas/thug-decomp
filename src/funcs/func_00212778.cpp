struct Ped_00212778 {
    char pad0[0xB8];
    float m_B8;
    float m_BC;
    void SetRange(float a, float b)
    {
        m_B8 = a;
        m_BC = b;
    }
};

extern float D_00389114;
extern float D_00389110;
extern char D_0038F4E0[];
extern char D_0038F4E8[];

extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" Ped_00212778* func_0013B000(int i);

bool func_00212778(void* params)
{
    float a = D_00389114;
    float b = D_00389110;
    func_001E7F50(params, D_0038F4E0, &a, 0);
    func_001E7F50(params, D_0038F4E8, &b, 0);
    for (int i = 0; i < 2; i++) {
        Ped_00212778* p = func_0013B000(i);
        if (p)
            p->SetRange(a, b);
    }
    return true;
}
