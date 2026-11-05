extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);

struct Obj_002947D0 {
    char pad[0x114];
    unsigned int m114;
    char pad118[0x1B8];
    int m2D0;
    void Event(void* params);
};

void Obj_002947D0::Event(void* params)
{
    unsigned int type = 0;
    func_001E8398(params, 0, &type, 0);
    if (m114 == 0x0FC6F698 && type == 0xDF47B144)
        m2D0 = 0;
}
