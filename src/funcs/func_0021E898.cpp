struct Game_0021E898 {
    char pad0[0x39C];
    void* m39C;
};
extern Game_0021E898* D_0038FC78;
extern "C" int func_0025FDE8(void* p);

int Call_0021E898()
{
    return func_0025FDE8(D_0038FC78->m39C);
}
