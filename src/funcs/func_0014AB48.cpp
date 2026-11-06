extern "C" bool func_0014ABD0();
extern "C" bool func_0014AC98(int i);
extern "C" bool func_0014ACD0(int i);

extern "C" void func_0014AB48()
{
    func_0014ABD0();
    for (int i = 0; i < 2; i++) {
        func_0014AC98(i);
        func_0014ACD0(i);
    }
}
