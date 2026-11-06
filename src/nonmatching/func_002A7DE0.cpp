/* fuzzy: 56.2 */
extern void* D_0038FC78;

extern "C" void* func_0022E358(void* g);
extern "C" int func_0024F328(void* p);
extern "C" int func_0024F360(void* p);
extern "C" unsigned int func_0024F938(void* p);
extern "C" int func_0024F050(void* p);

extern "C" int func_002A7DE0()
{
    void* p = func_0022E358(D_0038FC78);
    if (func_0024F328(p)) return 1;
    if (func_0024F360(p)) return 1;
    if (func_0024F938(p) == 0xBFF33600) return 1;
    if (func_0024F938(p) == 0xEC200EAA) return 1;
    if (func_0024F938(p) != 0x6C5FF266) return 0;
    if (!func_0024F050(p)) return 1;
    if (func_0024F938(p) != 0xBFF33600) return 0;
    return 1;
}
