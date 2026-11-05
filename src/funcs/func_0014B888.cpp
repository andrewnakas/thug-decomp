typedef int qword __attribute__((mode(TI)));

struct Vec_0014B888 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
};

struct Mat_0014B888 {
    Vec_0014B888 row[4];
};

struct Model_0014B888;

extern "C" Mat_0014B888* func_00114E48(Model_0014B888* m);
extern "C" Vec_0014B888* func_00114E18(Model_0014B888* m);
extern "C" float func_00114DB0(Model_0014B888* m);

struct Obj_0014B888 {
    char pad[0x18];
    Model_0014B888* m18;
    void Draw();
};

extern "C" void* func_0013AFA8(Obj_0014B888* self);
extern "C" int func_0017D438(void* r);
extern "C" float func_00114AF0(Obj_0014B888* self);
extern "C" void func_0017BAA0(void* r, Mat_0014B888* m, Obj_0014B888* o, float a, float b, float c, float d);

void Obj_0014B888::Draw()
{
    void* r = func_0013AFA8(this);
    if (func_0017D438(r)) return;
    if (!m18) return;
    Mat_0014B888 m = *func_00114E48(m18);
    m.row[3] = *func_00114E18(m18);
    float s = func_00114DB0(m18);
    func_0017BAA0(r, &m, this, s, func_00114AF0(this), -1.0f, -100000.0f);
}
