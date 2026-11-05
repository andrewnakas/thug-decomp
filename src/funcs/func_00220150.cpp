struct Game_00220150 {
    char pad0[0x398];
    void* m398;
};
extern Game_00220150* D_0038FC78;
extern "C" int func_002524A8(void* p, void* a);

int Call_00220150(void* a)
{
    return func_002524A8(D_0038FC78->m398, a);
}
