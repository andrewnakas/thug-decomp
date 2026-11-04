extern char D_00373A80[];
extern char D_0038FFC8[];

struct Array_00248270 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Goal_00248270 {
    char m_pad[0x20];
    void* m_params;
};

extern void* D_0038FC78;

extern "C" void* func_0022E048(void* self);
extern "C" bool func_001E82B8(void* params, const char* name, Array_00248270** out, int assert_);
extern "C" void* func_001E9378(Array_00248270* self, int index);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int assert_);
extern "C" void* func_00265958(void* self, unsigned int id);
extern "C" void func_00265528(void* self, int value);
extern "C" void func_00265250(void* self, int value);

void func_00248270(Goal_00248270* self, int value, int kill)
{
    void* clusters = func_0022E048(D_0038FC78);
    Array_00248270* list = 0;
    if (func_001E82B8(self->m_params, D_00373A80, &list, 0)) {
        int size = list->m_size;
        for (int i = 0; i < size; i++) {
            unsigned int id;
            func_001E84E8(func_001E9378(list, i), D_0038FFC8, &id, 1);
            if (func_00265958(clusters, id)) {
                if (kill) {
                    void* cluster = func_00265958(clusters, id);
                    if (cluster) {
                        func_00265528(cluster, value);
                    }
                } else {
                    func_00265250(func_00265958(clusters, id), value);
                }
            }
        }
    }
}
