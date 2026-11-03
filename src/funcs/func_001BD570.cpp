typedef int qword __attribute__((mode(TI)));

struct Vec_001BD570 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern "C" int func_001E8958(void* params, unsigned int name, Vec_001BD570* out, int req);
extern "C" int func_001E8918(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8A30(void* params, unsigned int name, void* out, int req);
extern "C" int func_001E8A80(void* params, unsigned int name, void** out, int req);
extern "C" int func_001E9270(void* arr, int i);
extern "C" void func_001423C0(void* o, int i, Vec_001BD570* v);
extern "C" void func_001423D8(void* o, int i, Vec_001BD570* v);
extern "C" void func_001423F0(void* o, int i, unsigned char* c);
extern "C" void func_00142398(void* o, float f);
extern "C" void func_001423A0(void* o, float f);
extern "C" void func_00142410(void* o, float f);
extern "C" void func_001423A8(void* o, float f);
extern "C" void func_001423B0(void* o, float f, int i);

struct C_001BD570 {
    int m_pad[7];
    int m1C;
    void* m20;
    int Call(unsigned int name, void* params);
};

int C_001BD570::Call(unsigned int name, void* params)
{
    union {
        Vec_001BD570 v;
        unsigned char c[4];
    } u;
    switch (name) {
    case 0x88BE2262:
        func_001E8958(params, 0, &u.v, 1);
        if (m20) func_001423C0(m20, 0, &u.v);
        break;
    case 0xBB6018F4:
        func_001E8958(params, 0, &u.v, 1);
        if (m20) func_001423C0(m20, 1, &u.v);
        break;
    case 0xE5134689:
        func_001E8958(params, 0, &u.v, 1);
        if (m20) func_001423C0(m20, 2, &u.v);
        break;
    case 0xF71D696E:
        func_001E8958(params, 0, &u.v, 1);
        if (m20) func_001423D8(m20, 0, &u.v);
        break;
    case 0x0AAB006D:
        func_001E8958(params, 0, &u.v, 1);
        if (m20) func_001423D8(m20, 1, &u.v);
        break;
    case 0xE2B99038:
        func_001E8958(params, 0, &u.v, 1);
        if (m20) func_001423D8(m20, 2, &u.v);
        break;
    case 0xC036F4D0:
        func_001E8A30(params, 0, &m1C, 1);
        break;
    case 0xC6525C4E: {
        float f;
        func_001E8918(params, 0, &f, 1);
        if (m20) func_00142398(m20, f);
        break;
    }
    case 0x31FCC8ED: {
        float f;
        func_001E8918(params, 0, &f, 1);
        if (m20) func_001423A0(m20, f);
        break;
    }
    case 0x19AF74D1: {
        float f;
        func_001E8918(params, 0, &f, 1);
        if (m20) func_00142410(m20, f);
        break;
    }
    case 0x4AA40FB5: {
        float f;
        func_001E8918(params, 0, &f, 1);
        if (m20) func_001423A8(m20, f);
        break;
    }
    case 0x234CEABB: {
        float f;
        func_001E8918(params, 0, &f, 1);
        if (m20) func_001423B0(m20, f, 0);
        break;
    }
    case 0x9E100F60: {
        float f;
        func_001E8918(params, 0, &f, 1);
        if (m20) func_001423B0(m20, f, 1);
        break;
    }
    case 0x2F0DA461: {
        float f;
        func_001E8918(params, 0, &f, 1);
        if (m20) func_001423B0(m20, f, 2);
        break;
    }
    case 0xEEFFAE18: {
        void* arr;
        func_001E8A80(params, 0, &arr, 1);
        if (m20) {
            u.c[0] = func_001E9270(arr, 0);
            u.c[1] = func_001E9270(arr, 1);
            u.c[2] = func_001E9270(arr, 2);
            u.c[3] = func_001E9270(arr, 3);
            func_001423F0(m20, 0, u.c);
        }
        break;
    }
    case 0x0FE869E8: {
        void* arr;
        func_001E8A80(params, 0, &arr, 1);
        if (m20) {
            u.c[0] = func_001E9270(arr, 0);
            u.c[1] = func_001E9270(arr, 1);
            u.c[2] = func_001E9270(arr, 2);
            u.c[3] = func_001E9270(arr, 3);
            func_001423F0(m20, 1, u.c);
        }
        break;
    }
    case 0x19AA4CD3: {
        void* arr;
        func_001E8A80(params, 0, &arr, 1);
        if (m20) {
            u.c[0] = func_001E9270(arr, 0);
            u.c[1] = func_001E9270(arr, 1);
            u.c[2] = func_001E9270(arr, 2);
            u.c[3] = func_001E9270(arr, 3);
            func_001423F0(m20, 2, u.c);
        }
        break;
    }
    default:
        return 2;
    }
    return 1;
}
