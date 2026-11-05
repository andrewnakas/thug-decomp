typedef int qword __attribute__((mode(TI)));

struct Vec_00114DD8 {
    qword q;
};

extern "C" Vec_00114DD8* func_00114E18(void* self);

struct Obj_00114DD8 {
    char pad[0x50];
    Vec_00114DD8 m_50;
    void Update();
};

void Obj_00114DD8::Update()
{
    m_50 = *func_00114E18(this);
}
