struct Game_00220100 {
    char pad0[0x398];
    void* m398;
};
extern Game_00220100* D_0038FC78;
extern "C" int func_002521F8(void* p);

bool Call_00220100()
{
    func_002521F8(D_0038FC78->m398);
    return true;
}
