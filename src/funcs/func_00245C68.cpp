extern char D_0038FFC8[];
extern char D_00373880[];

struct Array_00245C68 {
    unsigned int GetSize() const { return m_size; }
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
};

struct Goal_00245C68 {
    char m_pad[0x20];
    void* m_params;
};

extern void* D_0038FC78;

extern "C" bool func_001E8248(void* params, unsigned int name, Array_00245C68** out, int assert_);
extern "C" void* func_001E9378(Array_00245C68* self, unsigned int index);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int assert_);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void* func_0022E048(void* self);
extern "C" bool func_00265E50(void* self, unsigned int id, int a);
extern "C" void func_00103F28(const char* fmt);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void func_00245450(Goal_00245C68* self, unsigned int name, int a);

void func_00245C68(Goal_00245C68* self, unsigned int id, int max)
{
    Array_00245C68* list;
    func_001E8248(self->m_params, 0x191F66E9, &list, 1);
    for (unsigned int i = 0; i < list->GetSize(); i++) {
        void* elem = func_001E9378(list, i);
        unsigned int elem_id;
        func_001E84E8(elem, D_0038FFC8, &elem_id, 1);
        int value;
        if (!func_001E7DE8(elem, 0xCD66C8AE, &value, 0)) {
            func_001E7DE8(self->m_params, 0xCD66C8AE, &value, 1);
        }
        if (elem_id == id && value < max) {
            if (!func_00265E50(func_0022E048(D_0038FC78), id, 0)) {
                func_00103F28(D_00373880);
            }
            unsigned int script;
            func_001E8398(elem, 0x2E0B1465, &script, 1);
            func_00245450(self, script, 1);
            return;
        }
    }
}
