struct Mgr_0023ECD8 {
    int m0;
    char m_table[4];
};

extern void* D_00388A70;

extern "C" int func_0023C040(Mgr_0023ECD8* self);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" int func_00100030(int n);
extern "C" void* func_00243C18(void* table, int* key, int* out);
extern "C" bool func_00246D48(void* goal);
extern "C" unsigned int func_00246258(void* goal);

unsigned int func_0023ECD8(Mgr_0023ECD8* self)
{
    int n = func_0023C040(self);
    int* order = (int*)func_0010A638(D_00388A70, n * 4, 1, 0);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    for (int i = 0; i < n * 5; i++) {
        int a = func_00100030(n);
        int b = func_00100030(n);
        int t = order[a];
        order[a] = order[b];
        order[b] = t;
    }
    for (int i = 0; i < n; i++) {
        int out;
        void* goal = func_00243C18(self->m_table, &order[i], &out);
        if (func_00246D48(goal)) {
            if (order) {
                func_0010A8D8(D_00388A70, order);
            }
            return func_00246258(goal);
        }
    }
    if (order) {
        func_0010A8D8(D_00388A70, order);
    }
    return 0;
}
