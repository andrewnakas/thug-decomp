extern "C" float func_00119768(void* p);
extern "C" void func_00116170(void* p, int a, int b, int c, float f);

struct Obj_0025B730 {
    char pad[0x78];
    void* m78;
    char m7C[4];
    void Fn(int a, int b);
};

void Obj_0025B730::Fn(int a, int b)
{
    func_00116170(m78, a, b, 0, func_00119768(m7C));
}
