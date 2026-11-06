extern "C" void* func_001046B0(int size);
extern "C" void func_0026B770();

struct List_0026B728 {
    int m0;
    void* m4;
    int m8;
    int mC;
};

struct Game_0026B728 {
    char pad[0x2C];
    List_0026B728* m2C;
};

extern Game_0026B728* D_0038FC78;

void Reset_0026B728()
{
    Game_0026B728* g = D_0038FC78;
    if (g->m2C)
        func_0026B770();
    List_0026B728* l = (List_0026B728*)func_001046B0(0x10);
    l->mC = 0;
    g->m2C = l;
    l->m4 = 0;
}
