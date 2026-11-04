extern char D_00373CC0[];
extern char D_00373CB0[];

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);

struct Goal_0024A2F0 {
    char pad0[0xA8];
    int m_A8;

    void Load(void* params);
};

extern "C" void func_00246658(Goal_0024A2F0* self, int a);
extern "C" void func_002474E8(Goal_0024A2F0* self, void* params);

void Goal_0024A2F0::Load(void* params)
{
    int a;
    int b;
    func_001E7E58(params, D_00373CC0, &a, 0);
    if (a != -1)
        func_00246658(this, a);
    if (func_001E7E58(params, D_00373CB0, &b, 0))
        m_A8 = b;
    func_002474E8(this, params);
}
