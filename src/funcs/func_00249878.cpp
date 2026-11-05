struct Obj_00249878;
extern char D_003900B8[];
extern "C" void func_00249998(Obj_00249878* self, char* s, int a, int b, int c);

struct Obj_00249878 {
    int m0;
    int m4;
    void Fn();
};

void Obj_00249878::Fn()
{
    if (!m4) func_00249998(this, D_003900B8, 10, 1, 1);
}
