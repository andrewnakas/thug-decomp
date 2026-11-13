/* force: {"kind": "sched", "pass": 2, "block": 2, "clock": 3, "first": [46, 48]} */
/* force: {"kind": "sched", "pass": 2, "block": 3, "clock": 3, "first": [79, 81]} */
/* force: {"kind": "sched", "pass": 2, "block": 5, "clock": 6, "first": [121, 123]} */
struct Comp_001EBC48 {
    char m_0;
    unsigned char m_type;
    char m_pad2[0x4 - 2];
    int m_name;
    void* m_8;
};

struct Struct_001EBC48;
struct Heap_001EBC48 {
    char m_pad[0xEC];
    int m_EC;
};

extern Heap_001EBC48* D_00388A70;
extern "C" int func_001EC7A0(unsigned char* p);
extern "C" void func_001E7360(Struct_001EBC48* s, int name, int v);
extern "C" void func_001E7200(Struct_001EBC48* s, int name, int v);
extern "C" void func_001E72B0(Struct_001EBC48* s, int name, float v);
extern "C" void func_001E7410(Struct_001EBC48* s, int name, float x, float y, float z);
extern "C" void func_001E7558(Struct_001EBC48* s, int name, float x, float y);
extern "C" void func_001E70C0(Struct_001EBC48* s, int name, unsigned char* str);
extern "C" void func_001E7180(Struct_001EBC48* s, int name, unsigned char* str);
extern "C" void* func_001E8CD0(int size);
extern "C" Comp_001EBC48* func_001E4ED8(void* mem);
extern "C" unsigned char* func_001EB180(unsigned char* p, Comp_001EBC48* c, int flag);
extern "C" void func_001E6F90(Struct_001EBC48* s, Comp_001EBC48* c);
extern "C" void* func_001190D0(int size);
extern "C" Struct_001EBC48* func_001E6978(void* mem);
extern "C" unsigned char* func_001EC088(Struct_001EBC48* s, unsigned char* p, Struct_001EBC48* params);
extern "C" void func_001E78A8(Struct_001EBC48* s, int name, Struct_001EBC48* v);
extern "C" void func_0010A950(void* heap, int a);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" unsigned char* func_001EB450(void* a, unsigned char* p, Struct_001EBC48* params);
extern "C" void func_001E7720(Struct_001EBC48* s, int name, void* a);
extern "C" unsigned char* func_001ECD40(unsigned char* p);
extern "C" void func_001E7958(Struct_001EBC48* s, int name, unsigned char* data, int size);
extern "C" Comp_001EBC48* func_001E6DD0(Struct_001EBC48* params, int name);
extern "C" void func_001E6AC8(Struct_001EBC48* s, void* src);
extern "C" void func_001E6360(Comp_001EBC48* d, Comp_001EBC48* src);
extern "C" void func_001E6A00(Struct_001EBC48* d, Struct_001EBC48* src);
extern "C" void func_001E6A50(Struct_001EBC48* d, Struct_001EBC48* src);

static inline float ReadFloat_001EBC48(unsigned char* p)
{
    union {
        int i;
        float f;
    } u;
    u.i = func_001EC7A0(p);
    return u.f;
}

extern "C" unsigned char* func_001EBC48(Struct_001EBC48* s, int name, unsigned char* p, Struct_001EBC48* params)
{
    int flag = 0;
    Comp_001EBC48* c;
    Struct_001EBC48* st;
    int n;
    Comp_001EBC48* v;
    switch (*p++) {
    case 22: {
        int v = func_001EC7A0(p);
        p += 4;
        func_001E7360(s, name, v);
        return p;
    }
    case 23: {
        int v = func_001EC7A0(p);
        p += 4;
        func_001E7200(s, name, v);
        return p;
    }
    case 56:
        flag = 1;
    case 48:
        c = func_001E4ED8(func_001E8CD0(0x10));
        {
            unsigned char* r = func_001EB180(p, c, flag);
            c->m_name = name;
            p = r;
        }
        goto add_comp;
    case 26: {
        float f = ReadFloat_001EBC48(p);
        p += 4;
        func_001E72B0(s, name, f);
        return p;
    }
    case 30: {
        float x = ReadFloat_001EBC48(p);
        p += 4;
        float y = ReadFloat_001EBC48(p);
        p += 4;
        float z = ReadFloat_001EBC48(p);
        p += 4;
        if (name == (int)0x9D2D0915) {
            float ax = x;
            if (x < 0.0f) {
                ax = -x;
            }
            float ay = y;
            if (y < 0.0f) {
                ay = -y;
            }
            float az = z;
            if (z < 0.0f) {
                az = -z;
            }
            if (ax < 0.01f && ay < 0.01f && az < 0.01f) {
                return p;
            }
        }
        func_001E7410(s, name, x, y, z);
        return p;
    }
    case 31: {
        float x = ReadFloat_001EBC48(p);
        p += 4;
        float y = ReadFloat_001EBC48(p);
        p += 4;
        func_001E7558(s, name, x, y);
        return p;
    }
    case 27: {
        int n = func_001EC7A0(p);
        p += 4;
        func_001E70C0(s, name, p);
        p += n;
        break;
    }
    case 28: {
        int n = func_001EC7A0(p);
        p += 4;
        func_001E7180(s, name, p);
        p += n;
        break;
    }
    case 3:
        p--;
        st = func_001E6978(func_001190D0(8));
        p = func_001EC088(st, p, params);
        goto add_struct;
    case 5: {
        p--;
        func_0010A950(D_00388A70, D_00388A70->m_EC);
        void* a = func_001E8DD0(func_00122CF8(0x10));
        func_0010A9B0(D_00388A70);
        p = func_001EB450(a, p, params);
        func_001E7720(s, name, a);
        return p;
    }
    case 35: {
        p++;
        name = func_001EC7A0(p);
        p += 4;
        unsigned char* start = p;
        p = func_001ECD40(start);
        func_001E7958(s, name, start, p - start);
        return p;
    }
    case 45:
        p++;
        n = func_001EC7A0(p);
        p += 4;
        if (!params) {
            break;
        }
        v = func_001E6DD0(params, n);
        if (!v) {
            return p;
        }
        if (!name && v->m_type == 10) {
            func_001E6AC8(s, v->m_8);
            return p;
        }
        c = func_001E4ED8(func_001E8CD0(0x10));
        func_001E6360(c, v);
        c->m_name = name;
    add_comp:
        func_001E6F90(s, c);
        return p;
    case 44:
        if (!params) {
            return p;
        }
        if (name) {
            st = func_001E6978(func_001190D0(8));
            func_001E6A00(st, params);
        add_struct:
            func_001E78A8(s, name, st);
            return p;
        }
        func_001E6A50(s, params);
        return p;
    case 4:
    case 6:
    case 7:
    case 8:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 29:
    case 32:
    case 33:
    case 34:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 46:
    case 47:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    default:
        p--;
        break;
    case 9:
        break;
    }
    return p;
}
