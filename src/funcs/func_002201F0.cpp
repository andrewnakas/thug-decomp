extern char D_00371828[];
extern char D_0038F808[];
extern char D_0038F8A0[];
extern char D_00371838[];

struct Mgr_002201F0 {
    char m_pad[0x398];
    void* m398;
};

struct Str_002201F0 {
    char m_data[0x10];
};

extern Mgr_002201F0* D_0038FC78;

extern "C" bool func_001E8A50(void* self, const char* name, int* out, int assert_);
extern "C" void func_002527B0(Str_002201F0* out, void* self, int index);
extern "C" int func_00252270(void* self);
extern "C" int func_0022DF08(Mgr_002201F0* self, int value);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6A50(void* self, void* src);
extern "C" const char* func_001041B8(Str_002201F0* self);
extern "C" void func_001E7138(void* self, const char* name, const char* value);
extern "C" void func_001E73C8(void* self, const char* name, int value);
extern "C" void func_001F0370(const char* name, void* params, int id, int flags);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" void func_001040A8(Str_002201F0* self, int flags);

bool func_002201F0(void* params)
{
    Str_002201F0 str;
    int which;
    int id;
    func_001E8A50(params, D_00371828, &which, 1);
    func_001E8A50(params, D_0038F808, &id, 1);
    func_002527B0(&str, D_0038FC78->m398, which);
    Mgr_002201F0* mgr = D_0038FC78;
    int value = func_0022DF08(mgr, func_00252270(mgr->m398));
    void* p = func_001E6978(func_001190D0(8));
    func_001E6A50(p, params);
    func_001E7138(p, D_0038F8A0, func_001041B8(&str));
    func_001E73C8(p, D_0038F808, id);
    func_001F0370(D_00371838, p, value, 0);
    if (p) {
        func_001E6AE8(p, 3);
    }
    func_001040A8(&str, 2);
    return true;
}
