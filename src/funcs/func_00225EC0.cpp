extern char D_00371F40[];
extern char D_00371F58[];
extern char D_00371F68[];
extern char D_00371F78[];
extern char D_00371F88[];
extern char D_00371FA0[];
extern "C" int func_001E5648(char* name, int a);

int func_00225EC0(unsigned int type)
{
    switch (type) {
    case 0xB010F357:
        return func_001E5648(D_00371F40, 1);
    case 0x61A1BC57:
        return func_001E5648(D_00371F58, 1);
    case 0x3BF882CC:
        return func_001E5648(D_00371F68, 1);
    case 0x26C80B0D:
        return func_001E5648(D_00371F78, 1);
    case 0xCA41692D:
        return func_001E5648(D_00371F88, 1);
    case 0x62896EDF:
        return func_001E5648(D_00371FA0, 1);
    case 0xFFFFFFFF:
        break;
    }
    return -1;
}
