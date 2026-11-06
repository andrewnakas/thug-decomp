typedef int qword __attribute__((mode(TI)));

struct Vec_0011E1C8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Src_0011E1C8 {
    int m0;
    int m4;
    void* m_skel;
};

class Table_0011E1C8;
extern "C" void* func_0011D4F0(Table_0011E1C8* self, int key);
extern "C" int func_0011F4A8(void* sk);
extern "C" int func_0011F4B0(void* sk, int i);
extern "C" int func_0011E0D0(Src_0011E1C8* src, int key, Vec_0011E1C8* out);
extern "C" bool func_0011E110(Table_0011E1C8* self, int key, Vec_0011E1C8* v, int flag);

class Table_0011E1C8 {
public:
    void CopyScales(Src_0011E1C8* src);
};

void Table_0011E1C8::CopyScales(Src_0011E1C8* src)
{
    void* sk = src->m_skel;
    for (int i = 0; i < func_0011F4A8(sk); i++) {
        int key = func_0011F4B0(sk, i);
        if (func_0011D4F0(this, key)) {
            Vec_0011E1C8 v;
            if (func_0011E0D0(src, key, &v)) {
                func_0011E110(this, key, &v, 1);
            }
        }
    }
}
