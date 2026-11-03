struct Goal_0023E0E8 {
    char pad[0x18];
    void* m18;
};

extern "C" bool func_001E8398(void* self, unsigned int name, unsigned int* out, int assert_);
extern "C" Goal_0023E0E8* func_0023BAD8(void* self, unsigned int id, int flag);
extern "C" void func_00248FF8(void* self, unsigned int id, int a, int b, int c);
extern "C" bool func_001E7C80(void* self, unsigned int name, const char** out, int assert_);
extern "C" void func_00249208(void* self, const char* text, void* params);

void func_0023E0E8(void* mgr, void* params)
{
    unsigned int name;
    unsigned int id;
    const char* text;

    func_001E8398(params, 0xA1DC81F9, &name, 1);
    Goal_0023E0E8* goal = func_0023BAD8(mgr, name, 1);
    id = 0;
    func_001E8398(params, 0x1A4E4FB9, &id, 0);
    if (id) {
        func_00248FF8(goal->m18, id, 1, 0, 0);
        return;
    }
    text = 0;
    if (func_001E7C80(params, 0x7321A8D6, &text, 0))
        func_00249208(goal->m18, text, params);
}
