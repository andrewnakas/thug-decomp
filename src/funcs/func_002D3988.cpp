extern "C" void func_002D09F0(void* p);

struct Inst_002D3988 {
    int m0;
    void* m4;
};

extern Inst_002D3988* D_00392068;

struct Obj_002D3988 {
    bool Run();
};

bool Obj_002D3988::Run() {
    func_002D09F0(D_00392068->m4);
    return true;
}
