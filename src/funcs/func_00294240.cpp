extern char D_00391E18[];

struct Obj_00294240 {
    char pad0[0x114];
    unsigned int m114;
    char pad118[0x2B4 - 0x118];
    int m2B4;
    char pad2B8[0x2C8 - 0x2B8];
    int m2C8;
    int pad2CC;
    int m2D0;
    int m2D4;
    int m2D8;
    int m2DC;
    char pad2E0[0x30C - 0x2E0];
    unsigned char m30C[10];
    unsigned char m316;
    char m317[1];
    void Save(void* p, int v);
};

extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001E70C0(void* p, unsigned int name, char* s);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);
extern "C" void func_002940A0(Obj_00294240* o, void* p, int v);
extern "C" char* func_001E5488(unsigned int id, int v);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* a, int n, int t);
extern "C" void func_001E90A8(void* a, int i, int v);
extern "C" void func_001E90F8(void* a, int i, int v);
extern "C" int func_001F0D78(char* s);

void Obj_00294240::Save(void* p, int v)
{
    switch (m114) {
    case 0xEA7BA666:
        func_001E7360(p, 0, 0xEA7BA666);
        func_001E7200(p, 0x45A375C9, m2D8);
        func_001E7200(p, 0xBFD3A831, m2DC);
        m2C8 = m2D8;
        func_002940A0(this, p, v);
        break;
    case 0x0FC6F698:
        func_001E7360(p, 0, 0x4EC3CFB5);
        func_001E7200(p, 0x67DD90CA, m2D4);
        if (m2D0) {
            func_001E7360(p, 0, 0xDF47B144);
            m2C8 = m2D4;
        }
    case 0x7FE2238A:
        func_002940A0(this, p, v);
        break;
    case 0x6FE44C6D:
    case 0xEC414B76:
        func_001E7200(p, 0xCD66C8AE, m2B4);
        if (v == 1) {
            char buf[100];
            char* fmt;
            if (m114 == 0xEC414B76) fmt = func_001E5488(0x3693BFE4, 0);
            else fmt = func_001E5488(0xD6EFB1B5, 0);
            func_003331D0(buf, fmt, m2B4);
            func_001E70C0(p, 0xDA441D9A, buf);
        }
        break;
    case 0x61C5D092:
        func_001E70C0(p, 0x730844A3, m317);
        if (v == 1) {
            char buf[100];
            void* arr = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(arr, m316, 0xD);
            for (int i = 0; i < m316; i++) {
                func_003331D0(buf, D_00391E18, i + 1);
                func_001E90F8(arr, i, func_001F0D78(buf));
            }
            func_001E7720(p, 0xCC3C4CC4, arr);
            void* arr2 = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(arr2, m316, 1);
            for (int i = 0; i < m316; i++) {
                func_001E90A8(arr2, i, m30C[i]);
            }
            func_001E7720(p, 0x52D4489E, arr2);
        } else if (m316) {
            void* arr = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(arr, m316, 1);
            for (int i = 0; i < m316; i++) {
                func_001E90A8(arr, i, m30C[i]);
            }
            func_001E7720(p, 0xD76C173E, arr);
        }
        break;
    }
}
