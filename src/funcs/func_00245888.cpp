extern "C" bool func_001E7DE8(void* p, unsigned int name, int* out, int required);

struct Obj_00245888 {
    char pad0[0x24];
    void* m24;
    bool Get(unsigned int name);
};

bool Obj_00245888::Get(unsigned int name)
{
    int v;
    func_001E7DE8(m24, name, &v, 1);
    return v != 0;
}
