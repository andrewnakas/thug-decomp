struct Arr_0026E690 {
    char pad0[0xC];
    int m_size;
};

struct Elem_0026E690 {
    char pad0[0x14];
};

extern char D_00376420[];
extern "C" int func_001E82B8(void* params, const char* name, Arr_0026E690** out, int required);
extern "C" void* func_001E9378(Arr_0026E690* a, int i);
extern "C" void func_0026E2F8(Elem_0026E690* e, void* s);

struct Obj_0026E690 {
    int m0;
    int m_count;
    Elem_0026E690* m_elems;

    void Load(void* params);
};

void Obj_0026E690::Load(void* params)
{
    Arr_0026E690* a = 0;
    func_001E82B8(params, D_00376420, &a, 0);
    if (m_count == a->m_size) {
        for (int i = 0; i < m_count; i++) {
            func_0026E2F8(&m_elems[i], func_001E9378(a, i));
        }
    }
}
