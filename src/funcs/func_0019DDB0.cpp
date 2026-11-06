struct Vec_0019DDB0 {
    float x, y, z, w;
};

struct Obj_0019DDB0 {
    void Fn(Vec_0019DDB0* v);
};

void Obj_0019DDB0::Fn(Vec_0019DDB0* v)
{
    v->x = 0.0f;
    if (v->z < -0.9599312f)
        v->z = -1.9198624f;
    else if (v->z > 0.9599312f)
        v->z = 1.9198624f;
    else
        v->z = 0.0f;
}
