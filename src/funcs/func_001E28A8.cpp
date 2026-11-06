extern volatile int D_0038E298;
extern volatile int D_0038E29C;
extern "C" int func_00320438();
extern "C" int func_00320490();

extern "C" int func_001E28A8(int* out)
{
    func_00320438();
    *out = D_0038E298;
    int r = D_0038E29C;
    D_0038E298 = 0;
    D_0038E29C = 0;
    func_00320490();
    return r;
}
