typedef int qword_00229FF8 __attribute__((mode(TI)));

struct Vec_00229FF8 {
    union {
        struct { float x, y, z, w; };
        qword_00229FF8 q;
    };
};

extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_00229FF8* out, int assert);

extern "C" void func_00229FF8(void* params, Vec_00229FF8* out)
{
    if (func_001E7FA8(params, 0x7F261953, out, 0))
        return;
    if (func_001E7FA8(params, 0xB9D31B0A, out, 0)) {
        out->z = -out->z;
    } else {
        Vec_00229FF8 t;
        t.x = 0.0f;
        t.y = 0.0f;
        t.z = 0.0f;
        t.w = 1.0f;
        *out = t;
    }
}
