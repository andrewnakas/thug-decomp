struct Comp_00221FA0 {
    unsigned char m0;
    unsigned char m_type;
    char m_pad2[2];
    unsigned int m_value;
    void* m_data;
};

extern "C" void* func_001E5548(void* name, int assert_);
extern "C" Comp_00221FA0* func_001E6E90(void* params, Comp_00221FA0* prev);

extern "C" unsigned int func_00221FA0(void* params, void* name, int depth)
{
    if (depth >= 11) {
        return 0;
    }
    unsigned int result = 0;
    Comp_00221FA0* comp = func_001E6E90(params, 0);
    while (comp) {
        void* global = func_001E5548(comp->m_data, 0);
        Comp_00221FA0* next = func_001E6E90(params, comp);
        if (!result) {
            if (comp->m_type == 10) {
                result = func_00221FA0(comp->m_data, name, depth + 1);
            } else if (global) {
                result = func_00221FA0(global, name, depth + 1);
            }
        }
        if (comp->m_type == 13 && comp->m_data == name) {
            result = comp->m_value;
        }
        comp = next;
    }
    return result;
}
