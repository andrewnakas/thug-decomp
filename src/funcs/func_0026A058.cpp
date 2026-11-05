extern "C" float fabsf(float);

struct Pos_0026A058 {
    char pad[0x30];
    float x;
    float y;
    float z;
};

struct Obj_0026A058 {
    int m0;
    bool Near(Pos_0026A058* a, Pos_0026A058* b);
};

bool Obj_0026A058::Near(Pos_0026A058* a, Pos_0026A058* b)
{
    if (fabsf(a->x - b->x) > 1.0f)
        return false;
    if (fabsf(a->y - b->y) > 1.0f)
        return false;
    if (fabsf(a->z - b->z) > 1.0f)
        return false;
    return true;
}
