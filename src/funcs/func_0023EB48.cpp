struct Mgr_0023EB48 {
    char pad[0x1C];
    void* m_1C;
    bool Check(unsigned int id);
};

extern "C" void* func_0023BAD8(Mgr_0023EB48* self, unsigned int id, int create);
extern "C" bool func_002458B8(void* item);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Mgr_0023EB48::Check(unsigned int id)
{
    void* item = func_0023BAD8(this, id, 0);
    if (item) {
        return func_002458B8(item);
    }
    void* sub;
    int v = 0;
    if (func_001E8180(m_1C, id, &sub, 0)) {
        func_001E7DE8(sub, 0xD3E93882, &v, 1);
    }
    return v != 0;
}
