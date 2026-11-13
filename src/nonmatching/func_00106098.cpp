/* fuzzy: 98.3 */
extern "C" void* func_003315B8(void* dst, int c, unsigned int n);   /* memset */
extern char D_002CE630[];
extern char D_10000[];   /* linker-defined size symbol (0x10000) */
extern int D_003886AC;
extern char D_0035AA60[];   /* "ROOT" */

struct Name5_00106098 {
    char c[5];
};

struct Desc_00106098 {
    char name[16];
    int m10;
    int m14;
    char* m18;
    int m1C;
    char* m20;
    int m24;
    int m28;
};

extern Desc_00106098 D_003953B8;

/* static initialisation: D_003953B8 = { "ROOT", 0, 0, D_002CE630, D_003886AC, D_10000 } */
extern "C" void func_00106098(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        Desc_00106098 d;
        Desc_00106098* root = &D_003953B8;
        func_003315B8(&d, 0, sizeof(d));
        *(Name5_00106098*)d.name = *(Name5_00106098*)D_0035AA60;
        func_003315B8(d.name + 5, 0, 11);
        int t = D_003886AC;
        d.m18 = D_002CE630;
        d.m1C = t;
        d.m20 = D_10000;
        *root = d;
    }
}
