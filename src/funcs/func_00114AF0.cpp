extern "C" float func_0013B490(void* self);

struct Obj_00114AF0 {
    int m0[3];
    float m_C;
    float m_10;
    float Get();
};

float Obj_00114AF0::Get()
{
    return func_0013B490(this) * m_C / m_10;
}
