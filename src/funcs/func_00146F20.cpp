extern int D_0038A8C0;
extern unsigned char D_004653E8[256];
extern unsigned char D_004654E8[256];

void InitClutTables_00146F20()
{
    if (!D_0038A8C0) {
        unsigned int i;
        unsigned int j;
        int n = 0;
        for (i = 0; i < 256; i += 32) {
            for (j = i; j < i + 8; j++) {
                D_004653E8[j] = n++;
            }
            for (j = i + 16; j < i + 24; j++) {
                D_004653E8[j] = n++;
            }
            for (j = i + 8; j < i + 16; j++) {
                D_004653E8[j] = n++;
            }
            for (j = i + 24; j < i + 32; j++) {
                D_004653E8[j] = n++;
            }
        }
        n = 0;
        for (i = 0; i < 256; i += 32) {
            for (j = i; j < i + 8; j++) {
                D_004654E8[n++] = j;
            }
            for (j = i + 16; j < i + 24; j++) {
                D_004654E8[n++] = j;
            }
            for (j = i + 8; j < i + 16; j++) {
                D_004654E8[n++] = j;
            }
            for (j = i + 24; j < i + 32; j++) {
                D_004654E8[n++] = j;
            }
        }
        D_0038A8C0 = 1;
    }
}
