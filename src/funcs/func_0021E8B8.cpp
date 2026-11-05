struct Game_0021E8B8 {
    char pad0[0x39C];
    void* m39C;
};
extern Game_0021E8B8* D_0038FC78;
extern "C" int func_0025FE28(void* p);

int Call_0021E8B8()
{
    return func_0025FE28(D_0038FC78->m39C);
}
