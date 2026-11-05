struct Game_002201C8 {
    char pad0[0x398];
    void* m398;
};
extern Game_002201C8* D_0038FC78;
extern "C" int func_00252478(void* p);

bool Call_002201C8()
{
    func_00252478(D_0038FC78->m398);
    return true;
}
