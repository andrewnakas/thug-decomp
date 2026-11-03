struct Hdr_00122D48 {
    int w[0x38 / 4];
};

extern Hdr_00122D48 D_003BE8E8;
extern Hdr_00122D48 D_0034D698;

void func_00122D48(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize)
        D_003BE8E8 = D_0034D698;
}
