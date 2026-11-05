extern char D_00391458[];
extern char D_00391460[];
extern char D_00391450[];
extern char D_00376410[];

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" void func_0026DF70(int id, const char* name);

struct Obj_0026E2F8 {
    char pad0[4];
    int m_id;
    int m_a;
    int m_b;

    void Read(void* params);
};

void Obj_0026E2F8::Read(void* params)
{
    func_001E7E58(params, D_00391458, &m_a, 0);
    func_001E7E58(params, D_00391460, &m_b, 0);
    const char* name = D_00391450;
    func_001E8890(params, D_00376410, &name, 0);
    func_0026DF70(m_id, name);
}
