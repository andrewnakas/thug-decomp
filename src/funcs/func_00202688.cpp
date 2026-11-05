struct Obj_00202688 {
    char pad[0x74];
    unsigned int m74;
    void Extend(unsigned int ms);
};

extern "C" unsigned int func_0010FC30();

void Obj_00202688::Extend(unsigned int ms)
{
    unsigned int t = func_0010FC30() + ms;
    if (m74 < t)
        m74 = t;
}
