struct V3_00189BF8 {
    int x, y, z;
};

extern "C" void func_00188DF0(void* q, int x, int y, int z, int a, int b, int kind);

struct Obj_00189BF8 {
    int m0[8];
    char m_20[4];
    void Push(V3_00189BF8* v, int a, int b);
};

void Obj_00189BF8::Push(V3_00189BF8* v, int a, int b)
{
    func_00188DF0(m_20, v->x, v->z, v->y, b, a, 2);
}
