struct Vec_0019DCE8 {
    float x, y, z, w;
};

struct Obj_0019DCE8 {
    void Fn(Vec_0019DCE8* v);
};

void Obj_0019DCE8::Fn(Vec_0019DCE8* v)
{
    if (v->x > 1.5707965f || v->x < -1.5707965f)
        v->x = 3.141593f;
    else
        v->x = 0.0f;
    if (v->z > 1.5707965f || v->z < -1.5707965f)
        v->z = 3.141593f;
    else
        v->z = 0.0f;
}
