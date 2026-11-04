extern char D_00390E80[];
extern char D_00375C48[];
extern char D_00375C58[];
extern char D_00375C68[];
extern char D_00375C80[];
extern char D_00390E88[];
extern char D_00375C98[];

extern "C" unsigned int func_001F0D78(char* s);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E7E58(void* params, char* name, int* out, int required);
extern "C" bool func_001E81F0(void* params, char* name, void** out, int required);
extern "C" void func_0011FAB8(void* p, void* params, int a);
extern "C" void* func_001200E0(void* p);
extern "C" void func_00123350(void* face, void* params);
extern "C" void func_00103F28(char* fmt, ...);
extern "C" void func_00123428(void* face, bool found);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6B30(void* p);
extern "C" void func_001E6AE8(void* p, int a);

struct Profile_00262D10 {
    int m0;
    char m4[0x58];
    char m5C[4];
};

struct Mgr_00262D10 {
    void Load(void* data, bool keep);
};

extern "C" void func_002628F8(Mgr_00262D10* self, unsigned int name);
extern "C" Profile_00262D10* func_00262990(Mgr_00262D10* self);
extern "C" int func_00261E18(Profile_00262D10* p, unsigned int name);
extern "C" void func_00261E40(Profile_00262D10* p, unsigned int name, int value);
extern "C" int func_00261F80(Profile_00262D10* p);
extern "C" void* func_00262358(Profile_00262D10* p);

void Mgr_00262D10::Load(void* data, bool keep)
{
    func_002628F8(this, 0x0A7BE964);
    Profile_00262D10* prof = func_00262990(this);
    unsigned int key = func_001F0D78(D_00390E80);
    void* params = 0;
    func_001E8180(data, key, &params, 0);
    int version = 0;
    if (!func_001E7E58(params, D_00375C48, &version, 0))
        return;
    if (version != 2)
        return;
    void* sub = 0;
    func_001E81F0(params, D_00375C58, &sub, 0);
    func_0011FAB8(prof->m4, sub, 1);
    void* face = func_001200E0(prof->m4);
    if (face) {
        bool found = func_001E8180(params, 0xF0D3BC94, &sub, 0);
        if (found) {
            func_00123350(face, sub);
            func_00103F28(D_00375C68);
        } else {
            func_00103F28(D_00375C80);
        }
        func_00123428(face, found);
    }
    void* store = prof->m5C;
    int a = func_00261E18(prof, 0x439F4704);
    int b = func_00261E18(prof, 0xAF895B3F);
    int c = func_00261E18(prof, 0x9B65D7B8);
    int d = func_00261E18(prof, 0xF0D90109);
    int e = func_00261E18(prof, 0xEDF5DB70);
    int f = func_00261E18(prof, 0x6DCB497C);
    int g = func_00261E18(prof, 0x9016B4E7);
    int h = func_00261E18(prof, 0xF73A13E3);
    int i = func_00261E18(prof, 0xAE798769);
    int j = func_00261E18(prof, 0xB1FC0722);
    int k = func_00261F80(prof);
    void* saved = func_001E6978(func_001190D0(8));
    func_001E6AC8(saved, func_00262358(prof));
    sub = 0;
    func_001E81F0(params, D_00390E88, &sub, 0);
    func_001E6B30(store);
    func_001E6AC8(store, sub);
    if (!keep) {
        func_00261E40(prof, 0x439F4704, a);
        func_00261E40(prof, 0xAF895B3F, b);
        func_00261E40(prof, 0x9B65D7B8, c);
        func_00261E40(prof, 0xF0D90109, d);
        func_00261E40(prof, 0xEDF5DB70, e);
        func_00261E40(prof, 0x6DCB497C, f);
        func_00261E40(prof, 0x9016B4E7, g);
        func_00261E40(prof, 0xF73A13E3, h);
        func_00261E40(prof, 0xAE798769, i);
        func_00261E40(prof, 0xB1FC0722, j);
        func_00261E40(prof, 0xAC9B9EDA, k);
        func_001E6B30(func_00262358(prof));
        func_001E6AC8(func_00262358(prof), saved);
    }
    if (saved)
        func_001E6AE8(saved, 3);
    int flags = 1;
    func_001E7E58(params, D_00375C98, &flags, 0);
}
