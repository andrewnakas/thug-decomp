struct Slot_0021EB68 {
    int m0;
    int m4;
    int m8;
    int mC;
};
struct Mgr_0021EB68 {
    char pad[0x3C8];
    Slot_0021EB68 m3C8[1];
};
extern Mgr_0021EB68* D_0038FC78;
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);

int func_0021EB68(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0, &v, 0);
    return D_0038FC78->m3C8[v].m0;
}
