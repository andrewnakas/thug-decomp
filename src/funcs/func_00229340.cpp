struct Vec_00229340 {
    float x, y, z, w;
};

struct Array_00229340 {
    char pad[0xC];
    int m_size;
};

struct Symbol_00229340 {
    int m_flags;
    unsigned int m_name;
    int pad8;
    Array_00229340* m_value;
};

extern "C" void func_001EE2C0();
extern "C" void func_001EDA20();
extern "C" Symbol_00229340* func_001E5258(Symbol_00229340* prev);
extern "C" void func_00292388();
extern "C" void func_00229528();
extern "C" void func_00229AF8();
extern "C" void* func_001E9378(Array_00229340* a, int i);
extern "C" bool func_001E7FA8(void* params, unsigned int key, Vec_00229340* out, int required);
extern "C" void func_001E6B90(void* params, unsigned int key);
extern "C" void func_001E7410(void* params, unsigned int key, float x, float y, float z);
extern "C" void* func_00259EB8();
extern "C" void func_00259F80(void* a);

void func_00229340()
{
    func_001EE2C0();
    for (Symbol_00229340* sym = func_001E5258(0); sym; sym = func_001E5258(sym)) {
        if ((sym->m_flags & 0xFF0100) == 0xC0100 && sym->m_name == 0xC472ECC5) {
            func_00292388();
            func_00229528();
            func_00229AF8();
            int n = sym->m_value->m_size;
            for (int i = 0; i < n; i++) {
                void* e = func_001E9378(sym->m_value, i);
                Vec_00229340 v;
                v.x = 0.0f;
                v.y = 0.0f;
                v.z = 0.0f;
                v.w = 1.0f;
                if (func_001E7FA8(e, 0xB9D31B0A, &v, 0)) {
                    func_001E6B90(e, 0xB9D31B0A);
                    func_001E7410(e, 0x7F261953, v.x, v.y, -v.z);
                }
            }
            func_00259F80(func_00259EB8());
            sym->m_flags &= ~0x100;
            break;
        }
    }
    func_001EDA20();
}
