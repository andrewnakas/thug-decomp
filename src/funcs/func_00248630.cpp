struct Array_00248630 {
    int pad[3];
    int m_size;
};

struct Goal_00248630 {
    char pad[0x20];
    void* m_params;
};

extern char D_00373AD8[];

extern "C" void* func_00240850();
extern "C" bool func_001E84E8(void* self, const char* name, unsigned int* out, int assert_);
extern "C" bool func_001E82B8(void* self, const char* name, Array_00248630** out, int assert_);
extern "C" void func_0023D3C8(void* self, unsigned int id);
extern "C" unsigned int func_001E9300(void* self, int index);

void func_00248630(Goal_00248630* self)
{
    unsigned int id;
    Array_00248630* list;

    void* mgr = func_00240850();
    list = 0;
    id = 0;
    if (func_001E84E8(self->m_params, D_00373AD8, &id, 0)) {
        func_0023D3C8(mgr, id);
        return;
    }
    if (func_001E82B8(self->m_params, D_00373AD8, &list, 0)) {
        int n = list->m_size;
        for (int i = 0; i < n; i++) {
            id = func_001E9300(list, i);
            if (id)
                func_0023D3C8(mgr, id);
        }
    }
}
