struct Arr_002A23F0 {
    char pad[0xC];
    int size;
};

extern char D_003783A8[];
extern char D_00378328[];
extern char D_00392120[];
extern "C" Arr_002A23F0* func_001E55F8(char* name, int a);
extern "C" void* func_001E9378(Arr_002A23F0* a, int i);
extern "C" bool func_001E84E8(void* s, char* name, int* out, int a);
extern "C" bool func_001E8890(void* s, char* name, int* out, int a);
extern "C" void* func_002C0368();
extern "C" int func_002BD288(void* p);

struct Obj_002A23F0;
extern "C" int func_002A7668(Obj_002A23F0* o);

struct Obj_002A23F0 {
    int Lookup();
};

int Obj_002A23F0::Lookup()
{
    Arr_002A23F0* a = func_001E55F8(D_003783A8, 0);
    for (int i = 0; i < a->size; i++) {
        void* s = func_001E9378(a, i);
        int cur = func_002A7668(this);
        int v;
        func_001E84E8(s, D_00378328, &v, 0);
        if (cur == v) {
            int r;
            func_001E8890(s, D_00392120, &r, 1);
            return r;
        }
    }
    return 0;
}
