typedef int qword __attribute__((mode(TI)));

extern "C" void* memcpy(void* d, const void* s, unsigned int n);

struct Vec118DF0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec118DF0() {}
};

struct Quat118DF0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Quat118DF0() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
};

struct Header118DF0 {
    int m_id;
    int m_type;
    int m_size;
};

extern "C" void* func_001046B0(int size);
extern "C" void* func_001183B0(void* mem, int id, float f);
extern "C" void* func_00118490(void* mem, int id, int v);
extern "C" void* func_00118530(void* mem, int id, const Quat118DF0& rot, const Vec118DF0& pos, int t);
extern "C" void* func_00118B20(void* mem, int id);
extern "C" void* func_00118C90(void* mem, int id, int v);
extern "C" void* func_00118D38(void* mem, int id, int v);

void* func_00118DF0(char** pp)
{
    Header118DF0 h;
    memcpy(&h, *pp, 12);
    *pp += 12;
    switch (h.m_type) {
    case 1: {
        float f;
        memcpy(&f, *pp, 4);
        *pp += 4;
        return func_001183B0(func_001046B0(0x24), h.m_id, f);
    }
    case 4: {
        int v;
        memcpy(&v, *pp, 4);
        *pp += 4;
        return func_00118490(func_001046B0(0x24), h.m_id, v);
    }
    case 2: {
        Quat118DF0 rot;
        Vec118DF0 pos;
        memcpy(&pos, *pp, 16);
        *pp += 16;
        memcpy(&rot, *pp, 16);
        *pp += 16;
        return func_00118530(func_001046B0(0x50), h.m_id, rot, pos, 0);
    }
    case 7: {
        Quat118DF0 rot;
        Vec118DF0 pos;
        memcpy(&pos, *pp, 16);
        *pp += 16;
        memcpy(&rot, *pp, 16);
        *pp += 16;
        return func_00118530(func_001046B0(0x50), h.m_id, rot, pos, 1);
    }
    case 3:
        *pp += 0x20;
        return func_00118B20(func_001046B0(0x20), h.m_id);
    case 5: {
        int v;
        memcpy(&v, *pp, 4);
        *pp += 4;
        return func_00118C90(func_001046B0(0x24), h.m_id, v);
    }
    case 6: {
        int v;
        memcpy(&v, *pp, 4);
        *pp += 4;
        return func_00118D38(func_001046B0(0x24), h.m_id, v);
    }
    }
    *pp += h.m_size;
    return 0;
}
