extern char D_003F58A8[];
extern char D_00371FB8[];
extern char D_00371FD0[];
extern char D_00371FE0[];
extern char D_0038F9E0[];
extern char D_00371FF0[];
extern char D_00372000[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

char* func_00225FE8(unsigned int type, char* name)
{
    switch (type) {
    case 0xCA41692D:
        func_003331D0(D_003F58A8, D_00371FB8, name);
        break;
    case 0xB010F357:
        func_003331D0(D_003F58A8, D_00371FD0, name);
        break;
    case 0x61A1BC57:
        func_003331D0(D_003F58A8, D_00371FE0, name);
        break;
    case 0x3BF882CC:
        func_003331D0(D_003F58A8, D_0038F9E0, name);
        break;
    case 0x26C80B0D:
        func_003331D0(D_003F58A8, D_00371FF0, name);
        break;
    case 0x62896EDF:
        func_003331D0(D_003F58A8, D_00372000, name);
        break;
    case 0xFFFFFFFF:
        break;
    }
    return D_003F58A8;
}
