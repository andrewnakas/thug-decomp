struct Game_00219050 {
    char pad0[0x3BC];
    void* m3BC;
};
extern Game_00219050* D_0038FC78;
extern "C" int func_0024FE88(void* p);

int Call_00219050()
{
    return func_0024FE88(D_0038FC78->m3BC);
}
