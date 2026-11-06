extern char D_00361BF8[];
extern "C" int func_001E7E58(void* p, void* d, int* out, int n);
struct Obj_00187D68 {
    int m0, m4, m8, mC;
    void* m10;
    int Get();
};

int Obj_00187D68::Get()
{
    int v = 0;
    if (m10) {
        func_001E7E58(m10, D_00361BF8, &v, 0);
    }
    return v;
}
