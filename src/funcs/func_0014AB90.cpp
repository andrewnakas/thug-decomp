extern "C" bool func_0014ABD0();   // returns 1: addiu v0,zero,1 at 0x0014AC0C
extern "C" void func_0014ACD0(int i);

void Init_0014AB90()
{
    func_0014ABD0();
    for (int i = 0; i < 2; i++)
        func_0014ACD0(i);
}
