struct Vec_00101730 {
    float x, y, z, w;
};

extern "C" float sqrtf(float);
extern "C" Vec_00101730* func_001016A8(Vec_00101730* v, const Vec_00101730* n);
extern "C" void func_003233B8(Vec_00101730* dst, Vec_00101730* src);

extern "C" Vec_00101730* func_00101730(Vec_00101730* v, const Vec_00101730* n)
{
    float len = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
    func_001016A8(v, n);
    if (sqrtf(v->x * v->x + v->y * v->y + v->z * v->z) == 0.0f) {
        v->x = -n->z;
        v->y = n->x;
        v->z = -n->y;
    }
    func_003233B8(v, v);
    v->x *= len;
    v->y *= len;
    v->z *= len;
    v->w = 0.0f;
    return v;
}
