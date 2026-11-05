struct Obj_002026D0 {
    char pad[0x74];
    unsigned int m74;
    unsigned int Elapsed();
};
extern "C" unsigned int func_0010FC30();

unsigned int Obj_002026D0::Elapsed()
{
    unsigned int t = func_0010FC30();
    if (t < m74)
        return 0;
    return t - m74;
}
