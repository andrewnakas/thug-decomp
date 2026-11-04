extern char D_0038F4F8[];
extern char D_0038F540[];
extern char D_0038F548[];

extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_001317D0(unsigned int id);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" void func_00135558(void* model, float a, float b);

bool func_00212B98(void* params)
{
    unsigned int id;
    float a;
    float b;
    func_001E84E8(params, D_0038F4F8, &id, 0);
    void* model = func_001317D0(id);
    func_001E7F50(params, D_0038F540, &a, 0);
    func_001E7F50(params, D_0038F548, &b, 0);
    func_00135558(model, a, b);
    return true;
}
