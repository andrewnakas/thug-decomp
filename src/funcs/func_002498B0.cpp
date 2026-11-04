extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);

struct Goal_002498B0 {
    int m_0;
    int m_active;

    void Start(void* params);
};

extern "C" int func_00248AA0(Goal_002498B0* self, void** out, int a, int b, const char* name, int c);
extern "C" void func_00248FF8(Goal_002498B0* self, void* obj, int a, unsigned int id, bool flag);

void Goal_002498B0::Start(void* params)
{
    if (m_active)
        return;
    const char* name = 0;
    func_001E7C80(params, 0x82CBE8D1, &name, 0);
    void* obj;
    bool ok = func_00248AA0(this, &obj, -1, 1, name, 1) != 0;
    unsigned int id = 0;
    func_001E8398(params, 0xF0C598FA, &id, 0);
    if (obj)
        func_00248FF8(this, obj, 0, id, ok);
}
