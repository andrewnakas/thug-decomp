struct Game_00220178 {
    char pad0[0x398];
    void* m398;
};
extern Game_00220178* D_0038FC78;
extern "C" int func_00252278(void* p);

bool Call_00220178()
{
    func_00252278(D_0038FC78->m398);
    return true;
}
