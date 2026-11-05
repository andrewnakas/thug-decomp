struct Pair_001E8310 {
    unsigned int m_name;
    int m_value;
};

extern "C" int func_001E7B58(void* params, unsigned int name, int type, int* out);
extern "C" void func_001E93D0(void* params, int a);

extern "C" bool func_001E8310(void* params, unsigned int name, Pair_001E8310* out, int req)
{
    int v;
    if (func_001E7B58(params, name, 7, &v)) {
        out->m_name = name;
        out->m_value = v;
        return true;
    }
    if (req)
        func_001E93D0(params, 0);
    return false;
}
