extern unsigned int* D_00393F28;
extern unsigned int* D_00393F2C;

void SetAlpha_001465C8(unsigned int a)
{
    unsigned int al = (255 - a) >> 1;
    unsigned int v = (*D_00393F28 & 0xFFFFFF00) | al;
    *D_00393F28 = v;
    *D_00393F2C = v;
}
