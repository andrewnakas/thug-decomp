extern int D_003942B0;
extern unsigned int* D_003942B8[2];

unsigned int* NextTag_00161168(unsigned int* tag, int follow)
{
    switch (tag[0] >> 28) {
    case 1:
        return (unsigned int*)((char*)tag + (*(unsigned short*)tag * 16 + 16));
    case 2:
        return (unsigned int*)tag[1];
    case 3:
        return tag + 4;
    case 5:
        if (follow) {
            D_003942B8[D_003942B0] = (unsigned int*)((char*)tag + (*(unsigned short*)tag * 16 + 16));
            D_003942B0++;
            return (unsigned int*)tag[1];
        }
        return (unsigned int*)((char*)tag + (*(unsigned short*)tag * 16 + 16));
    case 6:
        D_003942B0--;
        return D_003942B8[D_003942B0];
    case 4:
    case 7:
    default:
        return 0;
    }
}
