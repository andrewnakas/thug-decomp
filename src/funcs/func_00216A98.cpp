extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" bool func_001E88F8(void* s, const char* name, int* out, int required);
extern "C" bool func_001E8A50(void* s, const char* name, unsigned int* out, int required);
extern "C" unsigned int func_00331BB8(const char* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_001F0370(const char* name, void* params, int a, int b);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void* func_001E9378(void* arr, int i);

struct Array_00216A98 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

extern "C" Array_00216A98* func_001E55F8(const char* name, int a);

extern char D_0038F610[];
extern char D_00370B98[];
extern char D_00370BB0[];
extern char D_0038F2C8[];
extern char D_00370BC8[];
extern char D_00370BF8[];
extern char D_0038F638[];
extern char D_0038F640[];
extern char D_00370C08[];
extern char D_00370C18[];

bool Cmd_00216A98(void* params, void* script)
{
    char buf[0x80];
    const char* code;
    func_001E8890(params, D_0038F610, &code, 1);
    if (func_00331BB8(code) < 6) {
        func_001F0370(D_00370B98, 0, 0, 0);
        return false;
    }
    func_003331D0(buf, D_00370BB0);
    int sum = 0;
    int i = 0;
    func_003331D0(buf, code);
    unsigned int crc = func_001F0D78(code);
    do {
        func_003331D0(buf, D_0038F2C8, i + crc);
        i++;
        buf[func_00331BB8(buf)] = 'X';
        for (char* p = buf; *p; p++) {
            sum += *p * 1023;
        }
        crc = func_001F0D78(buf);
    } while (i <= 99999);
    unsigned int c1 = func_001F0D78(code + func_00331BB8(code) / 3);
    unsigned int c2 = func_001F0D78(buf);
    c1 ^= sum;
    c2 ^= sum;
    func_00103F28(D_00370BC8, c1, c2, code);
    Array_00216A98* arr = func_001E55F8(D_00370BF8, 0);
    int n = arr->m_size;
    bool found = false;
    for (int k = 0; k < n; k++) {
        void* s = func_001E9378(arr, k);
        int a;
        int b;
        unsigned int cheat;
        func_001E88F8(s, D_0038F638, &a, 1);
        func_001E88F8(s, D_0038F640, &b, 1);
        func_001E8A50(s, D_00370C08, &cheat, 1);
        if (a == c1 && b == c2) {
            func_001F0370(D_00370C18, 0, 0, 0);
            found = true;
            func_001F0210(cheat, 0, 0, 0, 0);
        }
    }
    if (!found) {
        func_001F0370(D_00370B98, 0, 0, 0);
    }
    return false;
}
