struct Holder_002CAB28 {
    void* m0;
};

extern Holder_002CAB28* D_0039274C;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_002B74E8(void* p, int v);

bool func_002CAB28(void* params, void* script)
{
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    func_002B74E8(D_0039274C->m0, v);
    return true;
}
