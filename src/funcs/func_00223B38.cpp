struct Script_00223B38 {
    char pad[0x18];
    void* m_params;
};

extern "C" bool func_001E7C80(void* self, unsigned int name, const char** out, int assert_);
extern "C" int func_00331BB8(const char* s);
extern "C" void func_001E70C0(void* self, unsigned int name, const char* value);

bool func_00223B38(void* params, Script_00223B38* script)
{
    char name[32];
    const char* path;

    int k = 0;
    func_001E7C80(params, 0xF4AB74F0, &path, 1);
    int len = func_00331BB8(path);
    int i;
    for (i = len; i >= 0; i--) {
        if (path[i] == '/' || path[i] == '\\')
            break;
    }
    for (int j = i + 1; j <= len; j++)
        name[k++] = path[j];
    func_001E70C0(script->m_params, 0x7D99F28D, name);
    return true;
}
