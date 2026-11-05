extern "C" unsigned int func_0010FC30();

struct Obj_002B3038 {
    char pad0[0x15C];
    unsigned int m15C;
    bool Expired();
};

bool Obj_002B3038::Expired()
{
    return func_0010FC30() - m15C > 5000;
}
