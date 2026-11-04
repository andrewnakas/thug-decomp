struct Heap_001E9D70 {
    char pad[0xEC];
    int mEC;
};
extern Heap_001E9D70* D_00388A70;

struct Struct_001E9D70;
struct Array_001E9D70;

extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void func_001E6B30(Struct_001E9D70*);
extern "C" Array_001E9D70* func_001E55B8(unsigned int, int);
extern "C" unsigned int func_001E9300(Array_001E9D70*, unsigned int);
extern "C" int func_001EC7A0(unsigned char*);
extern "C" int func_001EC7E0(unsigned char*);
extern "C" void func_001E7200(Struct_001E9D70*, unsigned int, int);
extern "C" void func_001E72B0(Struct_001E9D70*, unsigned int, float);
extern "C" void func_001E7360(Struct_001E9D70*, unsigned int, int);
extern "C" void func_001E70C0(Struct_001E9D70*, unsigned int, unsigned char*);
extern "C" void func_001E7180(Struct_001E9D70*, unsigned int, unsigned char*);
extern "C" unsigned int func_00331BB8(unsigned char*);
extern "C" void func_001E7558(Struct_001E9D70*, unsigned int, float, float);
extern "C" void func_001E7410(Struct_001E9D70*, unsigned int, float, float, float);
extern "C" void* func_001190D0(unsigned int);
extern "C" Struct_001E9D70* func_001E6978(void*);
extern "C" void func_001E78A8(Struct_001E9D70*, unsigned int, Struct_001E9D70*);
extern "C" void* func_00122CF8(unsigned int);
extern "C" Array_001E9D70* func_001E8DD0(void*);
extern "C" unsigned char* func_001EA538(Array_001E9D70*, unsigned char*);
extern "C" void func_001E7720(Struct_001E9D70*, unsigned int, Array_001E9D70*);

static inline float ReadFloat_001E9D70(unsigned char* p)
{
    union {
        int i;
        float f;
    } u;
    u.i = func_001EC7A0(p);
    return u.f;
}

extern "C" unsigned char* func_001E9D70(Struct_001E9D70* s, unsigned char* p)
{
    func_001E6B30(s);
    func_0010A950(D_00388A70, D_00388A70->mEC);
    unsigned int type;
    float x, y, z;
    while ((type = *p++) != 0) {
        unsigned int name;
        if (type & 0x80) {
            name = func_001E9300(func_001E55B8(0x35115A20, 0), *p++);
        } else if (type & 0x40) {
            Array_001E9D70* a = func_001E55B8(0x25231F42, 0);
            unsigned short v = func_001EC7E0(p);
            p += 2;
            name = func_001E9300(a, v);
        } else {
            name = func_001EC7A0(p);
            p += 4;
        }
        type &= ~0xC0u;
        switch (type) {
        case 1: {
            int v = func_001EC7A0(p);
            p += 4;
            func_001E7200(s, name, v);
            break;
        }
        case 2: {
            float v = ReadFloat_001E9D70(p);
            p += 4;
            func_001E72B0(s, name, v);
            break;
        }
        case 13: {
            int v = func_001EC7A0(p);
            p += 4;
            func_001E7360(s, name, v);
            break;
        }
        case 19:
            func_001E72B0(s, name, 0.0f);
            break;
        case 18:
            func_001E7200(s, name, 0);
            break;
        case 14: {
            int v = (signed char)*p;
            p++;
            func_001E7200(s, name, v);
            break;
        }
        case 16: {
            int v = *p;
            p++;
            func_001E7200(s, name, v);
            break;
        }
        case 15: {
            short v = func_001EC7E0(p);
            p += 2;
            func_001E7200(s, name, v);
            break;
        }
        case 17: {
            unsigned short v = func_001EC7E0(p);
            p += 2;
            func_001E7200(s, name, v);
            break;
        }
        case 3:
            func_001E70C0(s, name, p);
            p += func_00331BB8(p);
            p++;
            break;
        case 4:
            func_001E7180(s, name, p);
            p += func_00331BB8(p);
            p++;
            break;
        case 5: {
            x = ReadFloat_001E9D70(p);
            p += 4;
            y = ReadFloat_001E9D70(p);
            p += 4;
            func_001E7558(s, name, x, y);
            break;
        }
        case 6: {
            x = ReadFloat_001E9D70(p);
            p += 4;
            y = ReadFloat_001E9D70(p);
            p += 4;
            z = ReadFloat_001E9D70(p);
            p += 4;
            func_001E7410(s, name, x, y, z);
            break;
        }
        case 10: {
            Struct_001E9D70* sub = func_001E6978(func_001190D0(8));
            p = func_001E9D70(sub, p);
            func_001E78A8(s, name, sub);
            break;
        }
        case 12: {
            Array_001E9D70* sub = func_001E8DD0(func_00122CF8(16));
            p = func_001EA538(sub, p);
            func_001E7720(s, name, sub);
            break;
        }
        }
    }
    func_0010A9B0(D_00388A70);
    return p;
}
