extern "C" int func_001E70C0(void* p, unsigned int name, void* v);

struct Obj_002407B0 {
    char pad0[0x54];
    void* m54;
    int Get(void* v);
};

int Obj_002407B0::Get(void* v)
{
    return func_001E70C0(m54, 0x703D7582, v);
}
