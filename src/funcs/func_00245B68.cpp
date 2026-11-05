extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int assert_);
extern "C" void func_001F0210(unsigned int script, void* params, void* a, void* b, int c);

struct Obj_00245B68 {
    char pad[0x20];
    void* m_params;

    void Check(int id);
};

void Obj_00245B68::Check(int id)
{
    if (func_001E8708(m_params, 0xF268C278)) {
        int v;
        func_001E8398(m_params, 0xB03713EE, &v, 1);
        if (v == id) {
            func_001F0210(0x62B12A8E, m_params, 0, 0, 0);
        }
    }
}
