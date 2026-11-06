extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Obj_001A53D0 {
    char pad0[0x214];
    int m214;
    int m218;
    void Fn(void* params);
};

extern "C" void func_001A8210(Obj_001A53D0* self, void* params);

void Obj_001A53D0::Fn(void* params)
{
    int v = -1;
    func_001E7DE8(params, 0xE50D6573, &v, 0);
    m218 = v;
    m214 = v;
    func_001A8210(this, params);
}
