extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);

struct Obj_00248800 {
    char pad[0x20];
    void* m20;
    bool Fn(unsigned int name);
};

bool Obj_00248800::Fn(unsigned int name)
{
    unsigned int v;
    if (func_001E8398(m20, name, &v, 0)) {
        func_001F0210(v, m20, 0, 0, 0);
        return true;
    }
    return false;
}
