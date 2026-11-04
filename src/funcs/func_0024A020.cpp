struct Arr_0024A020 {
    char pad0[0xC];
    unsigned int mC;
};

struct Obj_0024A020 {
    char pad0[0x14];
    void* vt;
    char pad18[0x8C];
    int mA4;
    int mA8;
};

extern char D_00373D00[];
extern char D_00373CA0[];
extern char D_00373CB0[];
extern "C" void func_00243DB8(Obj_0024A020* o, int script);
extern "C" int func_001E82B8(int s, char* name, Arr_0024A020** out, int f);
extern "C" int func_001E9300(Arr_0024A020* a, unsigned int i);
extern "C" int func_00229668(int s, int a);
extern "C" void func_00211410(int id);
extern "C" int func_001E7E58(int s, char* name, int* out, int f);

Obj_0024A020* func_0024A020(Obj_0024A020* o, int script)
{
    func_00243DB8(o, script);
    o->vt = D_00373D00;
    Arr_0024A020* arr;
    if (func_001E82B8(script, D_00373CA0, &arr, 0)) {
        unsigned int i = 0;
        if (arr->mC) {
            do {
                func_00211410(func_00229668(func_001E9300(arr, i++), 1));
            } while (i < arr->mC);
        }
    }
    o->mA4 = 0;
    o->mA8 = 0;
    func_001E7E58(script, D_00373CB0, &o->mA8, 0);
    return o;
}
