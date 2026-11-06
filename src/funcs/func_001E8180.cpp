extern "C" bool func_001E7B58(void* self, int name, int type, int* out);
extern "C" void func_001E93D0(void* self, int a);

struct Params_001E8180 {
    int m0;
    bool GetInt(int name, int* out, int required);
};

bool Params_001E8180::GetInt(int name, int* out, int required)
{
    int v;
    if (func_001E7B58(this, name, 10, &v)) {
        *out = v;
        return true;
    }
    if (required)
        func_001E93D0(this, 0);
    return false;
}
