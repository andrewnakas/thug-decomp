extern char D_00379F50[];
extern char D_00379F68[];
extern char D_00379F78[];
extern char D_00379F88[];

extern "C" void* func_001E5588(char* name, int v);
extern "C" int func_00331950(char* a, char* b);
extern "C" int func_001E82B8(void* s, char* name, int* out, int v);
extern "C" int func_001E7E58(void* s, char* name, int* out, int v);
extern "C" int func_001E9270(int a, int b);
extern "C" void* func_002C0368();
extern "C" int func_002BD248(void* p);

struct Obj_002B73B8 {
    int GetStat(char* name);
};

int Obj_002B73B8::GetStat(char* name)
{
    int a;
    int b;
    int r;
    int d;
    void* s = func_001E5588(D_00379F50, 0);
    if (!func_00331950(name, D_00379F68)) {
        func_001E82B8(s, name, &a, 0);
        r = func_001E9270(a, 0);
    } else if (!func_00331950(name, D_00379F78)) {
        func_001E82B8(s, name, &b, 0);
        r = func_001E9270(b, 0);
    } else if (func_00331950(name, D_00379F88)) {
        if (!func_001E7E58(s, name, &r, 0))
            return 0;
    } else {
        int x = func_002BD248(func_002C0368());
        func_001E82B8(s, name, &d, 0);
        r = func_001E9270(d, x);
    }
    return r;
}
