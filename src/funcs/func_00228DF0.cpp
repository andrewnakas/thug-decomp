extern char D_00372438[];
extern char D_00372450[];
extern char D_00372468[];
extern char D_00372480[];
extern char D_00372490[];
extern char D_003724A8[];

struct Heap_00228DF0 {
    char pad[0xD8];
    void* m_D8;
};

extern Heap_00228DF0* D_00388A70;

extern "C" void func_00229058();
extern "C" bool func_00229068();
extern "C" void func_00229088();
extern "C" void func_00229098();
extern "C" void func_002290A8();
extern "C" void func_002290B8();
extern "C" void func_002290C8();
extern "C" void func_0010A950(Heap_00228DF0* heap, void* a);
extern "C" void func_0010A9B0(Heap_00228DF0* heap);
extern "C" void func_0010BFC0(char* name);
extern "C" void func_0010BFC8();
extern "C" void func_001E5AB8(int n, char* name);
extern "C" void func_001E5B40(int n, char* name);
extern "C" void func_001E5BC8(int n, char* name);

bool func_00228DF0()
{
    func_00229058();
    if (func_00229068()) {
        func_002290A8();
        func_00229088();
        func_002290B8();
        func_00229098();
        func_002290C8();
        return true;
    }
    func_002290A8();
    func_0010A950(D_00388A70, D_00388A70->m_D8);
    func_0010BFC0(D_00372438);
    func_00229058();
    func_001E5AB8(50000, D_00372450);
    func_002290A8();
    func_0010BFC8();
    func_0010BFC0(D_00372468);
    func_00229088();
    func_001E5B40(50000, D_00372480);
    func_002290B8();
    func_0010BFC8();
    func_0010BFC0(D_00372490);
    func_00229098();
    func_001E5BC8(10000, D_003724A8);
    func_002290C8();
    func_0010BFC8();
    func_0010A9B0(D_00388A70);
    return true;
}
