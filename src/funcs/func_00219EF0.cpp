struct Game_00219EF0 {
    char pad0[0x28];
    void* m28;
};
extern Game_00219EF0* D_0038FC78;
extern "C" int func_0026B340(void* p, void* a);

bool Call_00219EF0(void* a)
{
    func_0026B340(D_0038FC78->m28, a);
    return true;
}
