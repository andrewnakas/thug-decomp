extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Obj_00248230 {
    char pad[0x20];
    void* m20;
    char pad24[0x38];
    int m5C;
    int Fn();
};

int Obj_00248230::Fn()
{
    int v = m5C;
    func_001E7DE8(m20, 0x1171A555, &v, 0);
    if (v) return v;
    return -1;
}
