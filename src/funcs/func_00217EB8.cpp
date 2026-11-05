struct Game_00217EB8 {
    char pad0[0x468];
    bool m468;
};
extern Game_00217EB8* D_0038FC78;

bool Toggle_00217EB8()
{
    D_0038FC78->m468 = !D_0038FC78->m468;
    return true;
}
