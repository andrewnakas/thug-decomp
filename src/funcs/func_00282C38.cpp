extern "C" float sqrtf(float);

struct Obj_00282C38 {
    float TimeTo(float from, float to, float v);
};

extern "C" float func_00282B58(Obj_00282C38* self);

float Obj_00282C38::TimeTo(float from, float to, float v)
{
    float d = to - from;
    float g = -func_00282B58(this);
    return (v + sqrtf(v * v + 2.0f * g * d)) / g;
}
