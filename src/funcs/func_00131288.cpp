typedef int qword __attribute__((mode(TI)));

struct Vec_00131288 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00131288() {}
    Vec_00131288(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

extern "C" int func_001E8618(void* params, unsigned int name);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_00131288* out, int req);
extern "C" int func_001E8918(void* params, unsigned int name, float* out, int req);

bool func_00131288(Vec_00131288* out, void* params)
{
    if (func_001E8618(params, 0x13B9DA7B)) {
        float s;
        if (func_001E7EB0(params, 0x13B9DA7B, &s, 0)) {
            *out = Vec_00131288(s, s, s, 1.0f);
            return true;
        }
        if (func_001E7FA8(params, 0x13B9DA7B, out, 0))
            return true;
    }
    int a = func_001E8918(params, 0x7323E97C, &out->x, 0);
    int b = func_001E8918(params, 0x424D9EA, &out->y, 0);
    int c = func_001E8918(params, 0x9D2D8850, &out->z, 0);
    return a || b || c;
}
