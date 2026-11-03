struct Arr_002A22D0 {
    char pad[0xC];
    int size;
};

extern char D_00378388[];
extern char D_00392118[];
extern char D_003920C0[];
extern "C" Arr_002A22D0* func_001E55F8(char* name, int a);
extern "C" void* func_001E9378(Arr_002A22D0* a, int i);
extern "C" bool func_001E84E8(void* s, char* name, int* out, int a);
extern "C" bool func_001E8890(void* s, char* name, int* out, int a);
extern "C" void* func_002C0368();
extern "C" int func_002BD288(void* p);

struct Obj_002A22D0;
extern "C" int func_002A58C0(Obj_002A22D0* o);

struct Obj_002A22D0 {
    int Lookup(bool flag);
};

int Obj_002A22D0::Lookup(bool flag)
{
    Arr_002A22D0* a = func_001E55F8(D_00378388, 0);
    for (int i = 0; i < a->size; i++) {
        void* s = func_001E9378(a, i);
        int v;
        func_001E84E8(s, D_00392118, &v, 0);
        int cur = func_002A58C0(this);
        if (cur == v) {
            if (flag && cur == (int)0xB664035D)
                return func_002BD288(func_002C0368());
            int r;
            func_001E8890(s, D_003920C0, &r, 1);
            return r;
        }
    }
    return 0;
}
