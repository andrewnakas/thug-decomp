extern "C" bool func_001E8180(void* params, unsigned int name, int* out, int required);

struct Obj_00202EF8 {
    int m0;
    char m4[0x10];
    int Get(unsigned int name);
};

int Obj_00202EF8::Get(unsigned int name)
{
    int v = 0;
    func_001E8180(m4, name, &v, 0);
    return v;
}
