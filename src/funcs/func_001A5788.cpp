typedef int qword_001A5788 __attribute__((mode(TI)));

struct Vec_001A5788 {
    union {
        struct { float x, y, z, w; };
        qword_001A5788 q;
    };
};

extern "C" unsigned int func_0010FC30();
extern "C" float func_00341068(float a);

struct Model_001A5788 {
    char pad[0x50];
    Vec_001A5788 m50;
};

struct Obj_001A5788 {
    char pad[0xC];
    Model_001A5788* mC;
    char pad10[0x200 - 0x10];
    float m200;
    float m204;
    float m208;
    unsigned int m20C;
    void Method();
};

void Obj_001A5788::Method()
{
    float t = (float)(func_0010FC30() % m20C * 2);
    m204 = m208 * func_00341068(t * 3.1415927f / (float)(int)m20C);
    Vec_001A5788 pos = mC->m50;
    m200 = pos.y;
    pos.y += m204;
    mC->m50 = pos;
}
