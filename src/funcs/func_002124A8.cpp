struct Array_002124A8 {
    char pad0[0xC];
    unsigned int m_size;
};

extern "C" void func_0010BFC0(char* name);
extern "C" void func_0010BFC8();
extern "C" void func_001F03D0();
extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void func_00229340(const char* name, int a);
extern "C" Array_002124A8* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(Array_002124A8* a, unsigned int index);
extern "C" void func_001E7268(void* s, char* name, unsigned int value);
extern "C" bool func_001E87B8(void* params, char* name);

extern char D_003706E0[];
extern char D_003706F0[];
extern char D_00370700[];
extern char D_003F57E8[];

bool Cmd_LoadNodeArray_002124A8(void* params, void* script)
{
    unsigned int i = 0;
    func_0010BFC0(D_003706E0);
    func_001F03D0();
    const char* name = 0;
    func_001E8870(params, 0, &name, 0);
    func_00331A9C(D_003F57E8, name);
    func_00229340(name, 0);
    Array_002124A8* nodes = func_001E55B8(0xC472ECC5, 0);
    for (; i < nodes->m_size; i++) {
        func_001E7268(func_001E9378(nodes, i), D_003706F0, i);
    }
    func_001E87B8(params, D_00370700);
    func_0010BFC8();
    return true;
}
