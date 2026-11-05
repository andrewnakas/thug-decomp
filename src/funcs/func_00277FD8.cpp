typedef int qword __attribute__((mode(TI)));
struct Vec_00277FD8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00277FD8 {
    Vec_00277FD8 r[4];
    const Vec_00277FD8& operator[](int i) const { return r[i]; }
    Mat_00277FD8& operator=(const Mat_00277FD8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Src_00277FD8 {
    char pad[0x20];
    Mat_00277FD8 m20;
};

struct Obj_00277FD8 {
    char pad[0x20];
    Mat_00277FD8 m20;
    char pad2[0x64 - 0x60];
    Src_00277FD8* m64;
    void Sync();
};

void Obj_00277FD8::Sync()
{
    m20 = m64->m20;
}
