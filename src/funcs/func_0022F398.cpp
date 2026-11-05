struct Game_0022F398 {
    char pad0[0x3AC];
    int m3AC;
};
extern Game_0022F398* D_0038FC78;
extern "C" void func_0022E430(Game_0022F398* g, int v);

bool Cmd_0022F398()
{
    func_0022E430(D_0038FC78, D_0038FC78->m3AC);
    return true;
}
