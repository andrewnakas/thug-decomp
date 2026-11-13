extern void* D_0038FC78;
extern char D_00390078[];
extern char D_00373C58[];
extern char D_00373C68[];

struct Goal_00249998;
extern "C" void func_00249C58(Goal_00249998* self);
extern "C" const char* func_00248950(Goal_00249998* self);
extern "C" void* func_0022E368(void* mgr, int a);
extern "C" char* func_002624F0(void* obj);
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90A8(void* arr, int i, int v);
extern "C" int func_001E9270(void* arr, int i);
extern "C" int func_00100030(int n);
extern "C" bool func_002623B8(void* obj);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" bool func_001E11A8(unsigned int name);
extern "C" void func_00248FF8(Goal_00249998* self, unsigned int goal, int a, unsigned int b, bool c);
extern "C" void func_001E6518(void* arr);
extern "C" void func_001E8DE8(void* arr, int flags);

static inline void CopyWord_00249998(char*& p, char* d)
{
    while (*p != ' ') {
        *d = *p;
        p++;
        d++;
    }
    *d = 0;
}

static inline void GetWord_00249998(char*& p, char* d)
{
    if (!func_003364D8(p, D_00390078)) {
        func_00331A9C(d, p);
    } else {
        CopyWord_00249998(p, d);
    }
}

struct Goal_00249998 {
    int m_0;
    int m_active;
    void Pick(const char* type, int base, int extra, int arg);
};

void Goal_00249998::Pick(const char* type, int base, int extra, int arg)
{
    if (m_active) {
        return;
    }
    func_00249C58(this);
    const char* prefix = func_00248950(this);
    if (!prefix) {
        return;
    }
    void* obj = func_0022E368(D_0038FC78, 0);
    char word[0x80];
    char name[0x80];
    char* p = func_002624F0(obj);
    GetWord_00249998(p, word);
    int n = base;
    if (extra) {
        n = base + 20;
    }
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, n, 1);
    for (int i = 0; i < n; i++) {
        func_001E90A8(arr, i, i + 1);
    }
    for (int i = 0; i < n; i++) {
        int j = func_00100030(n);
        int a = func_001E9270(arr, j);
        func_001E90A8(arr, j, func_001E9270(arr, i));
        func_001E90A8(arr, i, a);
    }
    for (int i = 0; i < n; i++) {
        int v = func_001E9270(arr, i);
        if (v > base) {
            if (!func_002623B8(obj)) continue;
            func_003331D0(name, D_00373C58, prefix, type, word, v - base);
            if (func_001E11A8(func_001F0D78(name))) {
                func_00248FF8(this, func_001F0D78(name), arg, 0, 0);
                break;
            }
        } else {
            func_003331D0(name, D_00373C68, prefix, type, v);
            if (func_001E11A8(func_001F0D78(name))) {
                func_00248FF8(this, func_001F0D78(name), arg, 0, 0);
                break;
            }
        }
    }
    func_001E6518(arr);
    if (arr) {
        func_001E8DE8(arr, 3);
    }
}
