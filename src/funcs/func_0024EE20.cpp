extern "C" int func_001E86D0(void* params, const char* name);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E6B90(void* params, unsigned int name);

struct Obj_0024EE20 {
    int m0;
    char m_params[4];
    bool Fn(const char* name, void* params);
};

bool Obj_0024EE20::Fn(const char* name, void* params)
{
    if (func_001E86D0(params, name)) {
        func_001E6B90(m_params, func_001F0D78(name));
        return true;
    }
    return false;
}
