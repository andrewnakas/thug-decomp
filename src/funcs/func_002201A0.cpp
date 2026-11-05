struct Game_002201A0 {
    char pad0[0x398];
    void* m398;
};
extern Game_002201A0* D_0038FC78;
extern "C" int func_00252288(void* p);

bool Call_002201A0()
{
    func_00252288(D_0038FC78->m398);
    return true;
}
