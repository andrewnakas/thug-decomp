extern void* D_0038FC78;
extern char D_00373C38[];

struct Goal_00249208;
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_00248FF8(Goal_00249208* self, unsigned int goal, int a, unsigned int b, bool c);
extern "C" void* func_0022E368(void* mgr, int a);
extern "C" bool func_002623B8(void* obj);
extern "C" const char* func_00248950(Goal_00249208* self);
extern "C" void func_00248F40(Goal_00249208* self, char* buf, int size);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90A8(void* arr, int i, int v);
extern "C" int func_001E9270(void* arr, int i);
extern "C" int func_00100030(int n);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" bool func_001E11A8(unsigned int name);
extern "C" void func_001E6518(void* arr);
extern "C" void func_001E8DE8(void* arr, int flags);
extern "C" void func_00249960(Goal_00249208* self);
extern "C" void func_00249878(Goal_00249208* self);
extern "C" void func_00249998(Goal_00249208* self, const char* type, int base, int extra, int arg);

struct Goal_00249208 {
    int m_0;
    int m_active;
    void Start(const char* type, void* params);
};

void Goal_00249208::Start(const char* type, void* params)
{
    if (m_active) {
        return;
    }
    bool done = false;
    bool a = func_001E8708(params, 0x2BE2056A);
    bool b = func_001E8708(params, 0x9F38B332);
    unsigned int goal;
    if (func_001E8398(params, 0x1A4E4FB9, &goal, 0)) {
        func_00248FF8(this, goal, 1, 0, 0);
        return;
    }
    if (a || b) {
        if (func_002623B8(func_0022E368(D_0038FC78, 0))) {
            const char* prefix = func_00248950(this);
            char word[0x80];
            char name[0x80];
            func_00248F40(this, word, 0x80);
            void* arr = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(arr, 5, 1);
            for (int i = 0; i < 5; i++) {
                func_001E90A8(arr, i, i + 1);
            }
            for (int i = 0; i < 5; i++) {
                int j = func_00100030(5);
                int t = func_001E9270(arr, j);
                func_001E90A8(arr, j, func_001E9270(arr, i));
                func_001E90A8(arr, i, t);
            }
            for (int i = 0; i < 5; i++) {
                func_003331D0(name, D_00373C38, prefix, word, i + 1);
                if (func_001E11A8(func_001F0D78(name))) {
                    done = true;
                    func_00248FF8(this, func_001F0D78(name), 1, 0, 0);
                    break;
                }
            }
            func_001E6518(arr);
            if (arr) {
                func_001E8DE8(arr, 3);
            }
        }
        if (!done) {
            b = false;
            a = true;
        }
    }
    if ((b || a) && !done) {
        switch (func_001F0D78(type)) {
        case 0x82117C1A:
            func_00249878(this);
            break;
        case 0x1623B689:
            func_00249960(this);
            break;
        default:
            func_00249998(this, type, 10, 0, 1);
            break;
        }
    }
}
