extern "C" int func_001E53A0(unsigned int name, int def);
extern "C" int func_00225E68(int x);

int Get_002277F0(unsigned int key)
{
    int v = 0;
    switch (key) {
    case 0xB010F357:
        v = func_001E53A0(0xE7F51FFE, 1);
        break;
    case 0x61A1BC57:
        v = func_001E53A0(0x9EECDEC9, 1);
        break;
    case 0x62896EDF:
        v = func_001E53A0(0x3308EFC0, 1);
        break;
    case 0x3BF882CC:
        v = func_001E53A0(0x2CB071ED, 1);
        break;
    case 0x26C80B0D:
        v = func_001E53A0(0x8EE3AA00, 1);
        break;
    case 0xCA41692D:
        v = func_001E53A0(0x651C978D, 1);
        break;
    case 0xFFC529F4:
        break;
    }
    return func_00225E68(v + 20);
}
