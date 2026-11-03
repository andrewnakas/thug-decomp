typedef int qword_002C02B0 __attribute__((mode(TI)));
struct Vec_002C02B0 {
    union {
        qword_002C02B0 q;
        struct { float x, y, z, w; } f;
    };
};

struct Box_002C02B0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

extern float D_00392610;
extern float D_00392614;
extern float D_00392618;

struct Obj_002C02B0 {
    Vec_002C02B0 GetPos(Box_002C02B0* b, float* size);
};

Vec_002C02B0 Obj_002C02B0::GetPos(Box_002C02B0* b, float* size)
{
    float sx = D_00392610;
    float sy = D_00392614;
    float sz = D_00392618;
    Vec_002C02B0 v;
    v.f.x = (float)(b->x - 29) * sx;
    v.f.y = (float)b->y * sy;
    v.f.z = (float)(b->z - 29) * sz;
    v.f.w = 1.0f;
    if (size) {
        size[0] = (float)b->w * sx;
        size[1] = (float)b->h * sy;
        size[2] = (float)b->d * sz;
    }
    return v;
}
