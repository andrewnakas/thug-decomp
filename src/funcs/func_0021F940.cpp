struct Game_0021F940 {
    char pad0[0x68];
    int m68;
};
extern Game_0021F940* D_0038FC78;

bool Cmd_0021F940()
{
    D_0038FC78->m68 = 1;
    return true;
}
