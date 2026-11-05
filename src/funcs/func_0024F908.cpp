extern "C" bool func_001E88D8(void* p, unsigned int name, int* out, int required);

struct Obj_0024F908 {
    int m0;
    char m4[0x10];
    bool Get(unsigned int name);
};

bool Obj_0024F908::Get(unsigned int name)
{
    int v;
    func_001E88D8(m4, name, &v, 1);
    return v != 0;
}
