typedef int qword __attribute__((mode(TI)));

struct Vec_00230430 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Obj_00230430 {
    char pad[0x470];
    int m_470;
    char pad474[0x480 - 0x474];
    Vec_00230430 m_480;
    void Update();
};

extern int D_0038A0E8;
extern "C" void* func_0013B0E8(int index);
extern "C" Vec_00230430* func_00114E18(void* a);

void Obj_00230430::Update()
{
    if (D_0038A0E8 >= 2 || !func_0013B0E8(0)) {
        m_470 = 1;
    } else {
        m_470 = 0;
        m_480 = *func_00114E18(func_0013B0E8(0));
    }
}
