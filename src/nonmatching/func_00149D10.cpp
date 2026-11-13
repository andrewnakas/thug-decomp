/* fuzzy: 75.0 */
extern "C" void* func_00180388(const char* name, int a, int b, int c, int d, void* out);
extern "C" void* func_00180430(int a, int b, int c, int d, int e);
extern "C" void func_00149BD0(void* self);

struct Tree_00149D10 {
    char pad[0xC];
    int mC;
    int m10;
    void* m14;
    int Init(const char* name, int a, int b, int flag, int c, int d, int e);
};

int Tree_00149D10::Init(const char* name, int a, int b, int flag, int c, int d, int e)
{
    int x, y, z;
    if (flag || (!d && !c)) {
        x = 0;
        y = 0;
        z = 1;
    } else {
        x = 1;
        y = 1;
        z = 0;
    }
    if (!flag && d) e = 1;
    if (name) {
        m14 = func_00180388(name, x, y, z, c, &mC);
    } else {
        mC = b;
        m14 = func_00180430(a, b, x, y, z);
    }
    if (e) func_00149BD0(this);
    return 0;
}
