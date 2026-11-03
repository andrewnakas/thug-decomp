extern unsigned long* D_003942AC;
extern int* D_00394274;
extern int D_00394280;
extern char D_00360860[];
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int code);

void AddEntry_00160F18(int index, unsigned int mode)
{
    unsigned long v = D_003942AC[index];
    *D_00394274 = (int)v;
    D_00394274[1] = (int)(v >> 32);
    D_00394274 += 2;
    switch (mode) {
    case 1:
        *D_00394274++ = (D_00394280 & 0xFFFF) | 0x3000000;
        *D_00394274++ = 0x2000000;
        D_00394280 += (int)((v >> 16) & 0x3FF);
        break;
    case 2:
        *D_00394274++ = 0;
        *D_00394274++ = 0;
        break;
    case 3:
        D_00394274 += 2;
        break;
    default:
        func_00103F28(D_00360860);
        func_00334148(1);
        break;
    }
}
