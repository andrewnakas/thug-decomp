struct Sub_00219F18 {
    int m0;
    int m4;
    int m8;
};
struct Game_00219F18 {
    char pad0[0x2C];
    Sub_00219F18* m2C;
};
extern Game_00219F18* D_0038FC78;

int Get_00219F18()
{
    return D_0038FC78->m2C->m8;
}
