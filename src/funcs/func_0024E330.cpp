struct Obj_0024E330;
extern char D_00374530[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" int func_00244E90(Obj_0024E330* self);

struct Obj_0024E330 {
    char pad[0x20];
    void* m20;
    int Fn();
};

int Obj_0024E330::Fn()
{
    int v = 0;
    func_001E7E58(m20, D_00374530, &v, 1);
    if (v == 1) return 0;
    return func_00244E90(this);
}
