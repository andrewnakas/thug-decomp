struct Game_0021F400 {
    char pad0[0x24];
    void* m24;
};
extern Game_0021F400* D_0038FC78;
extern "C" int func_00263790(void* p);

bool Call_0021F400()
{
    func_00263790(D_0038FC78->m24);
    return true;
}
