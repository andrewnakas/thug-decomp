/* sym: _vt$14Piece_002BAB20 = 0x0037A740 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Piece_002BAB20 {
    char pad0[0x28];
    void* m28;
    int m2C;
    int m30;
    int m34;
    virtual void V1();
    virtual ~Piece_002BAB20();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Piece_002BAB20::~Piece_002BAB20()
{
    if (m28)
        func_0010A8D8(D_00388A70, m28);
}
