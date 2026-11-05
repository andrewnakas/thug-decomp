struct Mgr_002BA990;
extern Mgr_002BA990* D_0039274C;
extern int D_00392750;
extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" Mgr_002BA990* func_002BC710(void* p);

Mgr_002BA990* func_002BA990(int create)
{
    if (!D_0039274C && create)
        D_0039274C = func_002BC710(func_0010A638(D_00388A70, 0x6B04, 1, 0));
    D_00392750++;
    return D_0039274C;
}
