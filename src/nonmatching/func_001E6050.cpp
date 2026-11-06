/* fuzzy: 86.2 */
struct Ent_001E6050 {
    unsigned int key;
    char* str;
};

extern int D_00388818;
extern Ent_001E6050* D_0038E580;
extern char* D_0038E584;
extern char* D_0038E588;
extern char** D_6E00080[];
extern Ent_001E6050 D_6E00100[];

extern "C" void func_001E6050()
{
    if (D_00388818) {
        D_6E00080[0] = &D_0038E584;
        D_6E00080[1] = &D_0038E588;
        D_0038E580 = D_6E00100;
        D_0038E584 = (char*)(D_0038E580 + 0xA0000);
        D_0038E588 = (char*)(D_0038E580 + 0xA0000);
        Ent_001E6050* e = D_0038E580;
        for (int i = 0xA0000; i != 0; i--) {
            e->key = 0;
            e->str = 0;
            e++;
        }
        *D_0038E584 = 0;
    }
}
