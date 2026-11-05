struct Game_00220130 {
    char pad0[0x398];
    void* m398;
};
extern Game_00220130* D_0038FC78;
extern "C" int func_00252528(void* p);

int Call_00220130()
{
    return func_00252528(D_0038FC78->m398);
}
