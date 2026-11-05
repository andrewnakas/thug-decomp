struct Obj_0024A650;
extern "C" void func_0024A880(Obj_0024A650* o, int k);

struct Obj_0024A650 {
    char pad0[0xA4];
    int mA4;
    bool Stop();
};

bool Obj_0024A650::Stop()
{
    if (mA4) func_0024A880(this, 0);
    return true;
}
