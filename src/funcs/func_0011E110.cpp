typedef int qword __attribute__((mode(TI)));

struct Vec_0011E110 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Entry_0011E110 {
    int m_key;
    int m4;
    int m8;
    unsigned int m_flags;
    int m10[4];
    Vec_0011E110 m_scale;
};

class Table_0011E110;
extern "C" Entry_0011E110* func_0011D4F0(Table_0011E110* self, int key);

class Table_0011E110 {
public:
    bool SetScale(int key, Vec_0011E110* v, int flag);
};

bool Table_0011E110::SetScale(int key, Vec_0011E110* v, int flag)
{
    Entry_0011E110* e = func_0011D4F0(this, key);
    if (e) {
        e->m_scale = *v;
        int unit = v->x == 1.0f && v->y == 1.0f && v->z == 1.0f;
        e->m_flags &= ~0x30000000;
        if (!unit) {
            e->m_flags |= flag ? 0x20000000 : 0x10000000;
        }
    }
    return e != 0;
}
