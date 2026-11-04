extern char D_00391458[];
extern char D_00391460[];
extern char D_00376410[];

extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, int value);
extern "C" void func_001E7A30(void* params, unsigned int name, int type, const char* value);
extern "C" const char* func_0026DF90(int id);

struct Obj_0026E258 {
    char pad0[4];
    int m_id;
    int m_a;
    int m_b;

    void Write(void* params);
};

void Obj_0026E258::Write(void* params)
{
    func_001E7A68(params, func_001F0D78(D_00391458), 1, m_a);
    func_001E7A68(params, func_001F0D78(D_00391460), 1, m_b);
    func_001E7A30(params, func_001F0D78(D_00376410), 3, func_0026DF90(m_id));
}
