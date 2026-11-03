struct Arr_002DA190 {
    char pad0[0xC];
    int mC;
};

extern char D_0037C9B8[];
extern char D_00392EC8[];
extern char D_00392ED0[];
extern "C" Arr_002DA190* func_001E55F8(char* name, int v);
extern "C" void* func_001E9378(Arr_002DA190* a, int i);
extern "C" int func_001E84E8(void* s, char* name, int* out, int v);
extern "C" int func_001E8890(void* s, char* name, int* out, int v);

int Find_002DA190(void* a0, int id)
{
    Arr_002DA190* arr = func_001E55F8(D_0037C9B8, 0);
    for (int i = 0; i < arr->mC; i++) {
        void* s = func_001E9378(arr, i);
        int v;
        func_001E84E8(s, D_00392EC8, &v, 0);
        if (id == v) {
            int r;
            func_001E8890(s, D_00392ED0, &r, 1);
            return r;
        }
    }
    return 0;
}
