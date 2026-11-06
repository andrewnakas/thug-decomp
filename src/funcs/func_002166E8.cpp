extern void* D_0038FC78;
extern char D_0038F618[];
extern char D_0038F620[];

extern "C" void* func_0022E358(void* game);
extern "C" unsigned int func_0024F938(void* p);
extern "C" unsigned int func_001F0D78(const char* s);

extern "C" bool func_002166E8()
{
    void* g = D_0038FC78;
    if (func_0024F938(func_0022E358(g)) == func_001F0D78(D_0038F618)
        || func_0024F938(func_0022E358(g)) == func_001F0D78(D_0038F620))
        return true;
    return false;
}
