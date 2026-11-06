struct Obj_00249960;
extern char D_003900C0[];
extern "C" void func_00249998(Obj_00249960* self, char* s, int a, int b, int c);

struct Obj_00249960 {
    int m0;
    int m4;
    void Fn();
};

void Obj_00249960::Fn()
{
    if (!m4) func_00249998(this, D_003900C0, 10, 0, 1);
}
