struct Mgr_0021F958 {
    char pad[0x68];
    int m68;
};
extern Mgr_0021F958* D_0038FC78;
extern "C" void* func_0022E358(Mgr_0021F958* m);
extern "C" int func_0024F050(void* p);

bool func_0021F958()
{
    bool r = false;
    if (D_0038FC78->m68 || func_0024F050(func_0022E358(D_0038FC78)))
        r = true;
    return r;
}
