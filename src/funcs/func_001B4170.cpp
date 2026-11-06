extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_00100030(int n);

struct Obj_001B4170 {
    int Method(void* params, unsigned int name);
};

int Obj_001B4170::Method(void* params, unsigned int name)
{
    float chance;
    func_001E7EB0(params, name, &chance, 1);
    if (chance > 0.99f)
        return 1;
    return (float)func_00100030(1000) < chance * 1000.0f;
}
