extern int D_00388CA0;
extern int D_00388C94;
extern "C" int func_00320438();
extern "C" void func_00320490();

void Toggle_001124B8()
{
    func_00320438();
    int t = D_00388CA0;
    D_00388C94 = 0;
    D_00388CA0 = t ^ 1;
    func_00320490();
}
