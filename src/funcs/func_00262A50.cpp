extern char D_00375C18[];
extern char D_00375C28[];
extern char D_00375C38[];

struct Str_00262A50 {
    char m[16];
};

struct Profile_00262A50;

struct Table_00262A50 {
    int m0;
    unsigned int m4;
};

extern "C" Profile_00262A50* func_00263320(Table_00262A50* t, const unsigned int& index, int* key);
extern "C" int func_002623B8(Profile_00262A50* p);
extern "C" void func_00261BC0(Profile_00262A50* p, void* out);
extern "C" void* func_00262388(Profile_00262A50* p);
extern "C" void func_002622B8(Str_00262A50* ret, Profile_00262A50* p, char* name);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, void* value);
extern "C" void func_001E7A30(void* params, unsigned int name, int type, char* value);
extern "C" char* func_001041B8(Str_00262A50* s);
extern "C" void func_001040A8(Str_00262A50* s, int flags);

struct Mgr_00262A50 {
    int m0;
    Table_00262A50 m4;
    char m_pad[0x1C - 0xC];
    Profile_00262A50* m1C[2];
    int m24;
    void WriteToStructure(void* out);
};

void Mgr_00262A50::WriteToStructure(void* out)
{
    unsigned int n = m4.m4;
    for (int i = 0; i < n; i++) {
        int key;
        Profile_00262A50* p = func_00263320(&m4, i, &key);
        if (func_002623B8(p))
            func_00261BC0(p, out);
    }
    void* s = func_00262388(m1C[m24]);
    func_001E7A68(out, func_001F0D78(D_00375C18), 0xD, s);
    Str_00262A50 name;
    func_002622B8(&name, m1C[m24], D_00375C28);
    char* str = func_001041B8(&name);
    func_001E7A30(out, func_001F0D78(D_00375C38), 3, str);
    func_001040A8(&name, 2);
}
