struct Ent_001E1450 {
    char pad[0x1010];
};
extern Ent_001E1450 D_003ED8D0[];
extern "C" void func_001E1218(Ent_001E1450* e);

void func_001E1450(int on, int id)
{
    if (id == 0xFFFF && on) {
        Ent_001E1450* e = D_003ED8D0;
        int n = 1;
        while (n--) {
            func_001E1218(e);
            e++;
        }
    }
}
