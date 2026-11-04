struct Obj_00294EE8 {
    char pad0[0x114];
    unsigned int m114;
    char pad118[0x2AC - 0x118];
    int m2AC;
    char pad2B0[0x2C4 - 0x2B0];
    int m2C4;
};

extern "C" void func_00294EE8(Obj_00294EE8* o, int v)
{
    o->m2AC = v;
    switch (o->m114) {
    case 0x7FE2238A:
    case 0x0FC6F698:
    case 0xEA7BA666:
        if (o->m2C4 > o->m2AC)
            o->m2C4 = o->m2AC;
        break;
    }
}
