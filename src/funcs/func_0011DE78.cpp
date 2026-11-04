struct Vec_0011DE78 {
    float x, y, z, w;
};

struct Arr_0011DE78 {
    char pad[0xC];
    unsigned int m_size;
};

struct Entry_0011DE78 {
    unsigned int m_id;
    char pad[0x2C];
};

extern char D_0035CA28[];
extern char D_0035CA38[];

extern "C" int func_001E7E58(void* params, const char* name, int* out, int req);
extern "C" int func_001E7FA8(void* params, unsigned int id, Vec_0011DE78* out, int req);
extern "C" Arr_0011DE78* func_001E55F8(const char* name, int flags);
extern "C" unsigned int func_001E9300(Arr_0011DE78* a, unsigned int i);

struct C_0011DE78 {
    unsigned int m_flags;
    char pad[0x10];
    int m_count;
    Entry_0011DE78* m_entries;
    int Apply(void* params);
};

extern "C" int func_0011E0D0(C_0011DE78* self, unsigned int id, Vec_0011DE78* out);
extern "C" void func_0011E110(C_0011DE78* self, unsigned int id, Vec_0011DE78* v, int flag);

int C_0011DE78::Apply(void* params)
{
    if (!params)
        return 0;
    int x = 0;
    func_001E7E58(params, D_0035CA28, &x, 0);
    int flag = x == 0;
    for (int i = 0; i < m_count; i++) {
        Vec_0011DE78 v;
        if (!func_001E7FA8(params, m_entries[i].m_id, &v, 0))
            continue;
        unsigned int id = m_entries[i].m_id;
        if (m_flags & 0x10000000) {
            if (id == 0x580C0963)
                id = 0xDFEE29AC;
        }
        Arr_0011DE78* arr = func_001E55F8(D_0035CA38, 0);
        if (arr) {
            for (unsigned int j = 0; j < arr->m_size; j++) {
                if (func_001E9300(arr, j) == id)
                    flag = 0;
            }
        }
        Vec_0011DE78 s;
        Vec_0011DE78* p = &s;
        p->x = 1.0f;
        p->y = 1.0f;
        p->z = 1.0f;
        p->w = 1.0f;
        if (func_0011E0D0(this, id, p)) {
            s.x *= v.x;
            s.y *= v.y;
            s.z *= v.z;
            s.w = 1.0f;
            func_0011E110(this, id, p, flag);
        }
    }
    return 1;
}
