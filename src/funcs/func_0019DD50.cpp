struct Vec_0019DD50 {
    float x, y, z, w;
};

extern "C" float func_0019DC90(float a, float step);

struct Obj_0019DD50 {
    void Fn(Vec_0019DD50* v);
};

void Obj_0019DD50::Fn(Vec_0019DD50* v)
{
    float step = 1.5707965f;
    v->x = func_0019DC90(v->x, step);
    v->y = func_0019DC90(v->y, step);
    v->z = func_0019DC90(v->z, step);
}
