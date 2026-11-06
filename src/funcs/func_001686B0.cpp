extern bool D_00394308[2];
extern "C" int func_00320438();
extern "C" int func_00320490();

bool func_001686B0(int i)
{
    func_00320438();
    bool old = D_00394308[i];
    D_00394308[i] = true;
    func_00320490();
    return !old;
}
