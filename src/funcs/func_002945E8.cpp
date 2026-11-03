struct Arr_002945E8 { char pad[0xC]; int mC; };
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" int func_001E8708(void* p, unsigned int key);
extern "C" int func_001E7C80(void* p, unsigned int key, char** out, int req);
extern "C" int func_001E8248(void* p, unsigned int key, Arr_002945E8** out, int req);
extern "C" int func_001E9270(Arr_002945E8*, int);
extern "C" char* func_00331A9C(char*, char*);

struct Obj_002945E8;
extern "C" void func_00294178(Obj_002945E8*, void*);

struct Obj_002945E8 {
    char pad0[0x114];
    unsigned int m114;
    char pad1[0x2B4 - 0x118];
    int m2B4;
    char pad2[0x2D0 - 0x2B8];
    int m2D0;
    int m2D4;
    int m2D8;
    int m2DC;
    char pad3[0x30C - 0x2E0];
    unsigned char m30C[10];
    unsigned char m316;
    char m317[1];
    void Load(void* s);
};

void Obj_002945E8::Load(void* s)
{
    switch (m114) {
    case 0xEA7BA666:
        func_001E7DE8(s, 0x45A375C9, &m2D8, 0);
        func_001E7DE8(s, 0xBFD3A831, &m2DC, 0);
        func_00294178(this, s);
        break;
    case 0x0FC6F698:
        func_001E7DE8(s, 0x67DD90CA, &m2D4, 0);
        if (func_001E8708(s, 0xDF47B144)) m2D0 = 1;
        func_00294178(this, s);
        break;
    case 0x7FE2238A:
        func_00294178(this, s);
        break;
    case 0x6FE44C6D:
    case 0xEC414B76:
        func_001E7DE8(s, 0xCD66C8AE, &m2B4, 0);
        break;
    case 0x61C5D092: {
        char* str = 0;
        if (func_001E7C80(s, 0x730844A3, &str, 0)) func_00331A9C(m317, str);
        Arr_002945E8* a = 0;
        func_001E8248(s, 0xD76C173E, &a, 0);
        if (a) {
            int n = a->mC;
            m316 = n;
            for (int i = 0; i < m316; i++) {
                m30C[i] = func_001E9270(a, i);
            }
        }
        break;
    }
    }
}
